/*
ID: khaled.17
TASK: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
	ifstream inF("ride.in");
	ofstream outF("ride.out");

	string gName, cName;

	inF >> gName >> cName;

	int gTotal = 1, cTotal = 1;

	for (int k = 0; k < gName.length(); k++) {
		gTotal *= (int)gName[k] - 64;
	}
	for (int k = 0; k < cName.length(); k++) {
		cTotal *= (int)cName[k] - 64;
	}

	if (cTotal % 47 == gTotal % 47) {
		outF << "GO" << endl;
	}
	else {
		outF << "STAY" << endl;
	}

	return 0;

}