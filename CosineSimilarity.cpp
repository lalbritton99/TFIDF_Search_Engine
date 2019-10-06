#include "tfidfCol.h"

//Function: Returns the dot product between the TFIDF values of each word in the current TFIDF obj and a passed one. Numerator in cosine similarity equation.
double tf_idfCol::dotProduct(tf_idfCol secondSet) { //declaration located in tfidfCol.h
	
	double dotProd = 0;										// Var to hold and return Dot Product
	double thisTFIDF = 0;
	double passedTFIDF = 0;

	for(int x=0; x < this->getTFIDFVecSize(); x++) {						// loops through current TFIDF vec
		for(int y=0; y < secondSet.getTFIDFVecSize(); y++) { 					// loops through passed TFIDF vec
		
		//---------------------------------------------------------------------------------------------------------------------
		//Testing FIXME
		//
			//cout << "Query Word: " << (this->getTFIDFObj(x)).GetName() << endl;
			//cout << "Doc Word: " << (secondSet.getTFIDFObj(y)).GetName() << endl;
			//cout << "Query Length: " << this->getTFIDFVecSize() << endl;
			//cout << "Doc Length: " << secondSet.getTFIDFVecSize() << endl;

		//---------------------------------------------------------------------------------------------------------------------
			if((this->getTFIDFObj(x)).GetName() == (secondSet.getTFIDFObj(y)).GetName()){	// if words are the same
				
				//cout << "---------------------------------" << endl; //FIXME

				thisTFIDF = (this->getTFIDFObj(x)).GetTFIDF();				// double TFIDF from currect obj
				passedTFIDF = (secondSet.getTFIDFObj(y)).GetTFIDF();			// double TFIDF from passed obj
				
				dotProd += thisTFIDF * passedTFIDF;					// Add product of TFIDFs of similar words to sum
			}
		}
	}
	
	return dotProd;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

//Function: Returns the product of the square roots of the sums of the squares of the TFIDF values of each word in the current TFIDF obj and a passed one. Denomonator in cosine similarity equation.
double tf_idfCol::squareProduct(tf_idfCol secondSet) { //declaration located in tfidfCol.h
	double thisSum = 0;										// sum of squared TFIDFs in current obj
	double passedSum = 0;										// sum of squared TFIDFs in passed obj
	double squareProd = 0;										// result to be returned
	
	for(int x=0; x < this->getTFIDFVecSize(); x++){ 						// loop through all TFIDFs in current obj
		double tempTFIDF = (this->getTFIDFObj(x)).GetTFIDF();					// var holding TFIDF
		thisSum += pow(tempTFIDF,2);								// adds square of TFIDF to sum
	}
	
	for(int y=0; y < secondSet.getTFIDFVecSize(); y++){ 						// loop through all TFIDFs in passed obj
		double tempTFIDF = (secondSet.getTFIDFObj(y)).GetTFIDF();		 		// var holding TFIDF
		passedSum += pow(tempTFIDF,2);
	}
	
	squareProd = sqrt(thisSum) * sqrt(passedSum); 							// product of both square roots of sums
	
	return squareProd;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

//Function: Returns the cosine similarity between the current TFIDF obj and a passed one.
double tf_idfCol::cosineSimilarity(tf_idfCol secondSet) {
	double cosSim = 0;
	
	cosSim = dotProduct(secondSet) / squareProduct(secondSet);					// divide numerator of cosine similarity equation by denomonator

	return cosSim;
}
