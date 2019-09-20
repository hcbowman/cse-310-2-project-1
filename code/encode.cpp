#include <iostream>
#include "encode.h"


void Encode::set(std::vector< std::vector<char> > inputVector)
{

	dataBlock = inputVector;
}

std::string Encode::get()
{
	std::string s;

	return s;
}

void Encode::shift() {
	std::cout << "shift" << "\n";
}

void Encode::sort() {
	std::cout << "sort" << "\n";
}

void Encode::printData() {
	
	for (size_t i = 0; i < dataBlock.size(); i++) {
		for (size_t j = 0; j < dataBlock[i].size(); j++) {
			std::cout << "j:" << j << dataBlock[i][j] << ' ';
		}
		std::cout << "i:" << i << '\n';
	}
}
