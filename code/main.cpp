#include <iostream>
#include <string>

#include"encode.h"



int main(int argc, char* argv[]) {

	std::cout << "project 1" << "\n" << "\n";


	std::cout << "argc: " << argc << "\n";

	for (int i = 0; i < argc; i++) {
		std::cout << "argv["<< i << "] " << argv[i] << "\n";
	}


	Encode myEncodeObj;
	
	myEncodeObj.sort();
	
	std::cout << "End" << "\n";

	return 0;
}