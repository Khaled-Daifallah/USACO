/*
ID: khaled.17
TASK: gift1
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
	ifstream inF("gift1.in");
	ofstream outF("gift1.out");

	int fnb = 0;

	inF >> fnb;

	map<string, int> balances;
	string* order = new string[fnb];

	for (int k = 0; k < fnb; k++) {
		string name;
		inF >> name;
		balances[name] = 0;
		order[k] = name;
	}

	for (int h = 0; h < fnb; h++) {
		string giver;
		inF >> giver;
		
		int amount, takers;
		inF >> amount >> takers;

		if (takers == 0) {
			continue;
		}

		int share = amount / takers;

		balances[giver] -= amount;
		balances[giver] += amount % takers;

		for (int a = 0; a < takers; a++) {
			string t;
			inF >> t;

			balances[t] += share;
		}
	}

	/*for (auto fr : balances) {
		outF << fr.first << " " << fr.second << endl;
	}*/
	for (int e = 0; e < fnb; e++) {
		outF << order[e] << " " << balances[order[e]] << endl;
	}




	return 0;
}