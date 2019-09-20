#ifndef ENCODE_H
#define ENCODE_H

#include <iostream>
#include <vector>


class Encode {


	private:
		int charCount;
		std::vector< std::vector<char> > dataBlock;


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