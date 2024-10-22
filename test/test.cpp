/* 
 * Title: test.cpp
 * Author: Matt
 *
 * Testing for grep2 program
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	system("../build/grep2 . ../test/mockTestFile.txt > output.txt");
	system("grep . ../test/mockTestFile.txt > expectedOutput.txt");	
	
	system("diff output.txt expectedOutput.txt > diff.txt");
	
	ifstream input;
	input.open("diff.txt");

	int c = input.peek();
	input.close();

	return c != EOF;
}
