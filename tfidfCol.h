#include "tfidf.h"

class tf_idfCol {
	private:
		vector<tf_idf>tfidfVec;							// collection of tf_idf objects
		int firstDocID;								// the id number of the first document that gets read in // maybe dont need???
	
	public:
		tf_idfCol();								// constructor
		void SetFirstDocID(int firstDocIdInput);				// mutator for firstDocId
		int GetFirstDocID();							// accessor for firstDocID
	
		void FindTF();								// function to find the tf for every word
		void FindIDF();								// function to find the idf for every word
		void FindTFIDF();							// function to find the tf-idf for every word
		void Print();								// prints out the tf, idf, tf-idf, and the word for every unique word in the first document 
		
		double dotProduct(tf_idfCol secondSet);					// returns the Dot product between the TFIDF values of this set and another passed in. numerator of cosine similarity equation
		double squareProduct(tf_idfCol secondSet);				// Returns the product of the square roots of the sums of the squares of the TFIDF values of this set and another passed in. denomonator of cosine similarity equation

		int getTFIDFVecSize();							// returns size of TFIDF vector
		tf_idf getTFIDF(int index);						// returns TFIDF at given index in TFIDF vector
	
};

