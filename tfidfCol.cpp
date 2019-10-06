#include "tfidfCol.h"

tf_idfCol::tf_idfCol(){								// constructer
	docID = "none";
	cosSimilarity = 0;
}

void tf_idfCol::SetDocID(string docIdInput){		// mutator for docID
	docID = docIdInput;
}
string tf_idfCol::GetDocID(){						// accessor for docID
		return docID;
}

void tf_idfCol::SetCosineSimilarity(double cosSim){                                // mutator for Cosine Similarity
	cosSimilarity = cosSim;
}

double tf_idfCol::GetCosineSimilarity(){						// accessor for Cosine Similarity
	return cosSimilarity;
}
void tf_idfCol::SetTFIDFvec(vector<tf_idf> &vecInput){
	tfidfVec = vecInput;
}
vector<tf_idf>* tf_idfCol::GetTFIDFvec(){
	vector<tf_idf>* tfidfPointer = &tfidfVec;
	return tfidfPointer;
}
void tf_idfCol::SetTFIDFQueryVec(vector<tf_idf> &vecInput)
{
	tfidfVecQuery = vecInput;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------	
void tf_idfCol::FindTF(const vector<string> &AllWords){		// gets the term frequency for every word
	
	int counter = 0;			// used to keep track of if the word has been used before or not, increments the TF by either 0, or 1
	tf_idf tfidfObject; 		// object for the tf_idf class
	bool canSet = 1;			// turns false when a duplicate is found, not allowing it to be added to the vector
	
	tfidfVec.clear();			// clears the vector so it is empty at the start of every doc
	
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
void tf_idfCol::FindIDF(unsigned int N){ 
	
	unsigned int size = tfidfVec.size();	// sets the size of the TFIDF vector
	double tempIDF = 0;						// temporary IDF variable
	
	for(int i = 0; i < size; i++)
	{
		//cout << tfidfVec[i].GetDocCount() << endl;
		if(tfidfVec[i].GetDocCount() == 0)
		{
			tempIDF = 0;
		}
		else
		{
			tempIDF = log(N / tfidfVec[i].GetDocCount());
		}
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
void tf_idfCol::FindQueryTF(const vector<string> &QueryWords){		// gets the term frequency for every word in the query

	tf_idf tfidfObject; 		// object for the tf_idf class
	int count = 0;
	
	tfidfVecQuery.clear();		// clears the vector so it is empty at the start of every doc
	
	// Checking every word, copying it into new query vector, and setting term frequency
	for(unsigned int i = 0; i < QueryWords.size(); i++) 
	{
		for (unsigned int j = 0; j < tfidfVec.size(); j++)
		{
			count = 0;
			if(tfidfVec[j].GetName() == QueryWords[i])	// checks if the word in the query is in the tfidf vector
			{
				// adds to the query vector for each doc if the word is used within the doc
				tfidfObject.SetName(QueryWords[i]);
				tfidfObject.SetTF(tfidfVec[j].GetTF());
				tfidfVecQuery.push_back(tfidfObject);
				break;
				
			}
			//else
			//{
			//	tfidfObject.SetName(QueryWords[i]);
			//	tfidfObject.SetTF(0);
			//	tfidfVecQuery.push_back(tfidfObject);
			//}
		}
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void tf_idfCol::FindQueryIDF(unsigned int N){  
	
	unsigned int size = tfidfVecQuery.size();	// sets the size of the TFIDF vector
	double tempIDF;								// temporary IDF variable
	
	for(int i = 0; i < size; i++)
	{
		if(tfidfVecQuery[i].GetDocCount() == 0)
		{
			tempIDF = 0;
		}
		else
		{
			tempIDF = log(N / tfidfVecQuery[i].GetDocCount());
		}
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
void tf_idfCol::Print(){	// prints all the words		
	
	unsigned int size = tfidfVec.size();	// sets the size of the vector
	
	
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
		cout << setw(15) << setprecision(5) << fixed << tfidfVec[i].GetIDF();
		cout << setw(15) << setprecision(5) << fixed << tfidfVec[i].GetTFIDF();
		cout << endl; 
	}
	
}
//---------------------------------------------------------------
void tf_idfCol::PrintQuery(){	// prints all the words		
	
	unsigned int size = tfidfVecQuery.size();	// sets the size of the vector
	
	
	// Prints the head of the table
	cout << setw(30) << "NAME";
	cout << setw(15) << "TF";
	cout << setw(15) << "IDF";
	cout << setw(15) << "TF-IDF";
	cout << endl;
	
	// Prints all the rows of the table
	for(unsigned int i = 0; i < size; i++)
	{
		cout << setw(30) << tfidfVecQuery[i].GetName();
		cout << setw(15) << tfidfVecQuery[i].GetTF();
		cout << setw(15) << setprecision(5) << fixed << tfidfVecQuery[i].GetIDF();
		cout << setw(15) << setprecision(5) << fixed << tfidfVecQuery[i].GetTFIDF();
		cout << endl; 
	}
	
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------
void tf_idfCol::printCSInfo(){			// prints final output. doc similarity info after sort
        cout << "Doc #: " << docID << "\tCos Sim: " << setprecision(5) << fixed << cosSimilarity << endl;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
int tf_idfCol::getTFIDFVecSize(){	// returns size of TFIDF vector
	return tfidfVec.size();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
tf_idf tf_idfCol::getTFIDFObj(int index){	// returns TFIDF at given index in TFIDF vector
	return tfidfVec[index];
}


