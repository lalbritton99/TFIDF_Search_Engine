#include "document.h"

// constructor
document::document()
{
	ID = "0";
	title = "";
	author = "";
	content.clear();
}

// set values in class
void document::SetID(string ID)
{
	this->ID = ID;
}
void document::SetTitle(string title)
{
	this->title = title;
}
void document::SetAuthor(string author)
{
	this->author = author;
}
void document::SetContent(vector<string> content)
{
	this->content = content;
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