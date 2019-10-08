#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "tfidfCol.h"
#include "fileOpener.h"
#include "stopwordOpener.h"
#include "porterStemmer.h"
#include "query.h"

int main() {
	
	vector<tf_idfCol> tfidfColVec;			// vector of all tfidf collection objects
	vector<tf_idfCol> tfidfQueryVec;		// vector for all tfidfs for every query word
	tf_idfCol tfidfClass;					// instance of tfidf collection class

	// runs the stopwords and documents file functions
	vector<string> stopwords_vec = stopwordOpener();
	vector<Document> Documents_vec = fileOpener(stopwords_vec);

//------------------------------------------------------------ Query -------------------------------------------------------------

	vector<string> stoppedQuery;
	vector<string> finalQuery;

        stoppedQuery = query(stopwords_vec);

	for(int i = 0; i < stoppedQuery.size(); i++){
		finalQuery.push_back(portStem(stoppedQuery[i]));
	}

//---------------------------------------------------------- End Query -----------------------------------------------------------

	unsigned int docSize = Documents_vec.size();	// stores the size of the document vector

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

//------------------------------------------------- TFIDF DOC Calculations Start --------------------------------------------------


	for (unsigned int i = 0; i < docSize; i++)
	{
		tfidfClass.FindTF(Documents_vec[i].GetContent());
		tfidfClass.SetDocID(Documents_vec[i].GetID());
		tfidfColVec.push_back(tfidfClass);
	}
	
	// finding the number of documents any given word is used in, used to calculate IDF
	for(unsigned int i = 0; i < docSize; i++)								// loops through all docs
	{
		vector<tf_idf> tempVec = *tfidfColVec[i].GetTFIDFvec();				// temp. vector to hold all tfidf objects for a doc
		
		for(unsigned int k = i; k < docSize; k++)							// loops through every doc again							
		{
			vector<tf_idf> tempVec2 = *tfidfColVec[k].GetTFIDFvec();		// temp. vector to hold all tfidf objects for a doc
													
			// makes sure it doesnt check itself
			if(Documents_vec[i].GetID() != Documents_vec[k].GetID())
			{
				for(unsigned int j = 0; j < tempVec.size(); j++)			// loops through every word in a given doc
				{
					for (unsigned int m = j; m < tempVec2.size(); m++)		// loops through every word in every doc again
					{
						if(tempVec[j].GetName() == tempVec2[m].GetName())
						{
							tempVec[j].SetDocCount();						// increase doc counter for that word
							tfidfColVec[i].SetTFIDFvec(tempVec);			// sets the temporary vector to the real vector
							break;
						}
					}
				}
			}
		}
	}
	
	// calls the IDF and TFIDF functions for all DOCUMENTS
	for (unsigned int i = 0; i < docSize; i++)
	{
		tfidfColVec[i].FindIDF(docSize);
		tfidfColVec[i].FindTFIDF();
	}

//------------------------------------------------- TFIDF Query Calculations Start ---------------------------------------------

	// calls the TF function for the QUERY
	for (unsigned int i = 0; i < docSize; i++)
	{

		tfidfColVec[i].FindQueryTF(finalQuery);	
		tfidfColVec[i].SetDocID(Documents_vec[i].GetID());
		//tfidfQueryVec.push_back(tfidfColVec[i]);
	}
	
	// Finds the IDF for every word in the query for every doc
	for(unsigned int i = 0; i < docSize; i++)								// loops through all docs
	{
		vector<tf_idf> tempVec = *tfidfColVec[i].GetQueryVec();			// temp. vector to hold all tfidf objects for a QUERY
		
		for(unsigned int k = i; k < docSize; k++)							// loops through every doc again							
		{
			vector<tf_idf> tempVec2 = *tfidfColVec[k].GetTFIDFvec();		// temp. vector to hold all tfidf objects for a DOC
													
			// makes sure it doesnt check itself
			if(Documents_vec[i].GetID() != Documents_vec[k].GetID())
			{
				for(unsigned int j = 0; j < tempVec.size(); j++)			// loops through every word in a given QUERY
				{
					for (unsigned int m = j; m < tempVec2.size(); m++)		// loops through every word in every doc 
					{
						if(tempVec[j].GetName() == tempVec2[m].GetName())
						{
							tempVec[j].SetDocCount();
							tfidfColVec[i].SetTFIDFQueryVec(tempVec);		// sets the temporary vector to the real vector
							break;
						}
					}
				}
			}
		}
	}
	
	// Finds the TFIDF for every word in the query for every doc
	for (unsigned int i = 0; i < docSize; i++)
	{
		tfidfColVec[i].FindQueryIDF(docSize);
		tfidfColVec[i].FindQueryTFIDF();
	}
	
//---------------------------------------------------- Printing TFIDF Information -----------------------------------------------
	
	tfidfColVec[0].Print();

//------------------------------------- TFIDF Collection Cosine Similarity Calculation -------------------------------------------

	for(int x=0; x<tfidfColVec.size(); x++){				// loop through TFIDF Collection Vector
		double tempCosSim = 0;
		tempCosSim = tfidfColVec[x].cosineSimilarity();			// calculates cosine similarity between TFIDF of doc and TFIDF of query 
		tfidfColVec[x].SetCosineSimilarity(tempCosSim); 		// set cosine similariry of doc to query in TFIDF obj for doc
	}

//--------------------------------------------- TFIDF Collection Vector Sort -----------------------------------------------------
	
	sort(tfidfColVec.begin(), tfidfColVec.end());				// sorts TFIDF colection vector by cosine similarity

//---------------------------------------------- Final Sorted Output Print -------------------------------------------------------

	cout << endl << "The top most similar documents are:" << endl;

	if(tfidfColVec.size() >= 5){						// for first 5 docs after the sort
		for(int x=4; x>0; x--){
			if(tfidfColVec[x].GetCosineSimilarity() != 0){		// if cosine similarity is not 0
				tfidfColVec[x].printCSInfo();			// print info
			}
		}
	}
	else{
		for(int x=tfidfColVec.size()-1; x>0; x--){			// if less than 5 docs, look at whole vector 
        	        if(tfidfColVec[x].GetCosineSimilarity() != 0){		// if cosine similarity is not 0
                                tfidfColVec[x].printCSInfo();			// print info 
                        }
       		}
	}

	cout << endl << "Complete!" << endl << endl;



	return 0;
}
