/*
ID: khaled.17
TASK: transform
LANG: C++14
*/

#include <iostream>
#include <fstream>

using namespace std;


bool** transform90(bool** table, int n) {
	bool** result = new bool* [n];
	for (int k = 0; k < n; k++) {
		result[k] = new bool[n];
	}

	int d = n - 1;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			result[c][d - r] = table[r][c];
		}
	}
	return result;
}

bool** transform180(bool** table, int n) {
	bool** res1 = transform90(table, n);
	bool** res2 = transform90(res1, n);
	return res2;
}

bool** transform270(bool** table, int n) {
	bool** res1 = transform180(table, n);
	bool** res2 = transform90(res1, n);
	return res2;
}

bool** refelct(bool** table, int n) {
	bool** result = new bool* [n];
	for (int k = 0; k < n; k++) {
		result[k] = new bool[n];
	}

	int d = n - 1;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			result[r][d - c] = table[r][c];
		}
	}
	return result;
}

bool areEqual(bool** a, bool** b, int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != b[i][j]) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	ifstream inF("transform.in");
	ofstream outF("transform.out");

	int nb;
	inF >> nb;

	bool** from = new bool* [nb];
	bool** to = new bool* [nb];
	char ch;
	for (int k = 0; k < 2; k++) {
		bool** temp = ((k == 0) ? from : to);

		for (int i = 0; i < nb; i++) {
			temp[i] = new bool[nb];

			for (int j = 0; j < nb; j++) {
				inF >> ch;
				temp[i][j] = ((ch == '@') ? true : false);
			}
		}
	}
	// test
	
	/*for (int h = 0; h < nb; h++) {
		for (int a = 0; a < nb; a++) {
			cout << ((from[h][a]) ? '@' : '-');
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	for (int h = 0; h < nb; h++) {
		for (int a = 0; a < nb; a++) {
			cout << ((to[h][a]) ? '@' : '-');
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	bool** res1 = transform90(from, nb);
	for (int h = 0; h < nb; h++) {
		for (int a = 0; a < nb; a++) {
			cout << ((res1[h][a]) ? '@' : '-');
		}
		cout << endl;
	}*/
	
	
	bool** res = transform90(from, nb);

	if (areEqual(res, to, nb)) {
		outF << "1" << endl;
		return 0;
	}

	bool** res2 = transform90(res, nb);
	if (areEqual(res2, to, nb)) {
		outF << "2" << endl;
		return 0;
	}

	res= transform90(res2, nb);
	if (areEqual(res, to, nb)) {
		outF << "3" << endl;
		return 0;
	}

	res = refelct(from, nb);
	if (areEqual(res, to, nb)) {
		outF << "4" << endl;
		return 0;
	}

	res2 = transform90(res, nb);
	if (areEqual(res2, to, nb)) {
		outF << "5" << endl;
		return 0;
	}

	res = transform90(res2, nb);
	if (areEqual(res, to, nb)) {
		outF << "5" << endl;
		return 0;
	}

	res2 = transform90(res, nb);
	if (areEqual(res2, to, nb)) {
		outF << "5" << endl;
		return 0;
	}

	if (areEqual(from, to, nb)) {
		outF << "6" << endl;
		return 0;
	}

	outF << "7" << endl;
	return 0;
}