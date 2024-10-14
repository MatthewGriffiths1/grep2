/*
 * Headers for grep2
 *
 */

#ifndef grep2_h
#define grep2_h


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
#endif

