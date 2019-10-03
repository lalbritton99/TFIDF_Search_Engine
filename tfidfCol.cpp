#include "tfidfCol.h"

tf_idfCol::tf_idfCol(){								// constructer
	docID = "none";
}

void tf_idfCol::SetDocID(string docIdInput){		// mutator for docID
	docID = docIdInput;
}
string tf_idfCol::GetDocID(){						// accessor for docID
		return docID;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------	
void tf_idfCol::FindTF(const vector<string> &AllWords){		// gets the term frequency for every word
	
	int counter = 0;			// used to keep track of if the word has been used before or not, increments the TF by either 0, or 1
	tf_idf tfidfObject; 		// object for the tf_idf class
	bool canSet = 1;			// turns false when a duplicate is found, not allowing it to be added to the vector
	
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
	
	// Sorting tfidf vector alphabetically
	sort(tfidfVec.begin(), tfidfVec.end()); 
	
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void tf_idfCol::FindIDF(unsigned int N){ // FIXME -- Pass in the Document_Vec and then use the size of it to replace the '1'
	
	unsigned int size = tfidfVec.size();	// sets the size of the TFIDF vector
	double tempIDF;							// temporary IDF variable
	
	for(int i = 0; i < size; i++)
	{
		tempIDF = log(N / tfidfVec[i].GetTF());
		tfidfVec[i].SetIDF(tempIDF);
	}
	
	// '1' will become the size of the document vector 
	// "tfidfVec[i].GetDocsAppearedIn()" will need to return the number of docs a certain word appears in
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
void tf_idfCol::FindQueryTF(const vector<string> &AllWords){		// gets the term frequency for every word

// FIXME check if the words in the query are in any of the documents, if so, then increase TF
	
	int counter = 0;			// used to keep track of if the word has been used before or not, increments the TF by either 0, or 1
	tf_idf tfidfObject; 		// object for the tf_idf class
	bool canSet = 1;			// turns false when a duplicate is found, not allowing it to be added to the vector
	
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
			tfidfVecQuery.push_back(tfidfObject);	// copies to the tfidf Query vector
		}
		else 
		{	
			for (unsigned int j = 0; j < tfidfVecQuery.size(); j++)
			{
				if(tfidfVecQuery[j].GetName() == AllWords[i])	// checks if the word has already been added to the tfidf vector
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
				tfidfVecQuery.push_back(tfidfObject);		// copies to the tfidf vector
			}
		}
	} 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void tf_idfCol::FindQueryIDF(){ // FIXME 
	
	unsigned int size = tfidfVecQuery.size();	// sets the size of the TFIDF vector
	double tempIDF;								// temporary IDF variable
	
	for(int i = 0; i < size; i++)
	{
		tempIDF = log(1 / tfidfVecQuery[i].GetTF());
		tfidfVecQuery[i].SetIDF(tempIDF);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void tf_idfCol::FindQueryTFIDF(){
	
	unsigned int size = tfidfVecQuery.size();	// sets the size of the TFIDF vector
	double tempTFIDF;							// temporary TFIDF variable
	
	for(int i = 0; i < size; i++)
	{
		tempTFIDF = tfidfVecQuery[i].GetTF() * tfidfVecQuery[i].GetIDF();
		tfidfVecQuery[i].SetTFIDF(tempTFIDF);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void tf_idfCol::Print(){	// prints all the words		// TODO: check if only first doc
	
	unsigned int size = tfidfVec.size();	// sets the size of the vector
	
	// TODO: Need to add if statment to check if within the first doc that gets entered
	
	// Prints the head of the table
	cout << setw(30) << "NAME";
	cout << setw(15) << "TF";
	cout << setw(15) << "IDF";
	cout << setw(15) << "TF-IDF";
	cout << endl;
	
	// Prints all the rows of the table
	for(unsigned int i = 0; i < size; i++)
	{
		cout << setw(30) << tfidfVec[i].GetName();
		cout << setw(15) << tfidfVec[i].GetTF();
		cout << setw(15) << tfidfVec[i].GetIDF();
		cout << setw(15) << tfidfVec[i].GetTFIDF();
		cout << endl; 
	}
	
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
int tf_idfCol::getTFIDFVecSize(){	// returns size of TFIDF vector
	return tfidfVec.size();
}


tf_idf tf_idfCol::getTFIDFObj(int index){	// returns TFIDF at given index in TFIDF vector
	return tfidfVec[index];
}


