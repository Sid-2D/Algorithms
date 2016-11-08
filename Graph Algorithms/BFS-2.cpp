// Application of Breadth First Search
// Tested on this problem: http://www.spoj.com/problems/MAKEMAZE/

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

char GRID[27][27];
int m, n;
int VISITED[27][27];

bool inGrid(int x, int y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}

int main () {
	int t; 
	cin >> t;
	int count = 0;
	while (t--) {
		count++;
		memset(VISITED, 0, sizeof(int) * 27 * 27);
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			cin >> GRID[i];
		}
		int edge = 0, x1 = -1, y1 = -1, x2 = -1, y2 = -1;
		for (int i = 0; i < m; i++) {
			
			if (GRID[i][0] == '.' && VISITED[i][0] == 0) {
				edge++;
				if (x1 == -1) {
					x1 = i;
					y1 = 0;
				} else {
					x2 = i;
					y2 = 0;
				}
				VISITED[i][0] = 1;
			}
			if (GRID[i][n - 1] == '.' && VISITED[i][n - 1] == 0) {
				edge++;
				if (x1 == -1) {
					x1 = i;
					y1 = n - 1;
				} else {
					x2 = i;
					y2 = n - 1;
				}
				VISITED[i][n-1] = 1;
			}
			
		}
		for(int i = 0; i < n; i++) {
			if (GRID[0][i] == '.' && VISITED[0][i] == 0) {
				edge++;
				if (x1 == -1) {
					x1 = 0;
					y1 = i;
				} else {
					x2 = 0;
					y2 = i;
				}
				VISITED[0][i] = 1;
			}
			if (GRID[m - 1][i] == '.' && VISITED[m - 1][i] == 0) {
				edge++;
				if (x1 == -1) {
					x1 = m - 1;
					y1 = i;
				} else {
					x2 = m - 1;
					y2 = i;
				}
				VISITED[m - 1][i] = 1;
			}
		}
		if (edge != 2) {
			cout << "invalid\n";
			continue;
		}
		VISITED[x1][y1] = VISITED[x2][y2] = 0;
		queue < pair<int, int> > Q;
		Q.push(make_pair(x1, y1));
		int d1[] = {1, 0, -1, 0};
		int d2[] = {0, 1, 0, -1};
		bool ans = false;
		while (!Q.empty()) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			if (x == x2 && y == y2) {
				ans = true;
				break;
			}
			VISITED[x][y] = 1;
			for (int i = 0; i < 4; i++) {
				if (inGrid(x + d1[i], y + d2[i]) && GRID[x + d1[i]][y + d2[i]] == '.' && VISITED[x + d1[i]][y + d2[i]] == 0) {
					Q.push(make_pair(x + d1[i], y + d2[i]));
				}
			}
		}
		if (ans) {
			cout << "valid\n";
			continue;
		}
		cout << "invalid\n";
	}
	return 0;
}