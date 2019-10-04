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
	
	vector<tf_idfCol> tfidfColVec;			// vector of all tfidf collection objects
	tf_idfCol tfidfClass;
// fixme - testing parts 1 and 2

	// runs the stopwords and documents file functions
	vector<string> stopwords_vec = stopwordOpener();
	vector<Document> Documents_vec = fileOpener(stopwords_vec);

// !!!!!!! JEREMY RUN PORTER STEMMER HERE !!!!!!!

	// calls all functions for the TFIDF calculations
	
//	loop through document class, for each doc, pass in the porter-stemmed abstract, add tfidfClass to tfidfColVec

	unsigned int docSize = Documents_vec.size();
	
	for (unsigned int i = 0; i < docSize; i++)
	{
		tfidfClass.FindTF(Documents_vec[i].GetContent());	// FIXME: pass in porter stemmed vector instead
		tfidfClass.FindIDF(docSize);			
		tfidfClass.FindTFIDF();
		tfidfClass.SetDocID(Documents_vec[i].GetID());
		
		tfidfColVec.push_back(tfidfClass);
	}
			

// !!!!!!! JEREMY RUN QUERY STUFF HERE !!!!!!!


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


//----------------------------------------------- Porter Stemmer Output Calculation ----------------------------------------------
	
	vector<string> stemmedVector;
	for(int i = 0; i < abstract_vec.size(); i++) {
		stemmedVector.push_back(portStem(abstract_vec[i]));
		cout << stemmedVector[i] << " ";
	}

//-------------------------------------------- Counting Number of Unique Stemmed Words  ------------------------------------------

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


//-------------------------------------------- Porter Stemming For All Documents -------------------------------------------------	

	vector<string> stemmingVector;
	vector<string> tempVector;
	for(int i = 0; i < Documents_vec.size(); i++){
		tempVector.clear();
		stemmingVector = Documents_vec[i].GetContent();
		for(int j = 0; j < stemmingVector.size(); j++) {
        	        tempVector.push_back(portStem(stemmingVector[j]));
        	}
		Documents_vec[i].SetContent(tempVector);
		cout << endl;
	}

//--------------------------------------------------- End Porter Stemming --------------------------------------------------------


	
	// NOTE: Documents_vec is a vector of all documents from any given file
	
	
	// prints tfidf information for first doc
	tfidfColVec[0].Print();


	
//------------------------------------- TFIDF Collection Cosine Similarity Calculation -------------------------------------------

	for(int x=0; x<tfidfColVec.size(); x++){				// loop through TFIDF Collection Vector
		double tempCosSim = 0;
		//tempCosSim = tfidfQueryVec[x].cosineSimilarity(tfidfColVec[x]);	//FIXME  calculates cosine similarity between TFIDF of doc and TFIDF of correlated query TFIDF
		tfidfColVec[x].SetCosineSimilarity(tempCosSim); 			// set cosine similariry of doc to query in TFIDF obj for doc
	}

//--------------------------------------------- TFIDF Collection Vector Sort -----------------------------------------------------

	sort(tfidfColVec.begin(), tfidfColVec.end());				// sorts TFIDF colection vector by cosine similarity

//---------------------------------------------- Final Sorted Output Print -------------------------------------------------------

	cout << endl << "The top most similar documents are:" << endl;

	if(tfidfColVec.size() >= 5){						// for first 5 docs after the sort
		for(int x=0; x<5; x++){
			if(tfidfColVec[x].GetCosineSimilarity() != 0){		// if cosine similarity is not 0
				tfidfColVec[x].printCSInfo();			// print info
			}
		}
	}
	else{
		for(int x=0; x<tfidfColVec.size(); x++){			// if less than 5 docs, look at whole vector 
        	        if(tfidfColVec[x].GetCosineSimilarity() != 0){		// if cosine similarity is not 0
                                tfidfColVec[x].printCSInfo();			// print info 
                        }
       		}
	}

	cout << endl << "Complete!" << endl << endl;



	return 0;
}
