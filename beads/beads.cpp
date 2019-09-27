/*
ID: khaled.17
TASK: beads
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream inF("beads.in");
	ofstream outF("beads.out");

	string neckles;
	int nb;
	inF >> nb >> neckles;

	int len = neckles.length();

	int max = -1;


	for (int p = 0; p < len; p++) {
		int count = 0;
		int before = p - 1;
		int after = p;
		
		bool begining = true;

		bool ok = true;

		

		char leftC = '-';
		char rightC = '-';

		bool goLeft = true, goRigh = true;

		while (ok) {
			
			if (before < 0) {
				before = len - 1;
			}
			if (after >= len) {
				after = 0;
			}
			if (before == after) {
				count++;
				break;
			}
			if (!begining && abs(before - after) == 1) {
				count += 2;
				break;
			}
			
			if (goLeft) {
				if (neckles[before] == 'w') {
					count++;
					before--;
				}
				else {
					if (leftC == '-') {
						leftC = neckles[before];
						count++;
						before--;
					}
					else if (leftC == neckles[before]) {
						count++;
						before--;
					}
					else {
						goLeft = false;
					}
				}
			}
			if (goRigh) {
				if (neckles[after] == 'w') {
					count++;
					after++;
				}
				else {
					if (rightC == '-') {
						rightC = neckles[after];
						count++;
						after++;
					}
					else if (rightC == neckles[after]) {
						count++;
						after++;
					}
					else {
						goRigh = false;
					}
				}
			}

			begining = false;
			ok = goLeft || goRigh;
		}
		if (count > max) {
			max = count;
		}
	}

	outF << max << endl;


	return 0;
}