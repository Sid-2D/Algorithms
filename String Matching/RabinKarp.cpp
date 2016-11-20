// Application of Rabin-Karp's Algorithm
// Tested on this problem: http://www.spoj.com/problems/NAJPF/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MOD 101
#define d 256

char T[1000008];
char P[1000008];
long long int m, n, ans[1000008], len, hash[1000008], hashLen, sum, p = 0, t = 0, h = 1;

void hashify () {
	m = strlen(P);
	n = strlen(T);
	long long int i;
	for (i = 0; i < m; i++) {
		p = (p * d + P[i]) % MOD;
		t = (t * d + T[i]) % MOD;
	}
	for (i = 0; i < m - 1; i++) {
		h = (h * d) % MOD;
	}
	hash[hashLen++] = t;
	for (i = 1; i <= n - m + 1; i++) {
		t = (d * (t - h * T[i - 1]) + T[i + m - 1]) % MOD; 
		if (t < 0) {
			t += MOD;
		}
		hash[hashLen++] = t;
	}
}

void rabinKarpSearch () {
	long long int i, j;
	for (i = 0; i < hashLen; i++) {
		if (hash[i] == p) {
			for (j = 0; j < m; j++) {
				if (P[j] != T[i + j]) {
					break;
				}
			}
			if (j == m) {
				sum++;
				ans[len++] = i + 1;
			}
		}
	}
}

int main () {
	int cases;
	cin >> cases;
	while (cases--) {
		sum = len = p = t = hashLen = 0;
		h = 1;
		scanf("%s%s", T, P);
		hashify();
		rabinKarpSearch();
		if (sum == 0) {
			cout << "Not Found\n";
		} else {
			cout << sum << endl;
			for (long long int i = 0; i < len; i++) {
				printf("%lld ", ans[i]);
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}