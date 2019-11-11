/*
ID: khaled.17
TASK: milk
LANG: C++14
*/


#include <iostream>
#include <fstream>

using namespace std;


struct farmer {
	int price;
	int amount;
};

int compare(const void* l, const void* r) {
	farmer left = *(farmer*)l;
	farmer right = *(farmer*)r;
	if (left.price < right.price) {
		return -1;
	}
	else {
		return 1;
	}
}

int main() {
	ifstream inF("milk.in");
	ofstream outF("milk.out");

	int N, M;
	inF >> N >> M;

	

	farmer* sources = new farmer[M];

	for (int k = 0; k < M; k++) {
		inF >> sources[k].price >> sources[k].amount;
	}

	qsort(sources, M, sizeof(sources[0]), compare);

	int totalPaid = 0;
	int totalCollected = 0;
	int ix = 0;
	
	while (totalCollected < N && ix < M) {
		int remain = N - totalCollected;
		int needed = sources[ix].amount;

		if (needed > remain) {
			needed = remain;
		}

		totalPaid += needed * sources[ix].price;

		totalCollected += needed;
		ix++;
	}

	outF << totalPaid << endl;

	return 0;
}