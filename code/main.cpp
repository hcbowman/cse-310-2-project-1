#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

//DEBUG
//#include <sstream>

#include"encode.h"


#define DATA_BLOCK_SIZE 64 




int main(int argc, char* argv[]) {

	//Variables
	std::string lineInput;
	int n = 0;

	//Objects
	Encode myEncodeObj;

	std::vector<char> tempVector; // = std::vector<char>(DATA_BLOCK_SIZE);
	std::vector< std::vector<char> > auxDataBlock; //= std::vector< std::vector<char> >(DATA_BLOCK_SIZE, std::vector<char>(DATA_BLOCK_SIZE));

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

	std::cout << "\n" << "##stdin##" << "\n";

	//Read from stdin and add it to a vector
	while (std::getline(std::cin, lineInput)) {
		//std::cout << lineInput << "\n";

		
		for (char ch : lineInput) {
			tempVector.push_back(ch);
			std::cout << ch << "\n";
		}
	}

	std::cout << "\n" << "##tempVector##" << "\n";

	//print tempVector
	for (auto const& i : tempVector) {
		std::cout << i << "";
		n++;
	}

	std::cout << "\n" << "##shift##" << "\n";

	//Shift the tempVector
	for (int i = 0; i < n - 1; i++) {

		int temp = tempVector.at(0);
		for (size_t j = 0; j < tempVector.size() - 1; j++)
		{
			tempVector.at(j) = tempVector.at(j + 1);
		}
		tempVector.at(tempVector.size() - 1) = temp;

		auxDataBlock[i] = tempVector;
	}

	//Print auxDataBlock
	for (size_t i = 0; i < auxDataBlock.size(); i++) {
		for (size_t j = 0; j < auxDataBlock[i].size(); j++) {
			std::cout << "j:" << j << auxDataBlock[i][j] << ' ';
		}
		std::cout << "i:" << i << '\n';
	}

	//DEBUG: Test Encode class
	//myEncodeObj.set(auxDataBlock);
	//myEncodeObj.printData();
	


	std::cout << "\n" << "End" << "\n";

	return 0;
}