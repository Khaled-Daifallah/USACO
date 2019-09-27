/*
ID: khaled.17
TASK: friday
LANG: C++14
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream inF("friday.in");
	ofstream outF("friday.out");


	int years;
	inF >> years;

	int days[7] = { 0 };
	// 13/1/1900 is Sat
	// int y = 1900, m = 1;
	int target = 1900 + years;
	
	days[0] = 1;
	int index = 0;
	for (int y = 1900; y < target; y++) {
		for (int m = 1; m < 13; m++) {
			int remain;
			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
				remain = 18;// 31 - 13;
			}
			else if (m == 9 || m == 4 || m == 6 || m == 11) {
				remain = 17;//  30 - 13;
			}
			else if (m == 2) {
				if (y % 400 == 0) {
					remain = 16;// 29 - 13;
				}
				else if (y % 100 == 0) {
					remain = 15;// 28 - 13;
				}
				else if (y % 4 == 0) {
					remain = 16;// 29 - 13;
				}
				else {
					remain = 15;// 28 - 13;
				}
			}
			remain += 13;
			int diff = remain % 7;
			index = (index + diff) % 7;
			days[index]++;
		}
	}
	days[index]--;

	for (int k = 0; k < 6; k++) {
		outF << days[k] << " ";
	}
	outF << days[6] << endl;

	return 0;
}