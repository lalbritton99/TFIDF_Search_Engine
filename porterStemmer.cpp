#include "porterStemmer.h"

using namespace std;


porterStem::porterStem(){
        word = "";
}
void porterStem::setWord(string change){
        word = change;
}
string porterStem::getWord(){
        return word;
}
string portStem(string change){
        cout << change << endl;
}


