#include "porterStemmer.h"

using namespace std;

string portStem(string word){
	int m; //Integer for measure of each word
	int step1B = 0;
	m = getM(word); //Calculate measure
	cout << m << endl; //FIXME
	

	//Step 1a for porterstemming
	if(word.find("sses") != -1){
		word.replace(word.find("sses"), 4, "ss" );
	}
	else if(word.find("ies") != -1){
		word.replace(word.find("ies"), 3, "i");
	}
	else if (word.find("ss") != -1){
		word.replace(word.find("ss"), 2, "ss" );
	}
	else if ((word.at(word.size()-1)) == 's'){
		word.replace(word.size()-1, 1, "");
	}

	//Step 1b
	if((m> 0) && (word.find("eed") != -1)){
		if(word.size() > 5){
			word.replace(word.substr(0, word.size()-3).find("eed"), 3, "ee");
		}
	}
	else if((hasVowel(word.substr(0, word.size()-2))) && (word.find("ed") != -1)){
		word.replace(word.find("ed"), 2, "");
		step1B = 1;
	}
	else if((hasVowel(word.substr(0, word.size()-3))) && (word.find("ing") != -1)){
                word.replace(word.find("ing"), 3, "");
		step1B = 1;
        }
	if(step1B == 1){
		if(word.substr(word.size()-2, 2) == "at"){
			word += "e";
		}
		else if(word.substr(word.size()-2, 2) == "bl"){
                        word += "e";
                }
		else if(word.substr(word.size()-2, 2) == "iz"){
                        word += "e";
                }
		else if((word.at(word.size()-2) == word.at(word.size()-1)) && (word.at(word.size()-2) != 's') && (word.at(word.size()-2) != 'l') && (word.at(word.size()-2) != 'z')){
			word = word.substr(0, word.size() -1);
		}
		else if((!(isVowel(word.at(word.size()-3)))) && (isVowel(word.at(word.size()-2))) && (!(isVowel(word.at(word.size()-1)))) && (((word.at(word.size()-1) != 'w') && (word.at(word.size()-1) != 'x') && (word.at(word.size()-1) != 'y')))){
			m = getM(word);
			if(m == 1){
				word += "e";
			}
		}
	}
	if((hasVowel(word.substr(0, word.size()-1))) && (word.at(word.size()-1) == 'y')){
		word.replace(word.find_last_of("y"), 1, "i");
	}



	return word;
}


int getM(string word){
	int m = 0;
	for(int i = 0; i < word.size(); i++){
		if((isVowel(word.at(i))))
		{
			if(i != (word.size() - 1)){
				if((!(isVowel(word.at(i+1))))){
					m++;
				}
			}
		}
		else if((word.at(i) == 'y') || (word.at(i) == 'Y')){
			if(i != 0){
				if((!(isVowel(word.at(i-1))))){
					if(i != (word.size() - 1)){
						if((!(isVowel(word.at(i+1))))){

							m++;
						}
					}
				}
			}
		}
	}
	return m;
}

int hasVowel(string word){
	for(int i = 0; i < word.size(); i++){
		if((isVowel(word.at(i))))
                {
			return true;
		}
	}
	return false;
}

bool isVowel(char let){
	if((let == 'a') || (let == 'A') || (let == 'e') || (let == 'E') || (let == 'i') || (let == 'I') || (let == 'o') || (let == 'O') || (let == 'u') || (let == 'U'))
	{
		return true;
	}
	else {
		return false;
	}
}


