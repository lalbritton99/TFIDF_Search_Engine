#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "tfidfCol.h"
//#include "document.h"
//#include "documentCol.h"

int main() {
	
	tf_idfCol tfidfClass;	// instance of the tfidf collection class
	
	tfidfClass.FindTF();	// TEMPORARY FOR TESTING
	tfidfClass.FindIDF();	// TEMPORARY FOR TESTING
	tfidfClass.FindTFIDF();	// TEMPORARY FOR TESTING
	tfidfClass.Print();		// TEMPORARY FOR TESTING
		

	string documentsFile = "";
	string stopwordsFile = "";
	ifstream documents;
	ifstream stopwords;


	return 0;
}
