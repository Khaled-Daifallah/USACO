/*
ID: khaled.17
TASK: dualpal
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
	
	if (nb[st] == '0' || nb[en] == '0') {
		return false;
	}

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
	ifstream inF("dualpal.in");
	ofstream outF("dualpal.out");

	int N, S;
	inF >> N >> S;

	int matches = 0;

	for (int k = S + 1; matches < N; k++) {
		int currPalindromes = 0;
		for (int base = 2; base < 10; base++) {
			string representation = convertToBase(k, base);
			if (isPalindromic(representation)) {
				currPalindromes++;
				if (currPalindromes == 2) {
					break;
				}
			}
		}
		if (currPalindromes == 2) {
			outF << k << endl;
			matches++;
		}
		else if (currPalindromes == 1) {
			if (isPalindromic(to_string(k))) {
				outF << k << endl;
				matches++;
			}
		}
	}

	return 0;
}