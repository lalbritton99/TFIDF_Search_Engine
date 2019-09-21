#include "porterStemmer.h"

using namespace std;

string portStem(string word){
	int m;
	m = getM(word);
	cout << m << endl;
	if(word.find("sses") != -1){
		word.replace(word.find("sses"), 4, "ss" );
	}
	return word;
}


int getM(string word){
	int m = 0;
	for(int i = 0; i < word.size(); i++){
		if((word.at(i) == 'a') || (word.at(i) == 'A') || (word.at(i) == 'e') || (word.at(i) == 'E') || (word.at(i) == 'i') || (word.at(i) == 'I') || (word.at(i) == 'o') || (word.at(i) == 'O') || (word.at(i) == 'u') || (word.at(i) == 'U'))
		{
			if(i != (word.size() - 1)){
				if((word.at(i+1) != 'a') && (word.at(i+1) != 'A') && (word.at(i+1) != 'e') && (word.at(i+1) != 'E') && (word.at(i+1) != 'i') && (word.at(i+1) != 'I') && (word.at(i+1) != 'o') && (word.at(i+1) != 'O') && (word.at(i+1) != 'u') && (word.at(i+1) != 'U')){
				m++;
				}
			}
		}
		else if((word.at(i) == 'y') || (word.at(i) == 'Y')){
			if(i != 0){
				if((word.at(i-1) != 'a') && (word.at(i-1) != 'A') && (word.at(i-1) != 'e') && (word.at(i-1) != 'E') && (word.at(i-1) != 'i') && (word.at(i-1) != 'I') && (word.at(i-1) != 'o') && (word.at(i-1) != 'O') && (word.at(i-1) != 'u') && (word.at(i-1) != 'U')){
					if(i != (word.size() - 1)){
						if((word.at(i+1) != 'a') && (word.at(i+1) != 'A') && (word.at(i+1) != 'e') && (word.at(i+1) != 'E') && (word.at(i+1) != 'i') && (word.at(i+1) != 'I') && (word.at(i+1) != 'o') && (word.at(i+1) != 'O') && (word.at(i+1) != 'u') && (word.at(i+1) != 'U')){

							m++;
						}
					}
				}
			}
		}
	}
	return m;
}


