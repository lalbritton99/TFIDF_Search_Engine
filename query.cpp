#include "query.h"

vector<string> query(vector<string> stops){
        string query, tempQuery;
	int temp = 0;
	bool stopped = true;
	vector<string> queryVec;
	vector<string> stoppedQuery;
        cout << "Enter your query: ";
	cin.ignore();
        getline(cin, query);
	
	istringstream querie(query);

	while(querie >> tempQuery) {
		queryVec.push_back(tempQuery);
	}

	vector<string>::iterator itr;
	for(itr = queryVec.begin(); itr < queryVec.end(); itr++){
		for(int j = 0; j < stops.size(); j++){
			if(*itr == stops[j]){
				stopped = true;
				break;
			}
			else {
				stopped = false;
			}
		}
		if (!stopped){
			stoppedQuery.push_back(*itr);
		}
	}
	return stoppedQuery;
}

