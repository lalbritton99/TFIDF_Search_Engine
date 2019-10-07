#include "tfidfCol.h"

//Function: Returns the dot product between the TFIDF values of each word in the doc and query. Numerator in cosine similarity equation.
double tf_idfCol::dotProduct() { //declaration located in tfidfCol.h
	
	double dotProd = 0;										// Var to hold and return Dot Product
	double docTFIDF = 0;										// var to hold doc TFIDF
	double queryTFIDF = 0;										// var to hold query TFIDF

	for(int x=0; x < this->getDocTFIDFVecSize(); x++) {						// loops through doc TFIDF vec
		for(int y=0; y < this->getQueryTFIDFVecSize(); y++) { 					// loops through query TFIDF vec
		
		//---------------------------------------------------------------------------------------------------------------------
		//Testing FIXME
		//
			//cout << "Query Word: " << (this->getTFIDFObj(x)).GetName() << endl;
			//cout << "Doc Word: " << (secondSet.getTFIDFObj(y)).GetName() << endl;
			//cout << "Query Length: " << this->getTFIDFVecSize() << endl;
			//cout << "Doc Length: " << secondSet.getTFIDFVecSize() << endl;

		//--------------------------------------------------------------------------------------------------------------------- 
			if((this->getDocTFIDFObj(x)).GetName() == (this->getQueryTFIDFObj(y)).GetName()){	// if words are the same
				
				//cout << "---------------------------------" << endl; //FIXME

				docTFIDF = (this->getDocTFIDFObj(x)).GetTFIDF();				// double TFIDF from currect obj
				queryTFIDF = (this->getQueryTFIDFObj(y)).GetTFIDF();				// double TFIDF from passed obj
				
				dotProd += docTFIDF * queryTFIDF;						// Add product of TFIDFs of similar words to sum
			}
		}
	}
	
	return dotProd;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

//Function: Returns the product of the square roots of the sums of the squares of the TFIDF values of each word in the doc and query. Denomonator in cosine similarity equation.
double tf_idfCol::squareProduct() { //declaration located in tfidfCol.h
	double docSum = 0;										// sum of squared TFIDFs in doc
	double querySum = 0;										// sum of squared TFIDFs in query
	double squareProd = 0;										// result to be returned
	
	for(int x=0; x < this->getDocTFIDFVecSize(); x++){ 						// loop through all TFIDFs in doc
		double tempTFIDF = (this->getDocTFIDFObj(x)).GetTFIDF();				// var holding TFIDF
		docSum += pow(tempTFIDF,2);								// adds square of TFIDF to sum
	}
	
	for(int y=0; y < this->getQueryTFIDFVecSize(); y++){ 						// loop through all TFIDFs in query
		double tempTFIDF = (this->getQueryTFIDFObj(y)).GetTFIDF();		 		// var holding TFIDF
		docSum += pow(tempTFIDF,2);
	}
	
	squareProd = sqrt(docSum) * sqrt(querySum); 							// product of both square roots of sums

	return squareProd;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

//Function: Returns the cosine similarity between the doc and query.
double tf_idfCol::cosineSimilarity() {
	double cosSim = 0;
	
	cosSim = dotProduct() / squareProduct();					// divide numerator of cosine similarity equation by denomonator

	return cosSim;
}
