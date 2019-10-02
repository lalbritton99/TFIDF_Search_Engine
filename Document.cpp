// Author: Marcus Summers

#include "Document.h"
using namespace std;

// constructor
Document::Document()
{
	ID = "0";
	title = "";
	author = "";
	content.clear();
}

// set values in class
void Document::SetID(string set_ID)
{
	ID = set_ID;
}
void Document::SetTitle(string set_title)
{
	title = set_title;
}
void Document::SetAuthor(string set_author)
{
	author = set_author;
}
void Document::SetContent(vector<string> set_content)
{
	content = set_content;
}

// get values from class
string GetID()
{
	return ID;
}
string GetTitle()
{
	return title;
}
string GetAuthor()
{
	return author;
}
vector<string> GetContent()
{
	return content;
}