#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class tf_idf {
	private:
		int     id;									// unique id number for every word
		string  name;								// the exact name of the unique word
		int     tf;									// the term frequency for a given unique word (a running count)
		double  idf;								// the inverse document frequency for a given unique word
		double  tfidf;								// the term freq. multiplied by the inverse doc. freq.
		int 	docsAppearedIn;						// dynamic list of all the document IDs a given word appears in
		
	public:
		tf_idf();										// constructor
		
		void SetID(int idInput);						// mutator for id
		int GetID();									// accessor for id
		
		void SetName(string nameInput);					// mutator for name
		string GetName() const;							// accessor for name
		
		void SetTF(int tfInput);						// mutator for tf
		int GetTF();									// accessor for tf
		
		void SetIDF(double idfInput);					// mutator for idf
		double GetIDF();								// accessor for idf
		
		void SetTFIDF(double tfidfInput);				// mutator for tfidf
		double GetTFIDF();								// accessor for tfidf
		
		void SetDocsAppearedIn(int idInput);
		int GetDocsAppearedIn();
};

bool operator < (const tf_idf &t1, const tf_idf &t2);	// used to sort the tfidf vector alphabetically
