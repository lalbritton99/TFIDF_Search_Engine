#include "query.h"

void query(){
        string query, tempQuery;
	int temp = 0;
	vector<string> queryVec;
        cout << "Enter your query: ";
        getline(cin, query);
	
	istringstream querie(query);

	while(querie >> tempQuery) {
		queryVec.push_back(tempQuery);
	}


	for(int i = 0; i < queryVec.size(); i++){
		cout << queryVec[i] << endl;
	}
}

