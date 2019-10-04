#include "porterStemmer.h"
using namespace std;

string portStem(string word){
	int m; //Integer for measure of each word
	int step1B = 0;
	m = getM(word); //Calculate measure

	//Step 1a for porterstemming
	if(word.size() > 4 && word.find("sses", word.size()-4) != string::npos){
		word.replace(word.find("sses"), 4, "ss" );
	}
	else if(word.size() > 3 &&word.find("ies", word.size()-3) != string::npos){
		word.replace(word.find("ies"), 3, "i");
	}
	else if (word.size() > 2 && word.find("ss", word.size()-2) != string::npos){
		word.replace(word.find("ss"), 2, "ss" );
	}
	else if ((word.at(word.size()-1)) == 's'){
		word.replace(word.size()-1, 1, "");
	}

	//Step 1b
	if((word.size() > 3 && getM(word.substr(0, word.size()-3)) > 0) && (word.find("eed", word.size()-3) != string::npos)){
		word.replace(word.find("eed"), 3, "ee");
	}
	else if((word.size() > 2 && hasVowel(word.substr(0, word.size()-2))) && (word.find("ed", word.size()-2) != string::npos) && word.at(word.size()-3) != 'e')
	{
		word.replace(word.find("ed"), 2, "");
		step1B = 1;//Show step 1b part two was executed
	}
	else if((word.size() > 3 && hasVowel(word.substr(0, word.size()-3))) && (word.find("ing") != -1)){
	       	word.replace(word.find("ing"), 3, "");
		step1B = 1;//Show step 1b part three was executed
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
		else if((word.size() > 2 && word.at(word.size()-2) == word.at(word.size()-1)) && (word.at(word.size()-2) != 's') && (word.at(word.size()-2) != 'l') && (word.at(word.size()-2) != 'z')){
			word = word.substr(0, word.size() -1);
		}
		else if(word.size() >= 3 && (!(isVowel(word.at(word.size()-3)))) && (isVowel(word.at(word.size()-2))) && (!(isVowel(word.at(word.size()-1)))) && (((word.at(word.size()-1) != 'w') && (word.at(word.size()-1) != 'x') && (word.at(word.size()-1) != 'y')))){
		
			m = getM(word);
			if(m == 1){
				word += "e";
			}
		}
	}
	//Step 1c
	if((hasVowel(word.substr(0, word.size()-1))) && (word.at(word.size()-1) == 'y')){
		word.replace(word.find_last_of("y"), 1, "i");
	}
	

	//Step two
	if(word.size() > 7 && getM(word.substr(0, word.size()-7)) > 0 && (word.find("ational") != -1)){
		word.replace(word.find("ational"), 7, "ate");
	}
	else if(word.size() > 6 && getM(word.substr(0, word.size()-6)) > 0 && (word.find("tional") != -1)){
                word.replace(word.find("tional"), 6, "tion");
        }
	else if(word.size() > 6 && getM(word.substr(0, word.size()-4)) > 0 && (word.find("enci") != -1)){
                word.replace(word.find("enci"), 4, "ence");
        }
	else if(word.size() > 4 && getM(word.substr(0, word.size()-4)) > 0 && (word.find("anci") != -1)){
                word.replace(word.find("anci"), 4, "ance");
        }
	else if(word.size() > 5 && getM(word.substr(0, word.size()-4)) > 0 && (word.find("izer") != -1)){
                word.replace(word.find("izer"), 4, "ize");
        }
	else if(word.size() > 4 && getM(word.substr(0, word.size()-4)) > 0 && (word.find("abli") != -1)){
                word.replace(word.find("abli"), 4, "able");
        }
	else if(word.size() > 4 && getM(word.substr(0, word.size()-4)) > 0 && (word.find("alli") != -1)){
                word.replace(word.find("alli"), 4, "al");
        }
	else if(word.size() > 5 && getM(word.substr(0, word.size()-5)) > 0 && (word.find("entli") != -1)){
                word.replace(word.find("entli"), 5, "ent");
        }
	else if(word.size() > 3 && getM(word.substr(0, word.size()-3)) > 0 && (word.find("eli") != -1)){
                word.replace(word.find("eli"), 3, "e");
        }
	else if(word.size() > 5 && getM(word.substr(0, word.size()-5)) > 0 && (word.find("ousli") != -1)){
                word.replace(word.find("ousli"), 5, "ous");
        }
	else if(word.size() > 7 && getM(word.substr(0, word.size()-7)) > 0 && (word.find("ization") != -1)){
                word.replace(word.find("ization"), 7, "ize");
        }
	else if(word.size() > 5 && getM(word.substr(0, word.size()-5)) > 0 && (word.find("ation", word.size() - 5) != -1)){
                word.replace(word.find("ation"), 5, "ate");
	}
	else if(word.size() > 4 && getM(word.substr(0, word.size()-4)) > 0 && (word.find("ator") != -1)){
                word.replace(word.find("ator"), 4, "ate");
        }
	else if(word.size() > 5 && getM(word.substr(0, word.size()-5)) > 0 && (word.find("alism") != -1)){
                word.replace(word.find("alism"), 5, "al");
        }
	else if(word.size() > 7 && getM(word.substr(0, word.size()-7)) > 0 && (word.find("iveness") != -1)){
                word.replace(word.find("iveness"), 7, "ive");
        }
	else if(word.size() > 7 && getM(word.substr(0, word.size()-7)) > 0 && (word.find("fulness") != -1)){
                word.replace(word.find("fulness"), 7, "ful");
        }
	else if(word.size() > 7 && getM(word.substr(0, word.size()-7)) > 0 && (word.find("ousness") != -1)){
                word.replace(word.find("ousness"), 7, "ous");
        }
	else if(word.size() > 5 && getM(word.substr(0, word.size()-5)) > 0 && (word.find("aliti") != -1)){
                word.replace(word.find("aliti"), 5, "al");
        }
	else if(word.size() > 5 && getM(word.substr(0, word.size()-5)) > 0 && (word.find("iviti") != -1)){
                word.replace(word.find("iviti"), 5, "ive");
        }
	else if(word.size() > 6 && getM(word.substr(0, word.size()-6)) > 0 && (word.find("biliti") != -1)){
                word.replace(word.find("biliti"), 6, "ble");
        }

	//Step 3
	if(word.size() > 5 && getM(word.substr(0, word.size()-5)) > 0 && word.find("icate", word.size()-5) != -1){
		word.replace(word.find("icate"), 5, "ic");
	}
	else if(word.size() > 5 && getM(word.substr(0, word.size()-5)) > 0 && word.find("ative", word.size()-5) != -1){
                word.replace(word.find("ative"), 5, "");
        }
	else if(word.size() > 5 && getM(word.substr(0, word.size()-5)) > 0 && word.find("alize", word.size()-5) != -1){
                word.replace(word.find("alize"), 5, "al");
        }
	else if(word.size() > 5 && getM(word.substr(0, word.size()-5)) > 0 && word.find("iciti", word.size()-5) != -1){
                word.replace(word.find("iciti"), 5, "ic");
        }
	else if(word.size() > 4 && getM(word.substr(0, word.size()-4)) > 0 && word.find("ical", word.size()-4) != -1){
                word.replace(word.find("ical"), 4, "ic");
        }
	else if(word.size() > 3 && getM(word.substr(0, word.size()-3)) > 0 && word.find("ful", word.size()-3) != -1){
                word.replace(word.find("ful"), 3, "");
        }
	else if(word.size() > 4 && getM(word.substr(0, word.size()-4)) > 0 && word.find("ness", word.size()-4) != -1){
                word.replace(word.find("ness"), 4, "");
        }

	//Step 4
	if(word.size() > 2 && getM(word.substr(0, word.size()-2)) > 1 && word.find("al", word.size() -2) != -1){
		word.replace(word.rfind("al"), 2, "");
	}
	else if(word.size() > 4 && getM(word.substr(0, word.size()-4)) > 1 && word.find("ance", word.size() -4) != -1){
                word.replace(word.rfind("ance"), 4, "");
        }
	else if(word.size() > 4 && getM(word.substr(0, word.size()-4)) > 1 && word.find("ence", word.size() -4) != -1){
                word.replace(word.rfind("ence"), 4, "");
        }
	else if(word.size() > 2 && getM(word.substr(0, word.size()-2)) > 1 && word.find("er", word.size() -2) != -1){
                word.replace(word.rfind("er"), 2, "");
        }
	else if(word.size() > 2 && getM(word.substr(0, word.size()-2)) > 1 && word.find("ic", word.size() -2) != -1){
                word.replace(word.rfind("ic"), 2, "");
        }
	else if(word.size() > 4 && getM(word.substr(0, word.size()-4)) > 1 && word.find("able", word.size() -4) != -1){
                word.replace(word.rfind("able"), 4, "");
        }
	else if(word.size() > 4 && getM(word.substr(0, word.size()-4)) > 1 && word.find("ible", word.size() -4) != -1){
                word.replace(word.rfind("ible"), 4, "");
        }
	else if(word.size() > 3 && getM(word.substr(0, word.size()-3)) > 1 && word.find("ant", word.size() -3) != -1){
                word.replace(word.rfind("ant"), 3, "");
        }
	else if(word.size() > 5 && getM(word.substr(0, word.size()-5)) > 1 && word.find("ement", word.size() -5) != -1){
                word.replace(word.rfind("ement"), 5, "");
        }
	else if(word.size() > 4 && getM(word.substr(0, word.size()-4)) > 1 && word.find("ment", word.size() -4) != -1){
                word.replace(word.rfind("ment"), 4, "");
        }
	else if(word.size() > 3 && getM(word.substr(0, word.size()-3)) > 1 && word.find("ent", word.size() -3) != -1){
                word.replace(word.rfind("ent"), 3, "");
        }
	else if(word.size() > 4 && getM(word.substr(0, word.size()-2)) > 1 && word.find("ion", word.size() -3) != -1 && (word.at(word.size()-4) == 's' || word.at(word.size()-4) == 't')){
                word.replace(word.rfind("ion"), 3, "");
        }
	else if(word.size() > 2 && getM(word.substr(0, word.size()-2)) > 1 && word.find("ou", word.size() -2) != -1){
                word.replace(word.rfind("ou"), 2, "");
        }
	else if(word.size() > 3 && getM(word.substr(0, word.size()-3)) > 1 && word.find("ism", word.size() -3) != -1){
                word.replace(word.rfind("ism"), 3, "");
        }
	else if(word.size() > 3 && getM(word.substr(0, word.size()-3)) > 1 && word.find("ate", word.size() -3) != -1){
                word.replace(word.rfind("ate"), 3, "");
        }
	else if(word.size() > 3 && getM(word.substr(0, word.size()-3)) > 1 && word.find("iti", word.size() -3) != -1){
                word.replace(word.rfind("iti"), 3, "");
        }
	else if(word.size() > 3 && getM(word.substr(0, word.size()-3)) > 1 && word.find("ous", word.size() -3) != -1){
                word.replace(word.rfind("ous"), 3, "");
        }
	else if(word.size() > 3 && getM(word.substr(0, word.size()-3)) > 1 && word.find("ive", word.size() -3) != -1){
                word.replace(word.rfind("ive"), 3, "");
        }
	else if(word.size() > 3 && getM(word.substr(0, word.size()-3)) > 1 && word.find("ize", word.size() -3) != -1){
                word.replace(word.rfind("ize"), 3, "");
        }

	//Step 5a
	if(word.size() > 1 && getM(word.substr(0, word.size()-1)) > 1 && word.at(word.size()-1) == 'e'){
		word.replace(word.rfind("e"), 1, "");
	}
	else if(word.size() > 3 && getM(word) == 1 && !((!(isVowel(word.at(word.size()-4)))) && (isVowel(word.at(word.size()-3))) && (!(isVowel(word.at(word.size()-2)))) && (((word.at(word.size()-2) != 'w') && (word.at(word.size()-2) != 'x') && (word.at(word.size()-2) != 'y'))))  && word.at(word.size()-1) == 'e'){
		word.replace(word.rfind("e"), 1, "");
	}

	//Step 5b
	if(word.size() > 1 && getM(word.substr(0, word.size()-1)) > 1 && (word.at(word.size()-1) == 'l' && word.at(word.size()-2) == 'l' )){
		word.replace(word.size()-1, 1, "");
	}

	return word;
}



