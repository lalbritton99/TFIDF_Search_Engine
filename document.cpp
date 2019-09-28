#include "document.h"

// constructor
document::document()
{
	ID = 0;									
	title = "";								
	author = "";									
	// vector already initialized?							
}

// set values in class
void document::SetID(int ID)
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
void document::SetContent(vector content)
{
	this->content = content;
}

// get values from class
int GetID()
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
vector GetContent()
{
	return content;
}