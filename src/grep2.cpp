/*
 * grep2.cpp: Passing command line flags
 *
 */

#include "../headers/grep2.h"
#include <cstdlib>
#include <sstream>
#include <vector> 
#include <iostream>

using namespace std;

Args::Args() {
	displayCount = false;
	ignoreCasing = false;
	fileNamesOnly = false;
	displayLineNumbers = false;
	invertMatch = false;
	matchWholeWord = false;
}


void Args::setFlag(char flag) {
	switch(flag) {
		case 'c':
			displayCount = true;
			break;
		case 'i':
			ignoreCasing = true;
			break;
		case 'l':
			fileNamesOnly = true;
			break;
		case 'n':
			displayLineNumbers = true;
			break;
		case 'v':
			invertMatch = true;
			break;
		case 'w':
			matchWholeWord = true;
			break;
		default:
			break;
	}
			
}

Result::Result() {
	count = 0;

}

void Result::getFileNames() {
	for (string file: fileNames) {
		cout << file << endl;
	}
}
