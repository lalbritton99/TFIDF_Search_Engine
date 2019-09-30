#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//#include <document.h> // this function will read a file into instance of document class
using namespace std;

void fileOpener(string file_type);

//	file_type
//	options for this parameter include:
//		"Documents" - indicates the documents file
//		"Stopwords" - indicates the stopwords file
//	THE PARAMETER MUST BE ENTERED EXACTLY AS SHOWN (capitalize first letter)