/* 
 * Title: test.cpp
 * Author: Matt
 *
 * Testing for grep2 program
 */

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <format>
#include <fstream>
#include <vector>

using namespace std;

bool execute(string flag, string regEx, string application, string testFile);

int main(int argc, char* argv[]) {
	// No command line flags tests
	vector<bool> results;
	results.push_back(execute("", ".", argv[1], argv[2]));	
	//results.push_back(execute("", ".*", argv[1], argv[2])); 
	// ^ This one thinks the file is a directory for some reason	
	results.push_back(execute("", "lorem", argv[1], argv[2]));	
	results.push_back(execute("", "\\n", argv[1], argv[2]));	
	results.push_back(execute("", "\\s* ", argv[1], argv[2]));	
	results.push_back(execute("", ".\\s* ", argv[1], argv[2]));	


	results.push_back(execute("-c", ".", argv[1], argv[2]));	
	//results.push_back(execute("", ".*", argv[1], argv[2])); 
	// ^ This one thinks the file is a directory for some reason	
	results.push_back(execute("-c", "lorem", argv[1], argv[2]));	
	results.push_back(execute("-c", "\\n", argv[1], argv[2]));	
	results.push_back(execute("-c", "\\s* ", argv[1], argv[2]));	
	results.push_back(execute("-c", ".\\s* ", argv[1], argv[2]));


	results.push_back(execute("-i", "iPsUm", argv[1], argv[2]));	
	//results.push_back(execute("", ".*", argv[1], argv[2])); 
	// ^ This one thinks the file is a directory for some reason	
	results.push_back(execute("-i", "lorem", argv[1], argv[2]));	
	results.push_back(execute("-i", "LOREM", argv[1], argv[2]));	
	
	results.push_back(execute("-l", "lorem", argv[1], argv[2]));
	
	bool result = true;

	for (vector<bool>::iterator i = results.begin(); i != results.end(); i++) {
		result = result && *i;
	}	

	cout << result << endl;

	return result;
}

bool execute(string flag, string regEx, string application, string testFile) {

	string firstCall;
	string secondCall;

	if (flag.empty()) {
		firstCall = application + " " + regEx + " " + testFile + " > output.txt";
		secondCall = "grep " + regEx + " " + testFile + " > expectedOutput.txt";
	} else {
		firstCall = application + " " + flag + " " + regEx + " " + testFile + " > output.txt";
		secondCall = "grep " + flag + " " + regEx + " " + testFile + " > expectedOutput.txt";
	}

	system(firstCall.c_str());
	system(secondCall.c_str());
	system("diff output.txt expectedOutput.txt > diff.txt");

	//cout << firstCall << endl;
	//cout << secondCall << endl;

	// open diff file to check results	
	ifstream input;
	input.open("diff.txt");
	int c = input.peek();
	input.close();
	
	bool result = c == EOF;
	if (result) {
		cout << "PASS" << endl;
	} else {
		cout << "FAIL" << endl;
	}
	return result;
}
