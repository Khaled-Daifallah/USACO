/*
ID: khaled.17
TASK: combo
LANG: C++14
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isOkNb(int nb, int lock, int digits) {

	if (lock == nb) {
		return true;
	}

	int p1, p2, m1, m2;
	p1 = (nb + 1);
	if (p1 > digits) {
		p1 -= digits;
	}
	if (lock == p1) {
		return true;
	}

	p2 = (nb + 2);
	if (p2 > digits) {
		p2 -= digits;
	}
	if (lock == p2) {
		return true;
	}

	m1 = (nb - 1);
	if (m1 < 1) {
		m1 += digits;
	}
	if (lock == m1) {
		return true;
	}

	m2 = (nb - 2);
	if (m2 < 1) {
		m2 += digits;
	}
	if (lock == m2) {
		return true;
	}

	return false;
}

int main() {
	ifstream inF("combo.in");
	ofstream outF("combo.out");

	int digits;
	inF >> digits;
	int fLock[3];
	int mLock[3];

	for (int k = 0; k < 3; k++) {
		inF >> fLock[k];
	}
	for (int k = 0; k < 3; k++) {
		inF >> mLock[k];
	}

	int total = 0;

	for (int n1 = 1; n1 <= digits; n1++) {
		bool isMasterOnly = false;
		bool isFarmerOnly = false;
		bool level1 = false;

		bool matchedMaster = isOkNb(n1, mLock[0], digits);
		bool matchedFarmer = isOkNb(n1, fLock[0], digits);
		
		if (!matchedMaster && !matchedFarmer) {
			continue;
		}
		if (matchedMaster && !matchedFarmer) {
			isMasterOnly = true;
			level1 = true;
		}
		else if (!matchedMaster && matchedFarmer) {
			isFarmerOnly = true;
			level1 = true;
		}
		
		for (int n2 = 1; n2 <= digits; n2++) {
			if (isMasterOnly && level1) {
				matchedMaster = isOkNb(n2, mLock[1], digits);
				if (!matchedMaster) {
					continue;
				}
			}
			else if(isFarmerOnly && level1) {
				matchedFarmer = isOkNb(n2, fLock[1], digits);
				if (!matchedFarmer) {
					continue;
				}
			}
			else {
				isMasterOnly = false;
				isFarmerOnly = false;
				matchedMaster = isOkNb(n2, mLock[1], digits);
				matchedFarmer = isOkNb(n2, fLock[1], digits);
				if (!matchedMaster && !matchedFarmer) {
					continue;
				}
				if (matchedMaster && !matchedFarmer) {
					isMasterOnly = true;
				}
				else if (!matchedMaster && matchedFarmer) {
					isFarmerOnly = true;
				}
			}

			for (int n3 = 1; n3 <= digits; n3++) {
				if (isMasterOnly) {
					matchedMaster = isOkNb(n3, mLock[2], digits);
					if (!matchedMaster) {
						continue;
					}
				}
				else if (isFarmerOnly) {
					matchedFarmer = isOkNb(n3, fLock[2], digits);
					if (!matchedFarmer) {
						continue;
					}
				}
				else {
					matchedMaster = isOkNb(n3, mLock[2], digits);
					matchedFarmer = isOkNb(n3, fLock[2], digits);
					if (!matchedMaster && !matchedFarmer) {
						continue;
					}
				}
				//cout << n1 << n2 << n3 << endl;
				total++;
			}
		}
	}

	outF << total << endl;

	return 0;
}