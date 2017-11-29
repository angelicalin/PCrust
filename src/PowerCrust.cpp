#include"PowerCrust.h"

PowerCrust::PowerCrust() {


}
typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_3<K> Delaunay;
typedef Delaunay::Point Point;
CGAL::Point_set_3<K::Point_3> input_point_set;
std::list<Point> L;

void PowerCrust::run(){
	//	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("Point Cloud Viewer"));
	//	viewer->setCameraPosition(0.0, 0.0, -2.5, 0.0, 0.0, 0.0);
	//// Load input file into a PointCloud<T> with an appropriate type
		
	// construction from a list of points :
	
	//loadMesh();
	L.push_front(Point(0, 0, 0));
	L.push_front(Point(1, 0, 0));
	L.push_front(Point(0, 1, 0));
	Delaunay T(L.begin(), L.end());
	Delaunay::size_type n = T.number_of_vertices();
	// insertion from a vector :
	std::vector<Point> V(3);
	V[0] = Point(0, 0, 1);
	V[1] = Point(1, 1, 1);
	V[2] = Point(2, 2, 2);
	n = n + T.insert(V.begin(), V.end());
	assert(n == 6);       // 6 points have been inserted
	assert(T.is_valid()); // checking validity of T
	Delaunay::Locate_type lt;
	//int li, lj;
	//Point p(0, 0, 0);
	//Delaunay::Cell_handle c = T.locate(p, lt, li, lj);
	// p is the vertex of c of index li :
	//assert(lt == Delaunay::VERTEX);
	//assert(c->vertex(li)->point() == p);
	//Delaunay::Vertex_handle v = c->vertex((li + 1) & 3);
	// v is another vertex of c
	//Delaunay::Cell_handle nc = c->neighbor(li);
	// nc = neighbor of c opposite to the vertex associated with p
	// nc must have vertex v :
	//int nli;
	//assert(nc->has_vertex(v, nli));
	// nli is the index of v in nc
	std::cout<<  T.number_of_vertices()<<std::endl;
	std::ofstream oFileT("output", std::ios::out);
	// writing file output;
	oFileT << T;
	Delaunay T1;
	std::ifstream iFileT("output", std::ios::in);
	// reading file output;
	iFileT >> T1;
	assert(T1.is_valid());
	assert(T1.number_of_vertices() == T.number_of_vertices());
	assert(T1.number_of_cells() == T.number_of_cells());
}

void PowerCrust::loadMesh() {
	std::ifstream f("bunny.ply");

	if (!f || !CGAL::read_ply_point_set(f, input_point_set)) {
		std::cerr << "Can't read the input file" << std::endl;
	}
	for (CGAL::Point_set_3<Point>::const_iterator it = input_point_set.begin(); it != input_point_set.end(); ++it) {
		L.push_front(Point(&(input_point_set.point(*it).x), input_point_set.point(*it).y, input_point_set.point(*it).z));
	}

}