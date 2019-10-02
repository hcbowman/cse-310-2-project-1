#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include"encode.h"
#include"decode.h"


#ifdef DECRYPT
#define CASE_INDEX 2
#else
#define CASE_INDEX 1
#endif

void mergeSort(std::vector< std::string >& bar);
void mergeHelper(std::vector< std::string >& left, std::vector< std::string >& right, std::vector< std::string >& bars);
void insertionSort(std::vector< std::string >& bar);
void insertionSort2(std::vector< std::string >& bar);
std::string insertionSortString(std::string bar);


int main(int argc, char* argv[]) {

	//std::cout << "CSE310 Project 1" << "\n" << "\n";

	//Variables
	std::string lineArg;
	//char c; //For the chars read in with cin.get()

	//Objects
	std::string compressedChars; //Vector containing the compressed output from the auxDataBlock
	std::string inputLine;

	//Disable synchronization between the C and C++ standard streams
	std::ios::sync_with_stdio(false);



	//DEBUG: Print command line arguments
	//std::cout << "\n" << "########## DEBUG: Print arguments ##########" << "\n";
	//std::cout << "argc: " << argc << "\n";
	//for (int i = 0; i < argc; i++) {
	//	std::cout << "argv[" << i << "] " << argv[i] << "\n";
	//}

	//Checks for a specified sort. If none, it will default to insertion sort
	if (argv[1] != NULL) {
		lineArg = argv[1];
	}
	else {
		//std::cout << "No input defaulting to insertion sort" << "\n";
		lineArg = "insertion";
	}

	//DEBUG:
	//if (lineArg == "insertion") {
	//	std::cout << "Use insertion sort for encoding algorithm" << "\n";
	//}
	//else if (lineArg == "merge"){
	//	std::cout << "Use merge sort for encoding algorithm" << "\n";
	//}
	//else {
	//	std::cout << "wrong input... defaulting to insertion" << "\n";
	//	lineArg = "insertion";
	//}

	switch (CASE_INDEX) {

		case 1:

			//This while loop reads a line from stdin and then encodes it
			while (std::getline(std::cin, inputLine)) {





				//Encode objects
				std::vector< std::string > auxDataBlock; //nxn matrix of chars from the text file, that will be Cyclic shifted and then sorted
				std::string sortedColumnChars; //A vector consisting of chars from the last column of the sorted auxDataBlock
				std::string v1;

				//Encode variables
				int index = 0;



				//This for loop copies the string to each new index of the vector, shifted
				v1 = inputLine;
				for (unsigned int i = 0; i < inputLine.size(); i++) {
					char tempChar;
					std::string v2;

					//DEBUG: Print vector before next shift
					//for (auto const& i : v1) {
					//	std::cout << i;
					//}
					//std::cout << "\n";

					auxDataBlock.push_back(v1);

					//Save first char to be put at end
					tempChar = v1.at(0);

					//Save each char, after the first char, to a new temp array, called v2
					for (unsigned int j = 1; j < inputLine.size(); j++) {
						v2.push_back(v1[j]);
					}

					//put the saved first char from before at the end of the temp array, v2
					v2.push_back(tempChar);

					//save the temp array, v2, over the original
					v1 = v2;
				}

				//Sort my block
				if (lineArg == "merge") {
					mergeSort(auxDataBlock);
				}
				else {
					insertionSort(auxDataBlock);
				}



				////DEBUG: Print auxDataBlock
				//std::cout << "\n" << "########## Print sorted Aux ##########" << "\n";
				//for (unsigned int i = 0; i < inputLine.size(); i++) {

				//	std::cout << "Index:" << i << " | ";

				//	for (unsigned int j = 0; j < inputLine.size(); j++) {
				//		std::cout << auxDataBlock[i][j];
				//	}

				//	std::cout << "\n";
				//}


				//Find idex of original string
				for (unsigned int i = 0; i < inputLine.size(); i++) {

					if (inputLine == auxDataBlock[i]) {
						index = i;
						break;
					}

				}

				//Get the last column
				for (unsigned int i = 0; i < inputLine.size(); i++) {
					int jj = (inputLine.size() - 1);
					sortedColumnChars.push_back(auxDataBlock[i][jj]);
				}


				//Count occurrences of the chars / compress it
				std::cout << index << "\n";
				for (unsigned int i = 0; i < inputLine.size(); i++) {

					int count = 1;

					while (i < inputLine.size() - 1 && sortedColumnChars[i] == sortedColumnChars[i + 1]) {
						count++;
						i++;
					}

					//Output encoded text
					std::cout << (int)count << " " << sortedColumnChars[i] << " ";


				}
				std::cout << "\n";


			}

			break;

		case 2:

			//DEBUG
			//std::cout << "case 2" << "\n";

			//Decode Objects
			std::string indexLine; //To hold the index before the line to be decoded
			std::string encodedLine; //To hold the encoded line

			//This while loop reads a line from stdin and then decodes it; basically goes through our text line by line
			while (std::getline(std::cin, indexLine)) {

				std::getline(std::cin, encodedLine);


				//Decode temp variables
				int position = 0; //Used to keep track of the position of the spaces 

				//Decode temp Objects
				std::string last; //Used to store the decoded last line of the sorted column
				std::string lastSorted; //Used to store the sorted decoded last line of the sorted column
				std::string completeDecoded; //This is the finished line
				std::vector<std::string> decAuxDataBlock;
				std::vector<int> next;


				//DEBUG: 
				//std::cout << "INDEX:" << indexLine << "\n";
				//std::cout << encodedLine << "ENCODED" << "\n";

				//Convert the index to an int for use
				int index = std::stoi(indexLine);


				//Iterate through the encodedLine to for parsing/decoding
				for (unsigned int i = 0; i < encodedLine.size(); i++) {

					//Check if we are at a space AND if the follwing char is not a space; this skips the inbetweener spaces but not the ones that need to be a part of the decode
					if ( (encodedLine[i] == ' ') && (encodedLine[i + 1] != ' ' || encodedLine[i - 1] != ' ') ) {
						position++;
						continue;
					}

					//If the number of chars is a two digit number, else it's a single digit
					if ( std::isdigit(encodedLine[i]) && std::isdigit(encodedLine[i + 1])) {


						//Stores the number before the char
						std::string stringInt;

						stringInt += encodedLine[i];
						stringInt += encodedLine[i + 1];

						//DEBUG
						//std::cout << "encodedLine[i]:" << encodedLine[i] << "\n";
						//std::cout << "encodedLine[i++]:" << encodedLine[i + 1] << "\n";

						int cnt = std::stoi(stringInt);

						//DEBUG
						//std::cout << "encodedLine2D[i]:" << cnt << "\n";

						for (int j = 0; j < cnt; j++) {
							last.push_back(encodedLine[i + 3]);
						}

						i++;

					}
					else if ( std::isdigit(encodedLine[i]) && (position%2 == 0) ) {

						//DEBUG
						//std::cout << "encodedLine1D[i]:" << encodedLine[i] << "\n";

						int cnt = (int)encodedLine[i] - 48;

						for (int j = 0; j < cnt; j++) {
							last.push_back(encodedLine[i + 2]);
						}

					}

				}

				//DEBUG
				//std::cout << "LAST:" << last << "\n";

				//Sort last
				lastSorted = insertionSortString(last);

				//DEBUG
				//std::cout << "lastSorted:" << lastSorted << "\n";


				int ii = 0;
				for (int j = 0; j < last.size(); j++) {

					if ( (lastSorted[ii] == last[j]) && (lastSorted[ii] != lastSorted[ii + 1]) ) {
							next.push_back(j);
							j = -1;
							ii++;
					}
					else if ( (lastSorted[ii] == last[j]) && (lastSorted[ii] == lastSorted[ii + 1])){
							next.push_back(j);
							ii++;
					}


				}


				//DEBUG: Print out the int vector NEXT
				//std::cout << "next:";
				//for (int i : next) {
				//	std::cout << i << " ";
				//}
				//std::cout << "\n";

				//Use index, next and last
				if (!next.empty()) {
					int x = next[index];
					for (unsigned int i = 0; i < last.size(); i++) {

						completeDecoded.push_back(last[x]);
						x = next[x];

					}
				}
				else {
					completeDecoded = "";
				}
				
				//DEBUG
				//std::cout << "complete decoded:" << completeDecoded << "\n";
				std::cout << completeDecoded << "\n";

			}

			break;

	}

}

