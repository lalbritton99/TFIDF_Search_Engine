#ifndef PORTSTEM
#define PORTSTEM

#include <iostream>
#include <string>
using namespace std;

class porterStem{
	private:
		string word;
	public:
		porterStem();
		void setWord(string change);
		string getWord();
		string portStem(string change);
};


#endif
