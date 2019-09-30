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
		// FIXME/NOTE: MUST EVENTUALLY ITERATE THROUGH INDEFINITE NUMBER OF DOCS PER FILE
		// sections
		string ID = "";
		string title = "";
		string author = "";
		string abstract = "";

		// puts the entire file into a string -- FIXME SEE NOTE
		string file_string = "";
		string line = "";
		while(getline(file, line))
		{
			file_string.append(line);
			file_string.append("\n");
		}

		// splits the file string up into parts
		ID = file_string.substr(file_string.find(".I") + 3, file_string.find(".T") - 3);
		title = file_string.substr(file_string.find(".T") + 3, file_string.find(".A") - 3);
		author = file_string.substr(file_string.find(".A") + 3, file_string.find(".W") - 3);
		abstract = file_string.substr(file_string.find(".W") + 3, file_string.length());

		// fixme
		cout << ID << endl << endl;
		cout << title << endl << endl;
		cout << author << endl << endl;
		cout << abstract << endl << endl;

		// below: AFTER SPLITTING OFF TO ABSTRACT ONLY

		// turns all hypens into spaces (required to space delimit)
		replace(file_string.begin(), file_string.end(), '-', ' ');
	}

	// return a vector of documents (even if just one)
}