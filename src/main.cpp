#include <iostream>
#include <fstream>
#include <regex>
#include <cstdlib>
#include <sstream>
#include "../headers/grep2.h"
#include <vector> 

using namespace std;


int main(int argc, char* argv[]) {

	Args args;
	string file = argv[argc - 1];
	regex regEx;
	string pattern;
	vector<string> files = {};
	Result result;

	if (argc < 3) {
		cerr << "Expected two arguements" << endl;
		return 1;
	}

	// get flags, files, and pattern
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			args.setFlag(argv[i][1]);	
		} else {
			ifstream testFile(argv[i]);
			if (testFile.good()) { // Arg is a file
				files.push_back(argv[i]);
			} else { // Arg is a pattern
				pattern = argv[i];		
			}
		}
	}
		
	if (args.ignoreCasing) {
		regEx.assign(pattern, regex_constants::icase);
	} else {
		regEx.assign(pattern);
	}

	for (vector<string>::iterator i = files.begin(); i != files.end(); i++) 
	{
		ifstream input;
		input.open(*i);
		stringstream result;
		int lineNo = 0;
		if (input.is_open()) {
			string line;
			while (getline(input, line)) {
				if (regex_search(line, regEx)) {
					result.count++;
					if (args.displayLineNumbers) {
						result << lineNo << ": " << line << endl;
					} else {
						result << line << endl;
					}
				}
				lineNo++;
			}
			input.close();
		}
	}

	if (args.displayCount) {
		cout << result.count << endl;
	} else if (args.fileNamesOnly && result.count > 0) {
	       cout << result.fileNames << endl; 
	} else if (!(args.displayCount || args.fileNamesOnly)) {
		cout << result.matches.str();
	}

	return 0;
}

void search(string file, Result result, Args args) {

	ifstream input;
	input.open(*i);
	if (input.is_open()) {
		string line;
		int lineNo = 0;
		while (getline(input, line)) {
			if (regex_search(line, regEx)) {
				result.count++;
				if (args.displayLineNumbers) {
					result << lineNo << ": " << line << endl;
				} else {
					result << line << endl;
				}
			}
			lineNo++;
		}
		input.close();
	}
}
