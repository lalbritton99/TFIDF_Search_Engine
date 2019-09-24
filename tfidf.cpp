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
string tf_idf::GetName(){								// accessor for name
	return name;
}
	
void tf_idf::SetTF(){									// mutator for tf
	tf++;
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