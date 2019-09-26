#include <iostream>
#include <string>
#include <vector>
using namespace std;

class document
{
	private:
		int ID;								// .I
		string title;						// .T
		string author;						// .A
		vector<string> content;				// .W
	public:
		document();

		void SetID(int ID);
		void SetTitle(string title);
		void SetAuthor(string author);
		void SetContent(vector content);

		int GetID();
		string GetTitle();
		string GetAuthor();
		vector GetContent();
};