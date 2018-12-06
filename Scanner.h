#ifndef SCANNER_H
#define SCANNER_H

#include <fstream>
#include <sstream>
#include "BST.h"

//Chris Sellers
//11/21/2018
//Assignment 4 - UPC Scanner

//This class is used to read in from a file and
//store values in a BST.
class Scanner {
	string filePath;
	BST bst;

	//Read in the contents of the file
	void readInFile() {
		ifstream inputFile;
		string input, key, value;

		inputFile.open(filePath);
		getline(inputFile, input, '\n');
		while (!inputFile.eof()) {
			getline(inputFile, key, ',');
			getline(inputFile, value, '\n');
			bst.insert(key, value);
		}
		inputFile.close();
	}

public:
	//Constructor
	Scanner(string filePath) {
		this->filePath = filePath;
		readInFile();
	}

	//Search for the provided key
	string find(string key) {
		return bst.find(key);
	}
};

#endif
