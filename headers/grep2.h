/*
 * Headers for grep2
 *
 */

#ifndef grep2_h
#define grep2_h

#include <sstream>
#include <vector>

using namespace std;

class Args {
	public:
		bool displayCount;
		bool ignoreCasing;
		bool fileNamesOnly;
		bool displayLineNumbers;
		bool invertMatch;
		bool matchWholeWord;
		Args();
		void setFlag(char flag);
};

class Result {
	public:
	      	int count;
		stringstream matches;
		vector<string> fileNames;
		Result();
		void getFileNames();
};
#endif

