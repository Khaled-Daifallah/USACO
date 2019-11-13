/*
ID: khaled.17
TASK: crypt1
LANG: C++14
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream inF("crypt1.in");
	ofstream outF("crypt1.out");

	int setSize;
	inF >> setSize;

	int* set = new int[setSize];
	string all = "";
	for (int k = 0; k < setSize; k++) {
		inF >> set[k];
		all += (char)(set[k] + 48);
	}

	int total = 0;

	int line1[3];
	int line2[2];

	for (int r11 = 0; r11 < setSize; r11++) {
		if (set[r11] == 0) {
			continue;
		}
		for (int r12 = 0; r12 < setSize; r12++) {
			for (int r13 = 0; r13 < setSize; r13++) {
				for (int r21 = 0; r21 < setSize; r21++) {
					if (set[r21] == 0) {
						continue;
					}
					for (int r22 = 0; r22 < setSize; r22++) {
						int nb1 = (100 * set[r11]) + (10 * set[r12]) + set[r13];
						// int nb2 = (10 * r21) + r22;
						
						int p1 = nb1 * set[r21];
						if (p1 > 999 || p1 < 100) {
							continue;
						}

						int p2 = nb1 * set[r22];
						if (p2 > 999 || p2 < 100) {
							continue;
						}

						int sum = (p1 * 10) + p2;
						if (sum > 9999 || sum < 1000) {
							continue;
						}

						string s1 = to_string(p1);
						bool skip = false;
						for (int h = 0; h < 3; h++) {
							if (all.find(s1[h]) == -1) {
								skip = true;
								break;
							}
						}
						if (skip) {
							continue;
						}


						string s2 = to_string(p2);
						for (int h = 0; h < 3; h++) {
							if (all.find(s2[h]) == -1) {
								skip = true;
								break;
							}
						}
						if (skip) {
							continue;
						}

						string s3 = to_string(sum);
						for (int h = 0; h < 4; h++) {
							if (all.find(s3[h]) == -1) {
								skip = true;
								break;
							}
						}
						if (skip) {
							continue;
						}

						total++;
					}
				}
			}
		}
	}

	outF << total << endl;


	return 0;
}