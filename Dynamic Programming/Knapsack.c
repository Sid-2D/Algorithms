// Link: http://www.spoj.com/problems/PARTY/

#include <stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n, budget, i, j, price[105], fun[105], cash, sum;
	while(1) {
		scanf("%d%d", &budget, &n);
		if (budget == 0 && n == 0) {
			break;
		}
		int dp[505][105] = {0};
		cash = 0;
		for(i = 0; i < n; i++) {
			scanf("%d%d", &price[i], &fun[i]);
		}
		for(i = 0; i < n - 1; i++) {
			for(j = i + 1; j < n; j++) {
				if (price[i] > price[j]) {
					int tmp1 = price[i];
					int tmp2 = fun[i];
					price[i] = price[j];
					fun[i] = fun[j];
					price[j] = tmp1;
					fun[j] = tmp2;
				}
			}
		}
		for(i = price[0]; i <= budget; i++) {
			for(j = 1; j <= n; j++) {
				if(i < price[j-1]) {
					dp[i][j] = dp[i][j - 1];
				} else {
					dp[i][j] = max(dp[i][j - 1], dp[i - price[j - 1]][j - 1] + fun[j - 1]);
				}
			}
		}
		i = budget;
		while(dp[i][n] == dp[i - 1][n]) {
			i--;
		}
		cash = i;
		printf("%d %d\n", cash, dp[budget][n]);
	}
	return 0;
} 