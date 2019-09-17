#ifndef ENCODE_H
#define ENCODE_H

#include <iostream>
#include <vector>

using namespace std;

#define DATA_BLOCK_SIZE 64 

class Encode {


	private:
		int charCount;
		std::vector< std::vector<char> > dataBlock = std::vector< std::vector<char> >(DATA_BLOCK_SIZE, std::vector<char>(DATA_BLOCK_SIZE));


	public:
		Encode() {
			charCount = 0;
		}

		/*
		Encode(int n) {
			//dataBlock;
			charCount = n;
		}
		*/

		void set(std::vector< std::vector<char> > inputVector);
		std::string get();
		void shift();
		void sort();
		void printData();

};

#endif