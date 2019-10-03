#include "tfidf.h"

tf_idf::tf_idf(){										// constructor
	id = 0;									
	name = "none";								
	tf = 0;									
	idf = 0;								
	tfidf = 0;	
}

void tf_idf::SetID(int idInput){						// mutator for id
	id = idInput;
}
int tf_idf::GetID(){									// accessor for id
	return id;
}		

void tf_idf::SetName(string nameInput){					// mutator for name
	name = nameInput;
}
string tf_idf::GetName() const{							// accessor for name
	return name;
}
	
void tf_idf::SetTF(int tfInput){						// mutator for tf
	tf += tfInput;
}
int tf_idf::GetTF(){									// accessor for tf
	return tf;
}		

void tf_idf::SetIDF(double idfInput){					// mutator for idf
	idf = idfInput;
}
double tf_idf::GetIDF(){								// accessor for idf
	return idf;
}
		
void tf_idf::SetTFIDF(double tfidfInput){				// mutator for tfidf
	tfidf = tfidfInput;
}
double tf_idf::GetTFIDF(){								// accessor for tfidf
	return tfidf;
}

bool operator < (const tf_idf &t1, const tf_idf &t2)	// used to sort the tfidf vector alphabetically
{
    return t1.GetName() < t2.GetName();
}
