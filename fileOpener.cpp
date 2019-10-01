// Author: Marcus Summers


#include "fileOpener.h"
// #include "document.h" // fixme - add the document header when it's ready
using namespace std;

// IMPORTANT NOTE: we will split the documents file up into a vector of separate documents
// and use a loop to iterate through it IN THE MAIN. This results in a vast simplification
// of the required features of this function.

void fileOpener(string file_type)
{
	// the file we are opening
	ifstream file;

	// validity check
	while(true)
	{
		// name of our file
		string file_name = "";

		cout << "Enter " << file_type << " file: ";
		cin >> file_name;

		file.open(file_name);

		// breaks validation loop if file is open
		if (!file.is_open())
		{
			cout << endl;
			cout << "--- " << file_type << " file " << file_name << " does not exist. Try Again ---" << endl;
			cout << endl;
		}
		else
		{
			break;
		}
	}

	// different parsing based on type
	// this is the Documents file
	if (file_type == "Documents")
	{
		string ID = "";
		string title = "";
		string author = "";
		string abstract = "";

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

		// gets the ID
		for (int i = 0; i < file_vector.size(); ++i)
		{
			if (file_vector[i].find(".I") != string::npos)
			{
				ID = file_vector[i + 1];
				break;
			}
		}
		// gets the title
		bool isTitle = false;
		for (int i = 0; i < file_vector.size(); ++i)
		{
			if (file_vector[i] == ".A")
			{
				isTitle = false;
			}
			if (isTitle)
			{
				title = title + file_vector[i] + ' ';
			}
			if (file_vector[i] == ".T")
			{
				isTitle = true;
			}
		}
		// gets the author
		for (int i = 0; i < file_vector.size(); ++i)
		{
			if (file_vector[i].find(".A") != string::npos)
			{
				author = file_vector[i + 1];
				break;
			}
		}
		// gets the abstract
		bool isAbstract = false;
		for (int i = 0; i < file_vector.size(); ++i)
		{
			if (isAbstract)
			{
				abstract = abstract + file_vector[i] + ' ';
			}
			if (file_vector[i] == ".W")
			{
				isAbstract = true;
			}
		}

		// below: AFTER SPLITTING OFF TO ABSTRACT ONLY

		// turns all abstract punctuation into spaces
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

		// puts abstract back into a vector
		vector<string> abstract_vector;
		stringstream abstract_stringstream(abstract);
		string tempWord = "";
		while (getline(abstract_stringstream, tempWord, ' '))
		{
			abstract_vector.push_back(tempWord);
		}
		// fixme
		cout << abstract_vector.size() << endl;
		// gets rid of empty spaces in abstract vector
		for (int i = 0; i < abstract_vector.size(); ++i)
		{
			if (abstract_vector[i] == "")
			{
				abstract_vector.erase(abstract_vector.begin() + i);
				i--;
			}
		}
		// fixme
		cout << abstract_vector.size() << endl;

		// fixme
		for (int i = 0; i < file_vector.size(); ++i)
		{
			cout << abstract_vector[i] << endl;
		}
		cout << ID << endl;
		cout << title << endl;
		cout << author << endl;
	}

	// return a vector of documents (even if just one)
}