#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

//DEBUG
//#include <sstream>

#include"encode.h"



int main(int argc, char* argv[]) {

	//Variables
	std::string lineInput;


	std::vector< std::vector<char> > dataBlock(32768, std::vector<char>(32768));

	//DEBUG variables
	//int x = 0;
	//std::stringstream geek();


	std::ios::sync_with_stdio(false);





	std::cout << "project 1 start" << "\n" << "\n";

	//Read command line arguments
	std::cout << "argc: " << argc << "\n";
	for (int i = 0; i < argc; i++) {
		std::cout << "argv["<< i << "] " << argv[i] << "\n";
	}



	//Read from stdin
	while (std::getline(std::cin, lineInput)) {
			std::cout << lineInput << "\n";

			//DEBUG
			//geek << lineInput;
			//geek >> x;
			//std::cout << "ints " << x << "\n";
	}

	//Test Encode class
	Encode myEncodeObj;
	
	myEncodeObj.sort();
	


	std::cout << "\n" << "End" << "\n";

	return 0;
}