int getM(string word){ //Used to find the measure of a word. The number of times there is a vowel or group of vowels followed by a consonant or group of consonants
	int m = 0; //Set measure to 0
	for(int i = 0; i < word.size(); i++){ //Loop through the entire word
		if((isVowel(word.at(i)))) //Check if the current letter is a vowel
		{
			if(i != (word.size() - 1)){ //Check if the letter is the last in the word
				if((!(isVowel(word.at(i+1))))){ //CHheck if the following letter is a consonant
					m++; //If it is increase measure by 1
				}
			}
		}
		else if((word.at(i) == 'y') || (word.at(i) == 'Y')){//Check if the letter is a y
			if(i != 0){ //Check that the y is not the first letter
				if((!(isVowel(word.at(i-1))))){ //Check if the letter before the y is a consonant, making the y a vowel.
					if(i != (word.size() - 1)){ //Check if the y is the last letter
						if((!(isVowel(word.at(i+1))))){ //Check if a consonant follows the y
							m++; //If so, increase measure by 1
						}
					}
				}
			}
		}
	}
	return m; //Return measure
}

int hasVowel(string word){ //Checks if a word contains a vowel
	for(int i = 0; i < word.size(); i++){ //Loop through the word
		if((isVowel(word.at(i)))) //Check if the current letter is a vowel
                {
			return true; //Return true if a vowel is found
		}
	}
	return false; //If no vowels are found, return false
}

bool isVowel(char let){ //Check if a letter is a vowel
	if((let == 'a') || (let == 'A') || (let == 'e') || (let == 'E') || (let == 'i') || (let == 'I') || (let == 'o') || (let == 'O') || (let == 'u') || (let == 'U')) //Check if a letter is a vowel (a, e, i, o, or u)
	{
		return true; //if it is, return true
	}
	else {
		return false; //If it is not, return false
	}
}


