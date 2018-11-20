#include <time.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char** arga) {
	struct Node {
		string key;
		string value;
		Node* left;
		Node* right;
	};
	size_t size = 1000000;
	Node* pInt = new Node[size];
	int count = 0;
	int index = 0;

	ifstream inputFile;
	istringstream inputStream;

	string input = "";
	string key = "";
	string value = "";
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
			if (count + 1 < size) {
				pInt[count].key = key;
				pInt[count].value = value;
				count++;
			}
			break;
		}
		switchValue++;
		switchValue %= 2;
	}
	inputFile.close();

	key = arga[2];

	clock_t t = clock();

	while (index < size) {
		if ((pInt[index].key).compare(key) == 0) {
			cout << pInt[index].value << endl;
			index = size;
		}
		index++;
	}

	t = clock() - t;
	cout << "time: " << t << " milliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	delete[] pInt;

	return 0;
}
