#include<stdio.h>

#include"PowerCrust.h"

int main(int argc, char** argv) {
	PowerCrust *con = new PowerCrust();
	
	
	con->run();
	delete con;

	return 0;
}