#include <string>
#include <vector>
using namespace std;

class tf_idf {
	private:
		int         id;									// unique id number for every word
		string      name;								// the exact name of the unique word
		int         tf;									// the term frequency for a given unique word (a running count)
		double      idf;								// the inverse document frequency for a given unique word
		double      tfidf;								// the term freq. multiplied by the inverse doc. freq.
		vector<int> docsAppearedIn;						// dynamic list of all the documents a given word appears in
		
	public:
		tf_idf();										// constructor
		
		void SetID(int idInput);						// mutator for id
		int GetID();									// accessor for id
		
		void SetName(string nameInput);					// mutator for name
		string GetName();								// accessor for name
		
		void SetTF();									// mutator for tf
		int GetTF();									// accessor for tf
		
		void SetIDF(double idfInput);					// mutator for idf
		double GetIDF();								// accessor for idf
		
		void SetTFIDF(double tfidfInput);				// mutator for tfidf
		double GetTFIDF();								// accessor for tfidf
};