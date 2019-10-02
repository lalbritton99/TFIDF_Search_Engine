#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Document
{
	private:
		string ID;							// .I
		string title;						// .T
		string author;						// .A
		vector<string> content;				// .W
	public:
		Document();

		void SetID(string ID);
		void SetTitle(string title);
		void SetAuthor(string author);
		void SetContent(vector<string> content);

		string GetID();
		string GetTitle();
		string GetAuthor();
		vector<string> GetContent();
};