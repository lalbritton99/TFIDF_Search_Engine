// Author: Marcus Summers



#include "fileOpener.h"
using namespace std;

// IMPORTANT NOTE: we will split the documents file up into a vector of separate documents
// and use a loop to iterate through it IN THE MAIN. This results in a vast simplification
// of the required features of this function.

vector<Document> fileOpener()
{
	// the file we are opening
	ifstream file;

	// validity check
	while(true)
	{
		// name of our file
		string file_name = "";

		cout << "Enter documents file: ";
		cin >> file_name;

		file.open(file_name);

		// breaks validation loop if file is open
		if (!file.is_open())
		{
			cout << endl;
			cout << "--- Documents file " << file_name << " does not exist. Try Again ---" << endl;
			cout << endl;
		}
		else
		{
			break;
		}
	}

	// puts the entire file into a string
	string file_string = "";
	string line = "";
	while (getline(file, line))
	{
		file_string.append(line);
		file_string.append("\n");
	}

	// splits the file string up into parts
	vector<string> file_vector;
	stringstream file_stringstream(file_string);
	string tempLine = "";
	while (getline(file_stringstream, tempLine))
	{
		stringstream line_stringstream(tempLine);
		string tempWord = "";
		while (getline(line_stringstream, tempWord, ' '))
		{
			file_vector.push_back(tempWord);
		}
	}

	// gets whitespace and empty elements out of file_vector
	for (int i = 0; i < file_vector.size(); ++i)
	{
		if (file_vector[i] == " " | file_vector[i] == "\n" | file_vector[i] == " \n" | file_vector[i] == "")
		{
			file_vector.erase(file_vector.begin() + i);
			i--;
		}
	}

	// actual vector of separate text documents
	vector<vector<string> > documents_vector;
	// vector of strings (all words and delimiters in document) to add to documents_vector
	vector<string> individual_document_vector;

	// puts vectors of strings into documents_vector
	bool isNewDocument = false;
	for (int i = 0; i < file_vector.size(); ++i)
	{
		// if the new document has started and another ".I"
		// (the end of the document) is found
		if (file_vector[i] == ".I" && isNewDocument)
		{
			isNewDocument = false;
			documents_vector.push_back(individual_document_vector);
			individual_document_vector.clear();
		}
		// picks up the first ".I"
		if (file_vector[i] == ".I")
		{
			isNewDocument = true;
		}
		// if the new document has started
		if (isNewDocument)
		{
			individual_document_vector.push_back(file_vector[i]);
		}
		// same if end of file_vector is reached
		if (i == file_vector.size() - 1)
		{
			isNewDocument = false;
			documents_vector.push_back(individual_document_vector);
			individual_document_vector.clear();
		}
	}

	// the actual parsing loop (works through each item of documents_vector)
	vector<Document> Documents;
	for (int j = 0; j < documents_vector.size(); ++j) // change to "documents_vector.size()"
	{
		string ID = "";
		string title = "";
		string author = "";
		string abstract = "";

		// FINDS ALL THE FIELDS (strings ID, title, author, abstract)
		// gets the ID
		for (int i = 0; i < documents_vector[j].size(); ++i)
		{
			if (documents_vector[j][i].find(".I") != string::npos)
			{
				ID = documents_vector[j][i + 1];
				break;
			}
		}
		// gets the title
		bool isTitle = false;
		for (int i = 0; i < documents_vector[j].size(); ++i)
		{
			if (documents_vector[j][i] == ".A")
			{
				isTitle = false;
			}
			if (isTitle)
			{
				title = title + documents_vector[j][i] + ' ';
			}
			if (documents_vector[j][i] == ".T")
			{
				isTitle = true;
			}
		}
		// gets the author
		bool isAuthor = false;
		for (int i = 0; i < documents_vector[j].size(); ++i)
		{
			if (documents_vector[j][i] == ".W")
			{
				isAuthor = false;
			}
			if (isAuthor)
			{
				author = author + documents_vector[j][i] + ' ';
			}
			if (documents_vector[j][i] == ".A")
			{
				isAuthor = true;
			}
		}
		// gets the abstract
		bool isAbstract = false;
		for (int i = 0; i < documents_vector[j].size(); ++i)
		{
			if (isAbstract)
			{
				abstract = abstract + documents_vector[j][i] + ' ';
			}
			if (documents_vector[j][i] == ".W")
			{
				isAbstract = true;
			}
		}

		// TURNS ALL ABSTRACT PUNCTUATION INTO SPACES
		replace(abstract.begin(), abstract.end(), '-', ' ');
		replace(abstract.begin(), abstract.end(), '.', ' ');
		replace(abstract.begin(), abstract.end(), ',', ' ');
		replace(abstract.begin(), abstract.end(), '/', ' ');
		replace(abstract.begin(), abstract.end(), '(', ' ');
		replace(abstract.begin(), abstract.end(), ')', ' ');
		replace(abstract.begin(), abstract.end(), '[', ' ');
		replace(abstract.begin(), abstract.end(), ']', ' ');
		replace(abstract.begin(), abstract.end(), '{', ' ');
		replace(abstract.begin(), abstract.end(), '}', ' ');
		replace(abstract.begin(), abstract.end(), '"', ' ');
		replace(abstract.begin(), abstract.end(), '\'', ' ');
		replace(abstract.begin(), abstract.end(), '|', ' ');
		replace(abstract.begin(), abstract.end(), '\\', ' ');
		replace(abstract.begin(), abstract.end(), '_', ' ');
		replace(abstract.begin(), abstract.end(), '!', ' ');
		replace(abstract.begin(), abstract.end(), '?', ' ');
		replace(abstract.begin(), abstract.end(), '@', ' ');
		replace(abstract.begin(), abstract.end(), '#', ' ');
		replace(abstract.begin(), abstract.end(), '$', ' ');
		replace(abstract.begin(), abstract.end(), '%', ' ');
		replace(abstract.begin(), abstract.end(), '^', ' ');
		replace(abstract.begin(), abstract.end(), '&', ' ');
		replace(abstract.begin(), abstract.end(), '*', ' ');
		replace(abstract.begin(), abstract.end(), '+', ' ');
		replace(abstract.begin(), abstract.end(), '+', ' ');
		replace(abstract.begin(), abstract.end(), ':', ' ');
		replace(abstract.begin(), abstract.end(), ';', ' ');
		replace(abstract.begin(), abstract.end(), '`', ' ');
		replace(abstract.begin(), abstract.end(), '~', ' ');

		// PUTS ABSTRACT INTO VECTOR
		vector<string> abstract_vector;
		// preps the abstract string as a stream
		stringstream abstract_stringstream(abstract);
		string tempWord = "";
		while (getline(abstract_stringstream, tempWord, ' '))
		{
			abstract_vector.push_back(tempWord);
		}
		// gets rid of empty spaces in abstract vector
		for (int i = 0; i < abstract_vector.size(); ++i)
		{
			if (abstract_vector[i] == "")
			{
				abstract_vector.erase(abstract_vector.begin() + i);
				i--;
			}
		}

		// REMOVE TITLE FROM ABSTRACT
		vector<string> title_vector;
		// clears punctuation from title
		string tempTitle = title;
		replace(tempTitle.begin(), tempTitle.end(), '-', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '.', ' ');
		replace(tempTitle.begin(), tempTitle.end(), ',', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '/', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '(', ' ');
		replace(tempTitle.begin(), tempTitle.end(), ')', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '[', ' ');
		replace(tempTitle.begin(), tempTitle.end(), ']', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '{', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '}', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '"', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '\'', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '|', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '\\', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '_', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '!', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '?', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '@', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '#', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '$', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '%', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '^', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '&', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '*', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '+', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '+', ' ');
		replace(tempTitle.begin(), tempTitle.end(), ':', ' ');
		replace(tempTitle.begin(), tempTitle.end(), ';', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '`', ' ');
		replace(tempTitle.begin(), tempTitle.end(), '~', ' ');
		// the string is prepared to read into getline() as a stream
		stringstream tempTitle_stringstream(tempTitle);
		tempWord = "";
		while (getline(tempTitle_stringstream, tempWord, ' '))
		{
			title_vector.push_back(tempWord);
		}
		// gets rid of empty spaces in title vector
		for (int i = 0; i < title_vector.size(); ++i)
		{
			if (title_vector[i] == "")
			{
				title_vector.erase(title_vector.begin() + i);
				i--;
			}
		}
		// actually removes title elements from abstract_vector
		for (int i = 0; i < title_vector.size(); ++i)
		{
			if (abstract_vector[i] == title_vector[i])
			{
				abstract_vector.erase(abstract_vector.begin() + i);
				title_vector.erase(title_vector.begin() + i);
				i--;
			}
			else
			{
				break;
			}
		}

		// sets the fields in Document class and pushes back on Documents vector
		Document tempDocument;
		tempDocument.SetID(ID);
		tempDocument.SetTitle(title);
		tempDocument.SetAuthor(author);
		tempDocument.SetContent(abstract_vector);
		Documents.push_back(tempDocument);
	}

	// returns vector of Document class instances
	return Documents;

	// closes the file
	file.close();
}