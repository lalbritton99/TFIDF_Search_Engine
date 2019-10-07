#include "tfidf.h"

class tf_idfCol {
	private:
		vector<tf_idf>tfidfVec;						// collection of tf_idf objects
		vector<tf_idf>tfidfVecQuery;				// collection of tf_idf objects for the QUERY
		string docID;								// the id number of the first document that gets read in
		double cosSimilarity;						// holds Cosine Similarity for corresponding doc

	public:
		tf_idfCol();								// constructor
		void SetDocID(string docIdInput);			// mutator for docID
		string GetDocID();							// accessor for docID
		void SetCosineSimilarity(double cosSim);	// mutator for Cosine Similarity
		double GetCosineSimilarity();				// accessor for Cosine Similarity

		void FindTF(const vector<string> &AllWords);	// function to find the tf for every word
		void FindIDF(unsigned int N);					// function to find the idf for every word
		void FindTFIDF();								// function to find the tf-idf for every word
		
		void FindQueryTF(const vector<string> &QueryWords);		// function to find the tf for every word in the query
		void FindQueryIDF(unsigned int N);						// function to find the idf for every word in the query
		void FindQueryTFIDF();									// function to find the tf-idf for every word in the query
		
		void Print();				// prints out the tf, idf, tf-idf, and the word for every unique word in the first document 
		void PrintQuery();			// prints the tfidfQueryVec
		void printCSInfo();			// prints final output. doc similarity info after sort


		double dotProduct(tf_idfCol secondSet);				// Returns the Dot product between the TFIDF values of this set and another passed in. numerator of cosine similarity equation
		double squareProduct(tf_idfCol secondSet);			// Returns the product of the square roots of the sums of the squares of the TFIDF values of this set and another passed in. denomonator of cosine similarity equation
		double cosineSimilarity(tf_idfCol secondSet);		// Returns the cosine similarity between the TFIDF collection obj and another passed in

		int getTFIDFVecSize();				// returns size of TFIDF vector
		tf_idf getTFIDFObj(int index);		// returns TFIDF at given index in TFIDF vector. Accessor function
	
		void SetTFIDFvec(vector<tf_idf> &vecInput);			// takes in a tf_idf vector, and saves it to the tfidfVec
		vector<tf_idf>*GetTFIDFvec();						// returns a pointer to the tfidfVec
		void SetTFIDFQueryVec(vector<tf_idf> &vecInput);	// takes in a tf_idf vector, and saves it to the tfidfVecQuery
		vector<tf_idf>* GetQueryVec();						// returns a pointer to the tfidfVecQuery
		
		bool operator < (tf_idfCol const &T){ 				// overload < operator
			return cosSimilarity < T.cosSimilarity;
		}
		
		bool operator > (tf_idfCol const &T){               // overload > operator
            return cosSimilarity > T.cosSimilarity;
        }

};

