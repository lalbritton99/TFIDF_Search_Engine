#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "tfidfCol.h"
//#include "document.h"
//#include "documentCol.h"

int main() {
	
	tf_idfCol tfidfClass;	// instance of the tfidf collection class
	
//- LINES 15 - 34 ARE TEMPORARY. Using them for testing. Can be commented out if you need. -Austin ------------------------------
	int numWords; 
	string word;
	vector<string>AllWords;	
	
	// Getting the temporary vector
	cout << "Enter the number of words to enter: ";
	cin >> numWords;
	for(int i = 0; i < numWords; i++)
	{
		cout << "Enter word " << i+1 << ": ";
		cin >> word;
		AllWords.push_back(word);
	}
	
	tfidfClass.FindTF(AllWords);	// TEMPORARY FOR TESTING
	tfidfClass.FindIDF();			// TEMPORARY FOR TESTING
	tfidfClass.FindTFIDF();			// TEMPORARY FOR TESTING
	tfidfClass.Print();				// TEMPORARY FOR TESTING
//-------------------------------------------------------------------------------------------------------------------------------

	string documentsFile = "";
	string stopwordsFile = "";
	ifstream documents;
	ifstream stopwords;


	return 0;
}
