#ifndef ENCODE_H
#define ENCODE_H

#include <iostream>
#include <vector>

//#define DATA_BLOCK_SIZE 32768

class Encode {


	//std::vector< std::vector<char> > dataBlock(32768, std::vector<char>(32768));

	private:
		int charCount;


	public:
		Encode() {
			//dataBlock;
			charCount = 0;
		}

		Encode(int n) {
			//dataBlock;
			charCount = n;
		}

		void set(std::string inpLine);
		std::string get();
		void shift();
		void sort();

};

#endif