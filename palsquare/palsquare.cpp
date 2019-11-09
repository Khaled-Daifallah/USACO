/*
ID: khaled.17
TASK: palsquare
LANG: C++14
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string convertToBase(int nb, int b) {
	string val = "";

	int cur = nb;
	while (cur > 0)
	{
		int div = (int)(cur / b);
		int remain = cur % b;
		string digit;
		if (remain > 9) {
			digit = (char)((remain - 9) + 64);
		}
		else {
			digit = to_string(remain);
		}

		val = digit + val;

		cur = div;
	}

	return val;
}

bool isPalindromic(string nb) {

	int st = 0;
	int en = nb.length() - 1;
	while (st < en) {
		
		if (nb[st] != nb[en]) {
			return false;
		}

		st++;
		en--;
	}

	return true;
}

int main() {
	ifstream inF("palsquare.in");
	ofstream outF("palsquare.out");

	int base;

	inF >> base;

	for (int N = 1; N <= 300; N++) {
		int square = N * N;
		string representation = convertToBase(square, base);
		if (isPalindromic(representation)) {
			outF << convertToBase(N, base) << " " << representation << endl;
		}
	}

	return 0;
}