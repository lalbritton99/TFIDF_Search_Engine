#include <iostream>
#include <string>
#include <vector>
using namespace std;

class document
{
	private:
		int ID = -1;								// .I
		string title = '';							// .T
		string author = '';							// .A
		vector<string> content;						// .W
	public:
		document();
};