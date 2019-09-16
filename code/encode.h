#ifndef ENCODE_H
#define ENCODE_H

#include <vector>
#

#define DATA_BLOCK_SIZE 32768

class Encode {

	private:
		int charCount;
		std::vector<std::vector<char>> dataBlock(DATA_BLOCK_SIZE, std::vector<char>(DATA_BLOCK_SIZE, 0));


	public:
		Encode() {
			dataBlock;
			charCount = 0;
		}

		Encode(int n) {
			dataBlock;
			charCount = n;
		}

		void set(std::string inpLine);
		std::string get();
		void shift();
		void sort();

};

#endif