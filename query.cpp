#include "query.h"

vector<string> query(vector<string> stops){
        string query, tempQuery;
	int temp = 0;
	bool stopped = true;
	vector<string> queryVec; //Vector of strings for query as input
	vector<string> stoppedQuery; //Vector to store query after the stopwords are removed
        cout << "Enter your query: "; //Prompt for the query
	cin.ignore();
        getline(cin, query); //Read in the query
	
	istringstream queryStream(query); //String stream to iterate through the string

	while(queryStream >> tempQuery) { //While loop to populate queryVec
		queryVec.push_back(tempQuery);
	}

	vector<string>::iterator itr;
	for(itr = queryVec.begin(); itr < queryVec.end(); itr++){ //Loops through queryVec
		for(int j = 0; j < stops.size(); j++){ //Loops through stop word vector
			if(*itr == stops[j]){ //If the element is found in the stop word query, set stopped to true
				stopped = true;
				break;
			}
			else {
				stopped = false;
			}
		}
		if (!stopped){ //If stopped is false, add the element to the stopped query
			stoppedQuery.push_back(*itr);
		}
	}
	for(int i = 0; i < stoppedQuery.size(); i++){ //Loop through stopped query
		for(int j = 0; j < stoppedQuery[i].size(); j++){ //Loop through each individual words
			if((ispunct(stoppedQuery[i].at(j))) && (stoppedQuery[i].at(j) != '-')){ //If punctuation is found, remove it
				stoppedQuery[i].replace(stoppedQuery[i].size()-1, 1, "");
			}
		}
	}
	return stoppedQuery; //Return a copy of the query without stop words
}

