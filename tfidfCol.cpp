#include "tfidfCol.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

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
	int tempID = 1;					//TEMPORARY
	
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
			tfidfObject.SetDocsAppearedIn(1);		// TODO: ADD TO DOCSAPPEAREDIN - check for multiple IDs
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
					tfidfVec[j].SetDocsAppearedIn(++counter);
					//TODO: add to docsAppearedIn - check for multiple IDs
				}
			}
			
			if(canSet)		// only allows non-duplicate words to be added to vector
			{
				counter = 0;
				tfidfObject.SetName(AllWords[i]);		// sets the name of the word
				tfidfObject.SetTF(counter);				// sets the TF for the word
				tfidfObject.SetDocsAppearedIn(1);		// TODO: ADD TO DOCSAPPEAREDIN - check for multiple IDs
				tfidfVec.push_back(tfidfObject);		// copies to the tfidf vector
			}
		}
	}
	
	// Sorting tfidf vector alphabetically
	sort(tfidfVec.begin(), tfidfVec.end()); 
	
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void tf_idfCol::FindIDF(){
	
	unsigned int size = tfidfVec.size();	// sets the size of the TFIDF vector
	double tempIDF;							// temporary IDF variable
	
	for(int i = 0; i < size; i++)
	{
		tempIDF = log(3 / tfidfVec[i].GetDocsAppearedIn());
		tfidfVec[i].SetIDF(tempIDF);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void tf_idfCol::FindTFIDF(){
	
	unsigned int size = tfidfVec.size();	// sets the size of the TFIDF vector
	double tempTFIDF;						// temporary TFIDF variable
	
	for(int i = 0; i < size; i++)
	{
		tempTFIDF = tfidfVec[i].GetTF() * tfidfVec[i].GetIDF();
		tfidfVec[i].SetTFIDF(tempTFIDF);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------------------------------------------------------
int tf_idfCol::getTFIDFVecSize(){	// returns size of TFIDF vector
	return tfidfVec.size();
}

tf_idf tf_idfCol::getTFIDF(int index){	// returns TFIDF at given index in TFIDF vector
	return tfidfVec[index];
}


