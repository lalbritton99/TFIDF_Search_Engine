#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "tfidfCol.h"
#include "fileOpener.h"
#include "stopwordOpener.h"
#include "porterStemmer.h"

int main() {
// fixme - testing parts 1 and 2
/*	
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
*/
	// * MARCUS'S FEATURES *
	// runs the stopwords and documents file functions
	vector<string> stopwords_vec = stopwordOpener();
	vector<Document> Documents_vec = fileOpener(stopwords_vec);

	// outputs the header
	cout << "ID:\t" << Documents_vec[0].GetID() << endl;
	cout << "title:\t" << Documents_vec[0].GetTitle() << endl;
	cout << "author:\t" << Documents_vec[0].GetAuthor() << endl;
	cout << endl;

	// outputs the abstract (punctuation intact)
	cout << Documents_vec[0].GetAbstract() << endl;
	cout << endl;

	// outputs the number of stopwords
	cout << "There are currently " << stopwords_vec.size() << " known stopwords." << endl;
	cout << endl;

	// outputs the abstract without puntuation, "'s", stopwords, ...
	vector<string> abstract_vec = Documents_vec[0].GetContent();
	for (int i = 0; i < abstract_vec.size(); ++i)
		{
			cout << abstract_vec[i] << " ";
		}
	cout << endl;
	// outputs the number of unique words
	vector<string> unique_vector;
	for (int i = 0; i < abstract_vec.size(); ++i)
	{
		bool found = false;
		for (int j = 0; j < unique_vector.size(); ++j)
		{
			if (abstract_vec[i] == unique_vector[j])
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			unique_vector.push_back(abstract_vec[i]);
		}
	}
	cout << "number of unique unstemmed words:\t" << unique_vector.size() << endl;
	cout << endl << endl << endl;
	
	vector<string> stemmedVector;
	for(int i = 0; i < abstract_vec.size(); i++) {
		stemmedVector.push_back(portStem(abstract_vec[i]));
		cout << stemmedVector[i] << " ";
	}
	unique_vector.clear();
        for (int i = 0; i < stemmedVector.size(); ++i)
        {
                bool found = false;
                for (int j = 0; j < unique_vector.size(); ++j)
                {
                        if (stemmedVector[i] == unique_vector[j])
                        {
                                found = true;
                                break;
                        }
                }
                if (!found)
                {
                        unique_vector.push_back(stemmedVector[i]);
                }
        }

	cout << "\nnumber of unique stemmed words:    " << unique_vector.size() << endl;
	vector<string> stemmingVector;
	vector<string> tempVector;
	for(int i = 0; i < Documents_vec.size(); i++){
		tempVector.clear();
		stemmingVector = Documents_vec[i].GetContent();
		for(int j = 0; j < stemmingVector.size(); j++) {
        	        tempVector.push_back(portStem(stemmingVector[j]));
			cout << tempVector[j] << " ";
        	}
		Documents_vec[i].SetContent(tempVector);
		cout << endl << endl << endl;
	}

	
	// NOTE: Documents_vec is a vector of all documents from any given file
	// fixme - making sure Documents_vec is fully loaded every time
	cout << Documents_vec.size() << endl;
	// * END MARCUS'S FEATURES *

	return 0;
}
