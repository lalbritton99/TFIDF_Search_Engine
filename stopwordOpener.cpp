// Author: Marcus Summers

#include "stopwordOpener.h"
using namespace std;

vector<string> stopwordOpener()
{
	// the file we are opening
	ifstream file;

	// validity check
	while(true)
	{
		// name of our file
		string file_name = "";

		cout << "Enter stopwords file: ";
		cin >> file_name;

		file.open(file_name);

		// breaks validation loop if file is open
		if (!file.is_open())
		{
			cout << endl;
			cout << "--- Stopwords file " << file_name << " does not exist. Try Again ---" << endl;
			cout << endl;
		}
		else
		{
			break;
		}
	}

	// gets the stopwords into a vector
	string temp = "";
	vector<string> stopwords_vector;
	while (getline(file, temp))
	{
		stopwords_vector.push_back(temp);
	}

	// closes the file
	file.close();

	// returns a vector of stopwords (strings)
	return stopwords_vector;
}