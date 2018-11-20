#include <time.h>
#include <fstream>
#include <sstream>
#include "BST.h"

int main(int argc, char** arga) {
	ifstream inputFile;
	string input = "";
	BSTAVL bst;
	string key = "";
	string value = "";
	istringstream inputStream;
	int switchValue = 0;

	inputFile.open(arga[1]);
	getline(inputFile, input, '\n');
	while (!inputFile.eof()) {
		switch (switchValue) {
		case 0:
			getline(inputFile, input, ',');
			key = input;
			break;
		case 1:
			getline(inputFile, input, '\n');
			value = input;
			bst.insert(key, value);
			break;
		}
		switchValue++;
		switchValue %= 2;
	}
	inputFile.close();

	clock_t t = clock();

	cout << bst.find(arga[2]) << endl;

	t = clock() - t;
	cout << "time: " << t << " milliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	return 0;
}
