#ifndef PowerCrust_h
#define PowerCrust_h

#include <glad/glad.h>

#include<iostream>
#include <fstream>
#include<unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <memory>
#include<cassert>
#include <CGAL/Regular_triangulation_3.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_3.h>

#include <CGAL/Delaunay_triangulation_2.h>

#include <CGAL/Point_set_3.h>
#include <CGAL/Point_set_3/IO.h>

class PowerCrust {
public:
	PowerCrust();

	void run();

	// Callbacks for user input

protected:

	int _windowWidth;  //This is based on the framebuffer size, not the windowWidth passed to the constructor
	int _windowHeight; //This is based on the framebuffer size, not the windowWidth passed to the constructor
	int _windowXPos;
	int _windowYPos;

	void PowerCrust::loadMesh();
	


};
#endif