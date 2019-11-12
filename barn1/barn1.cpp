/*
ID: khaled.17
TASK: barn1
LANG: C++14
*/


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct group {
	int st;
	int en;
};

int compare(const void* l, const void* r) {
	group left = *(group*)l;
	group right = *(group*)r;
	if ((left.en - left.st) < (right.en - right.st)) {
		// revers order
		return 1;
	}
	else {
		return -1;
	}
}


int main() {
	ifstream inF("barn1.in");
	ofstream outF("barn1.out");

	int M, S, C;
	inF >> M >> S >> C;

	bool* stalls = new bool[S + 1]{ false };

	int stNb;

	for (int c = 0; c < C; c++) {

		inF >> stNb;
		stalls[stNb] = true;
	}

	if (C <= 1) {
		outF << "1" << endl;
		return 0;
	}

	int areaStart = 1;
	int areaEnd = S;
	while (!stalls[areaStart] && areaStart <= S) {
		areaStart++;
	}
	while (!stalls[areaEnd] && areaEnd >= 1) {
		areaEnd--;
	}


	vector<group> ranges;

	for (int k = areaStart + 1; k < areaEnd; k++) {
		if (!stalls[k]) {
			int st = k;
			group place;
			place.st = st;
			while (!stalls[st]) {
				st++;
			}
			place.en = st;
			ranges.push_back(place);
			k = st - 1;
		}
	}

	group* rangesArray = &ranges[0];

	qsort(rangesArray, ranges.size(), sizeof(rangesArray[0]), compare);

	int ignored = areaStart - 1;
	ignored += S - areaEnd;

	for (int h = 0; h < M - 1 && h < ranges.size(); h++) {
		ignored += rangesArray[h].en - rangesArray[h].st;
	}


	outF << S - ignored << endl;

	return 0;
}