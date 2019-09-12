#ifndef ENCODE_H
#define ENCODE_H

#include <vector>

class Encode {

	private:
		int charCount;

	public:
		Encode() {
			std::vector<std::vector<char>> v();
			charCount = 0;
		}

		Encode(int n) {
			std::vector<std::vector<char>> v(n);
			charCount = n;
		}


		void shift();
		void sort();

};

#endif