void insertionSort(std::vector< std::string >& bar) {

	for (unsigned int i = 1; i < bar.size(); i++) {

		for (unsigned int j = i; j > 0 && bar[j - 1] > bar[j]; j--) {

			std::string temp = bar[j];

			bar[j] = bar[j - 1];

			bar[j - 1] = temp;

		}

	}
}

void insertionSort2(std::vector< std::string >& bar) {


	for (unsigned int i = 1; i < bar.size(); i++) {



		std::string key = bar[i];

		int j = i - 1;
		while (j > 0 || key < bar[j]) {

			bar[j + 1] = bar[j];
			j--;
		}
		bar[j + 1] = key;


	}

}

std::string insertionSortString(std::string bar) {

	for (unsigned int i = 1; i < bar.size(); i++) {

		for (unsigned int j = i; j > 0 && bar[j - 1] > bar[j]; j--) {

			char temp = bar[j];

			bar[j] = bar[j - 1];

			bar[j - 1] = temp;

		}

	}

	return bar;
}




//Merge Sort function
void mergeSort(std::vector< std::string >& bas) {

	//Base case
	if (bas.size() <= 1) {
		return;
	}

	//Mid point
	int mid = bas.size() / 2;

	//Left and right sub-vectors
	std::vector< std::string > leftVector;
	std::vector< std::string > rightVector;

	//Fill left and right sub-vectors
	for (size_t j = 0; j < (unsigned int)mid; j++) {
		leftVector.push_back(bas[j]);
	}
	for (size_t j = 0; j < (bas.size()) - mid; j++) {
		rightVector.push_back(bas[mid + j]);
	}

	//Reeecuuuursion ruulz
	mergeSort(leftVector);
	mergeSort(rightVector);
	mergeHelper(leftVector, rightVector, bas);
}

//A helper function for merge sort
void mergeHelper(std::vector< std::string >& left, std::vector< std::string >& right, std::vector< std::string >& base)
{
	//Variables
	int newLeft = left.size();
	int newRight = right.size();
	int leftLoop = 0;
	int rightLoop = 0;
	int barLoop = 0;

	//
	while (rightLoop < newLeft && barLoop < newRight)
	{
		if (left[rightLoop] < right[barLoop]) {
			base[leftLoop] = left[rightLoop];
			rightLoop++;
		}
		else {
			base[leftLoop] = right[barLoop];
			barLoop++;
		}
		leftLoop++;
	}
	while (rightLoop < newLeft) {
		base[leftLoop] = left[rightLoop];
		rightLoop++; leftLoop++;
	}
	while (barLoop < newRight) {
		base[leftLoop] = right[barLoop];
		barLoop++; leftLoop++;
	}
}