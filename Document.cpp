// Author: Marcus Summers

#include "Document.h"
using namespace std;

// constructor
Document::Document()
{
	ID = "0";
	title = "";
	author = "";
	abstract = "";
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
void Document::SetAbstract(string set_abstract)
{
	abstract = set_abstract;
}
void Document::SetContent(vector<string> set_content)
{
	content = set_content;
}

// get values from class
string Document::GetID()
{
	return ID;
}
string Document::GetTitle()
{
	return title;
}
string Document::GetAuthor()
{
	return author;
}
string Document::GetAbstract()
{
	return abstract;
}
vector<string> Document::GetContent()
{
	return content;
}