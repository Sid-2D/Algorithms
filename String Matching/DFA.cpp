// Application of string matching using DFA
// Problem is intended to be solved using regex but is simple enough 
// and I am designing the underlying finite automata for each pattern.
// Tested on this problem https://www.hackerrank.com/challenges/find-substring

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string T[108], P;
int m, n[108], sentences, sum;
int transitionTable[1008][256];

int getNextState (int state, int x) {
	if (state < m && P[state] == x) {
		return state + 1;
	}
	int i = 0, j = 1, k = 2, ns = 0;
	while (j <= m) {
		if (j != m) {
			if (P[i] == P[j]) {
				i++;
				j++;
				ns++;
			} else {
				i = ns = 0;
				j = k++;
			}
		} else {
			if (P[i] == (char)x) {
				i++;
				j++;
				ns++;
			} else {
				i = ns = 0;
				j = k++;
			}
		} 
	}
	return ns;
}

void computeTransitionTable () {
	for (int state = 0; state <= m; state++) {
		for (int x = 0; x < 256; x++) {
			transitionTable[state][x] = getNextState(state, x);
		}
	}
}

bool check (char x) {
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9') || (x == '_')) {
		return true;
	}
	return false;
}

bool isValid (int i, int j) {
	if (j + 1 < T[i].size()) {
		if (check(T[i][j + 1])) {
			if (j - m >= 0) {
				return check(T[i][j - m]);
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}

void dfaSearch () {
	computeTransitionTable();
	for (int i = 0; i < sentences; i++) {
		int state = 0;
		for (int j = 0; j < n[i]; j++) {
			state = transitionTable[state][T[i][j]];
			if (state == m) {
				if (isValid(i, j)) {
					sum++;
				}
			}
		}
	}
}

int main () {
	cin >> sentences;
	for (int i = 0; i < sentences; i++) {
		cin.ignore();
		getline(cin, T[i]);
		n[i] = T[i].size();
	}
	int queries;
	cin >> queries;
	while (queries--) {
		sum = 0;
		cin >> P;
		m = P.size();
		bool chk = true;
		for (int i = 0; i < m ; i++) {
			if (!check(P[i])) {
				chk = false;
				break;
			}
		}
		if (chk) {
			dfaSearch();
		}
		cout << sum << endl;
	}
	return 0;
}