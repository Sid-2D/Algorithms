// Link: https://www.hackerrank.com/challenges/coin-change/problem

#include <stdio.h>

int main() {
	int c, n, i, j, coins[55];
	scanf("%d%d", &n, &c);
	for (i = 0; i < c; i++) {
		scanf("%d", &coins[i]);
	}
	for (i = 0; i < c - 1; i++) {
		for (j = i + 1; j < c; j++) {
			if (coins[j] < coins[i]) {
				int temp = coins[j];
				coins[j] = coins[i];
				coins[i] = temp;
			}
		}
	}
	long long unsigned int dp[255] = {0};
	for(i=0; i < c; i++) {
		dp[coins[i]]++;
		for(j = coins[i] + 1; j <= n; j++) {
			if (dp[j - coins[i]]) {
				dp[j] += dp[j - coins[i]];
			}
		}
	}
	printf("%llu", dp[n]);
	return 0;
}