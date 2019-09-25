#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//#include "tfidf.h"
//#include "document.h"
//#include "documentCol.h"

int main()
{
	string documentsFile = "";
	string stopwordsFile = "";
	ifstream documents;
	ifstream stopwords;

	// gets documents file from user
	while(true)
	{
		cout << endl;
		cout << "Documents file name: ";
		cin >> documentsFile;

		// fixme
		cout << "c: " << documentsFile << endl;

		documents.open(documentsFile);

		if (!documents.is_open())
		{
			cout << endl;
			cout << "--- Documents file " << documentsFile << " does not exist. Try Again ---" << endl;
		}
		else
		{
			break;
		}
	}

	// gets stopwords file from user
	while(true)
	{
		cout << endl;
		cout << "Stopwords file name: ";
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

	// fixme
	string testStr = "abdFUCKdef";
	size_t found = testStr.find("FUCK");
	cout << found << endl << endl << endl;

	//

	return 0;
}