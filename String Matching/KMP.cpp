// Application of Knuth-Morris-Pratt's Algorithm
// Tested on this problem: http://www.spoj.com/problems/NAJPF/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char T[1000008];
char P[1000008];
long long int m, n, b[1000008] = {-1}, ans[1000008], len, sum;

void kmpPreprocess () {
	long long int i = 0, j = -1; 
	m = strlen(P);
	while (i < m) { 
		while (j >= 0 && P[i] != P[j]) {
			j--;
		}
		i++;
		j++; 
		b[i] = j;
	} 
} 

void kmpSearch () {
	long long int i = 0, j = 0;
	n = strlen(T);
	m = strlen(P);
	while (i < n) {
		while (j >= 0 && T[i] != P[j]) {
			j--;
		}
		i++;
		j++;
		if (j == m) {
			sum++;
			ans[len++] = i - j;
			j = b[j];
		}
	}
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		sum = len = 0;
		scanf("%s%s", T, P);
		kmpPreprocess();
		kmpSearch();		
		if (sum == 0) {
			cout << "Not Found\n";
		} else {
			cout << sum << endl;
			for (long long int i = 0; i < len; i++) {
				printf("%lld ", ans[i] + 1);
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}