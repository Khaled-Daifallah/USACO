/*
ID: khaled.17
TASK: namenum
LANG: C++14
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


string convertToNb(string name) {
	string nb = "";
	for (int k = 0; k < name.length(); k++) {
		if (name[k] == 'A' || name[k] == 'B' || name[k] == 'C') {
			nb += "2";
		}
		else if (name[k] == 'E' || name[k] == 'F' || name[k] == 'D') {
			nb += "3";
		}
		else if (name[k] == 'G' || name[k] == 'H' || name[k] == 'I') {
			nb += "4";
		}
		else if (name[k] == 'J' || name[k] == 'K' || name[k] == 'L') {
			nb += "5";
		}
		else if (name[k] == 'M' || name[k] == 'N' || name[k] == 'O') {
			nb += "6";
		}
		else if (name[k] == 'P' || name[k] == 'R' || name[k] == 'S') {
			nb += "7";
		}
		else if (name[k] == 'T' || name[k] == 'U' || name[k] == 'V') {
			nb += "8";
		}
		else if (name[k] == 'W' || name[k] == 'X' || name[k] == 'Y') {
			nb += "9";
		}
		else {
			// cout << "Strange value " << name[k] << endl;
			nb += "0";
		}
	}

	return nb;
}

int main() {
	ifstream inF("namenum.in");
	ofstream outF("namenum.out");
	ifstream dic("dict.txt");

	string name;

	dic >> name;

	int ix = 0;
	vector<string> acceptedNames;
	vector<string> namesNumbers;


	while (!dic.eof()) {
		acceptedNames.push_back(name);

		
		namesNumbers.push_back(convertToNb(name));

		dic >> name;
	}

	string target;
	inF >> target;
	bool found = false;

	for (int h = 0; h < namesNumbers.size(); h++) {
		if (namesNumbers.at(h) == target) {
			outF << acceptedNames.at(h) << endl;
			found = true;
		}
	}

	if (!found) {
		outF << "NONE" << endl;
	}
	return 0;
}