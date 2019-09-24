#include "tfidfCol.h"
#include <string>
#include <vector>
#include <iostream>

tf_idfCol::tf_idfCol(){							// constructer
	firstDocID = 0;
}

void tf_idfCol::SetFirstDocID(int firstDocIdInput){
	firstDocID = firstDocIdInput;
}
int tf_idfCol::GetFirstDocID(){
		return firstDocID;
}
	
void tf_idfCol::FindTF(){
	
	tf_idf tfidfObject; 
	int numWords;
	string word;
	
	vector<string>AllWords;
	
	cout << "Enter the number of words to enter: ";
	cin >> numWords;
	
	for(int i = 0; i < numWords; i++){
		
		cout << "Enter word " << i+1 << ": ";
		cin >> word;
		AllWords.push_back(word);
	}
	
	for(unsigned int i = 0; i < AllWords.size(); i++) {
		if(i==0)
		{
			tfidfObject.SetName(AllWords[i]);
			tfidfObject.SetTF();
			
			tfidfVec.push_back(tfidfObject);
		}
		else 
		{	
			for (unsigned int j = 0; j < tfidfVec.size(); j++)
			{
				if(tfidfVec[j].GetName() == AllWords[i])
				{
					tfidfObject.SetTF();
					tfidfVec.push_back(tfidfObject);
				}
				else
				{
					tfidfObject.SetName(AllWords[i]);
					tfidfObject.SetTF();
			
					tfidfVec.push_back(tfidfObject);
				}
			}
		}
	}
	
}
void tf_idfCol::FindIDF(){
	
}
void tf_idfCol::FindTFIDF(){
	
}
void tf_idfCol::Print(){
}