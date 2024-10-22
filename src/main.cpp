#include <iostream>
#include <fstream>
#include <regex>
#include <cstdlib>
#include <sstream>
#include "../headers/grep2.h"
#include <vector> 
#include <filesystem>

using namespace std;

void match(regex regEx, ifstream &input, Result &result, Args &args);
bool checkFileExists(string fileName);

int main(int argc, char* argv[]) {

	Args args;
	regex regEx;
	vector<string> files = {};
	Result result;
	string pattern;

	if (argc < 3) {
		cerr << "Expected two arguements" << endl;
		return 1;
	}

	// Assign flags and patterns
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			args.setFlag(argv[i][1]);	
		} else {
			if (!filesystem::is_directory(argv[i]) && filesystem::exists(argv[i])) { // Arg is a file
				files.push_back(argv[i]);
			} else { // Arg is a pattern
				pattern = argv[i];		
			}
		}
	}	

	if (args.matchWholeWord) {
		pattern = "\\b" + pattern + "\\b";	
	}

	if (args.ignoreCasing) {
		regEx.assign(pattern, regex_constants::icase);
	} else {
		regEx.assign(pattern);
	}

	// Loop through files and search
	for (vector<string>::iterator i = files.begin(); i != files.end(); i++) 
	{
		ifstream input;
		input.open(*i);
		int lineNo = 0;
		int startCount = result.count;
		if (input.is_open()) {
			match(regEx, input, result, args);
		}
		input.close();

		if (startCount < result.count) {
			result.fileNames.push_back(*i);
		}
	}
	
	// Output result
	if (args.displayCount) {
		cout << result.count << endl;
	} else if (args.fileNamesOnly && result.count > 0) {
		result.getFileNames();
	} else if (!(args.displayCount || args.fileNamesOnly)) {
		cout << result.matches.str();
	}

	return 0;
}

void match(regex regEx, ifstream &input, Result &result, Args &args) {
	string line;
	int lineNo = 1;
	
	while (getline(input, line)) {
		bool regexMatch = regex_search(line, regEx);
		if (regexMatch ^ args.invertMatch) {
			result.count++;
			if (args.displayLineNumbers) {
				result.matches << lineNo << ": " << line << endl;
			} else {
				result.matches << line << endl;
			}
		}
		lineNo++;
	}

}

bool checkFileExists(string fileName) {
	ifstream input;
	input.open(fileName);
	if (!input.fail()) {
		input.close();
		return true;
	}
	return false;
}
