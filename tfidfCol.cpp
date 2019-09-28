#include "tfidfCol.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

tf_idfCol::tf_idfCol(){									// constructer
	firstDocID = 0;
}

void tf_idfCol::SetFirstDocID(int firstDocIdInput){		// mutator for firstDocID
	firstDocID = firstDocIdInput;
}
int tf_idfCol::GetFirstDocID(){							// accessor for firstDocID
		return firstDocID;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------	
void tf_idfCol::FindTF(){		// gets the term frequency for every word
	
	int counter = 0;			// used to keep track of if the word has been used before or not, increments the TF by either 0, or 1
	tf_idf tfidfObject; 		// object for the tf_idf class
	bool canSet = 1;			// turns false when a duplicate is found, not allowing it to be added to the vector
	
	int numWords;				// TEMPORARY
	string word;				// TEMPORARY
	vector<string>AllWords;		// TEMPORARY
	
	// Getting the temporary vector
	cout << "Enter the number of words to enter: ";
	cin >> numWords;
	for(int i = 0; i < numWords; i++)
	{
		cout << "Enter word " << i+1 << ": ";
		cin >> word;
		AllWords.push_back(word);
	}
	
	// Checking every word, copying it into new vector, and increasing term frequency when neccessary
	for(unsigned int i = 0; i < AllWords.size(); i++) 
	{
		counter = 0;		// increments TF by 0
		canSet = 1;			// words can be added to tfidf vector
		
		if(i==0)			// Takes care of very first word
		{
			counter = 1;
			tfidfObject.SetName(AllWords[i]);		// sets the name of the word
			tfidfObject.SetTF(counter);				// sets the TF
			tfidfVec.push_back(tfidfObject);		// copies to the tfidf vector
		}
		else 
		{	
			for (unsigned int j = 0; j < tfidfVec.size(); j++)
			{
				if(tfidfVec[j].GetName() == AllWords[i])	// checks if the word has already been added to the tfidf vector
				{
					counter = 1;
					canSet = 0;								// duplicate words do not get added to the vector
					tfidfVec[j].SetTF(counter);				// increases TF for the re-used words
				}
			}
			
			if(canSet)		// only allows non-duplicate words to be added to vector
			{
				counter = 0;
				tfidfObject.SetName(AllWords[i]);		// sets the name of the word
				tfidfObject.SetTF(counter);				// sets the TF for the word
				tfidfVec.push_back(tfidfObject);		// copies to the tfidf vector
			}
		}
	}
	
	// Sorting tfidf vector 
	sort(tfidfVec.begin(), tfidfVec.end()); 
	
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void tf_idfCol::FindIDF(){
	
}
void tf_idfCol::FindTFIDF(){
	// loop through all parts of the tfidf Vector
	// for every word, multiply the TF by the IDF
	// store in the TFIDF for that instance of the vector
}
void tf_idfCol::Print(){	// prints all the words		// TODO: check if only first doc
	
	unsigned int size = tfidfVec.size();	// sets the size of the vector
	
	// Need to add if statment to check if within the first doc that gets entered
	
	// Prints the head of the table
	cout << setw(10) << "NAME";
	cout << setw(10) << "TF";
	cout << setw(10) << "IDF";
	cout << setw(10) << "TF-IDF";
	cout << endl;
	
	// Prints all the rows of the table
	for(unsigned int i = 0; i < size; i++)
	{
		cout << setw(10) << tfidfVec[i].GetName();
		cout << setw(10) << tfidfVec[i].GetTF();
		cout << setw(10) << tfidfVec[i].GetIDF();
		cout << setw(10) << tfidfVec[i].GetTFIDF();
		cout << endl; 
	}
	
}
