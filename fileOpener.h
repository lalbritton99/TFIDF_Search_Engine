#include <iostream>
#include <fstream>
#include <string>
//#include <document.h> // this function will read a file into instance of document class

void fileOpener(string file_type, string file_name)
{
	while(true)
	{
		cout << endl;
		cout << file_type << " file name: ";
		cin >> stopwordsFile;

		// fixme
		cout << "s: " << stopwordsFile << endl;

		stopwords.open(stopwordsFile);

		if (!stopwords.is_open())
		{
			cout << endl;
			cout << "--- Stopwords file " << stopwordsFile << " does not exist. Try Again ---" << endl;
		}
		else
		{
			break;
		}
	}

	// return <NAME OF DOCUMENT CLASS INSTANCE>
}