/*
ID: khaled.17
TASK: milk2
LANG: C++14
*/

#include <iostream>
#include <fstream>

using namespace std;

int compare(const void* l, const void* r) {
	int* left = *(int**)l;
	int* right = *(int**)r;
	if (left[0] < right[0]) {
		return -1;
	}
	else if (left[0] == right[0]) {
		if (left[1] < right[1]) {
			return -1;
		}
		else {
			return 1;
		}
	}
	else {
		return 1;
	}
}

int main() {
	ifstream inF("milk2.in");
	ofstream outF("milk2.out");

	int nb;
	inF >> nb;
	int** table = new int* [nb];

	for (int k = 0; k < nb; k++) {
		table[k] = new int[2];
		inF >> table[k][0] >> table[k][1];
	}

	int maxOff = 0;

	//int size = sizeof(table) / sizeof(table[0]);

	qsort(table, nb, sizeof(table[0]), compare);

	int bestRange[2] = { 0,0 };

	for (int x = 0; x < nb; x++) {
		int range[2] = { table[x][0],table[x][1] };

		for (int h = 0; h < nb; h++) {
			if (h == x) {
				continue;
			}
			int st = table[h][0];
			int en = table[h][1];

			if (st >= range[0] && en <= range[1]) {
				continue;
			}
			else if (st >= range[0] && st<=range[1] && en > range[1]) {
				range[1] = en;
			}
			else if (st < range[0] && en>=range[0] && en <= range[1]) {
				range[0] = st;
			}
			else if (st < range[0] && en > range[1]) {
				range[0] = st;
				range[1] = en;
			}
			/*else {
				if ((en - st) > (range[1] - range[0])) {
					range[0] = st;
					range[1] = en;
				}
			}*/
		}
		if ((range[1] - range[0]) > (bestRange[1] - bestRange[0])) {
			bestRange[0] = range[0];
			bestRange[1] = range[1];
		}

	}

	if (nb > 1) {
		int covered = 0;
		for (int a = 0; a < nb - 1; a++) {
			int st1 = table[a][0];
			int en1 = table[a][1];

			int st2 = table[a+1][0];
			int en2 = table[a+1][1];
			int off = 0;

			if (st2 > covered && st2 > en1) {
				off = st2 - ((covered > en1) ? covered : en1);
				// covered = en2;
			}
			else {
				if (en1 > covered) {
					covered = en1;
				}
			}

			if (off > maxOff) {
				maxOff = off;
			}

		}
	}

	outF << (bestRange[1] - bestRange[0]) << " " << maxOff << endl;


	return 0;
}

