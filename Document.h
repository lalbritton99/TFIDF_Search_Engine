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

		void SetID(string set_ID);
		void SetTitle(string set_title);
		void SetAuthor(string set_author);
		void SetContent(vector<string> set_content);

		string GetID();
		string GetTitle();
		string GetAuthor();
		vector<string> GetContent();
};