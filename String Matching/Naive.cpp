// Application of Naive String Matching Algorithm
// Tested on this problem: http://www.spoj.com/problems/NAJPF/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char T[1000008];
char P[1000008];
long long int m, n, ans[1000008], len, sum;

void bruteForce () {
	long long int i = 0, j = 0;
	n = strlen(T);
	m = strlen(P);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (T[i + j] == P[j]) {
				if (j == m - 1) {
					sum++;
					ans[len++] = i + 1;
				}
			} else {
				break;
			}
		}
	}
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		sum = len = 0;
		scanf("%s%s", T, P);
		bruteForce();
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