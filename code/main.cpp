#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

void sortFunct(std::vector< std::vector<char> >& bar);
void mergeSort(std::vector< std::vector<char> >& left, std::vector< std::vector<char> >& right, std::vector< std::vector<char> >& bars);

#include"encode.h"


//#define DATA_BLOCK_SIZE 64


int main(int argc, char* argv[]) {

	std::cout << "project 1 start" << "\n" << "\n";

	//Variables
	char c; //char input from text file
	int n = 0; //char count, including spaces


	//Vector objects
	std::vector<char> inputVector;
	std::vector<char> outputVector;
	std::vector< std::vector<char> > auxDataBlock; //nxn matrix of chars from the text file, that will be Cyclic shifted and then sorted
	std::vector<char> lastChars; //A vector consisting of chars from the last columb of the sorted auxDataBlock

	//Disable synchronization between the C and C++ standard streams
	std::ios::sync_with_stdio(false);



	//DEBUG: Read command line arguments
	std::cout << "\n" << "##Read arguments##" << "\n";
	std::cout << "argc: " << argc << "\n";
	for (int i = 0; i < argc; i++) {
		std::cout << "argv[" << i << "] " << argv[i] << "\n";
	}


	//Read eachline from stdin and parse each char to a vector, inputVector
	std::cout << "\n" << "##stdin##" << "\n";
	while (std::cin.get(c)) {

		std::cout << c;
		inputVector.push_back(c);
		n++;

	}

	//DEBUG: prints out n and the number of characters of the input text data
	std::cout << "\n";
	//std::cout << "n = " << n << "\n";
	//std::cout << "inputVector.size = " << inputVector.size() << "\n";
	std::cout << "\n";


	//Cyclic shift all char in tempVector to the left in a new vector "v", and copy this to the 2nd row of the auxDataBlock for each n-1 chars
	std::cout << "\n" << "##Shift and make auxDataBlock##" << "\n";
	std::vector<char> v1;
	v1 = inputVector;

	for (int i = 0; i < n; i++) {


		char tempChar;
		std::vector<char> v2;

		//Print vector before next shift
		for (auto const& i : v1) {
			std::cout << i;
		}
		std::cout << "\n";

		auxDataBlock.push_back(v1);

		//Save first char to be put at end
		tempChar = v1.at(0);

		//Save each char, after the first char, to a new temp array, called v2
		for (int j = 1; j < (n); j++) {
			v2.push_back(v1[j]);
		}

		//put the saved first char from before at the end of the temp array, v2
		v2.push_back(tempChar);

		//save the temp array, v2, over the original
		v1 = v2;
	}




	//Print auxDataBlock
	std::cout << "\n" << "##Print Aux: BEFORE##" << "\n";
	for (int i = 0; i < n; i++) {

		std::cout << "Index:" << i << " | ";

		for (int j = 0; j < n; j++) {

			std::cout << auxDataBlock[i][j];

		}

		std::cout << "\n";

	}



	//Sort auxDataBlock
	std::cout << "\n" << "##Sort Aux##" << "\n";
	sortFunct(auxDataBlock);

	//Print auxDataBlock
	std::cout << "\n" << "##Print Aux: AFTER##" << "\n";
	for (int i = 0; i < n; i++) {

		std::cout << "Index:" << i << " | ";

		for (int j = 0; j < n; j++) {

			std::cout << auxDataBlock[i][j];

		}

		std::cout << "\n";

	}

	//Get the last char of each row, make it it's own string and compress it
	std::cout << "\n" << "##Get new String and Compress##" << "\n";

	std::map <int, char> myMap;

	for (int i = 0; i < n; i++) {
		int j = (n - 1);
		lastChars.push_back(auxDataBlock[i][j]);
		std::cout << auxDataBlock[i][j];
	}

	for (auto c : lastChars) {
		++myMap[c];
	}

	for (int i = 0; i < myMap.size(); i++) {
		
		std::cout << myMap[i];

	}

	std::cout << "\n" << "End" << "\n";

	//P.S. There is no Return 0; I intend main.cpp to only exist in a non-failure state
}

void sortFunct(std::vector< std::vector<char> >& bar) {

	if (bar.size() <= 1) {
		return;
	}

	int mid = bar.size() / 2;
	std::vector< std::vector<char> > left;
	std::vector< std::vector<char> > right;

	for (size_t j = 0; j < mid; j++) {
		left.push_back(bar[j]);
	}

	for (size_t j = 0; j < (bar.size()) - mid; j++) {
		right.push_back(bar[mid + j]);
	}

	sortFunct(left);
	sortFunct(right);
	mergeSort(left, right, bar);
}

void mergeSort(std::vector< std::vector<char> >& left, std::vector< std::vector<char> >& right, std::vector< std::vector<char> >& bars)
{
	int nL = left.size();
	int nR = right.size();
	int leftLoop = 0;
	int rightLoop = 0;
	int barLoop = 0;

	while (rightLoop < nL && barLoop < nR)
	{
		if (left[rightLoop] < right[barLoop]) {
			bars[leftLoop] = left[rightLoop];
			rightLoop++;
		}
		else {
			bars[leftLoop] = right[barLoop];
			barLoop++;
		}
		leftLoop++;
	}
	while (rightLoop < nL) {
		bars[leftLoop] = left[rightLoop];
		rightLoop++; leftLoop++;
	}
	while (barLoop < nR) {
		bars[leftLoop] = right[barLoop];
		barLoop++; leftLoop++;
	}
}