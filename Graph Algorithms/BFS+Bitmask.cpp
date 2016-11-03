// Application of Breadth First Search along with some bitmasks
// Tested on this problem: http://www.spoj.com/problems/CERC07K/

#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

queue < pair<pair <int, int>, int> > Q;
int VISITED[108][108][16], R, C;
char GRID[108][108];

void check (int i, int j, int mask, int steps) {
	if (i >= 0 && i < R && j >= 0 && j < C) {
		if (GRID[i][j] != '#' && VISITED[i][j][mask] == -1) {
			if (GRID[i][j] >= 'a' && GRID[i][j] <= 'z') {
				VISITED[i][j][mask] = steps + 1;
				switch (GRID[i][j]) {
					case 'r': mask = mask | 0x1; break;
					case 'g': mask = mask | 0x2; break;
					case 'b': mask = mask | 0x4; break;
					case 'y': mask = mask | 0x8; break;
				}
				Q.push(make_pair(make_pair(i, j), mask));
				VISITED[i][j][mask] = steps + 1;
			} else if (GRID[i][j] >= 'A' && GRID[i][j] <= 'Z') {
				switch (GRID[i][j]) {
					case 'R': if (mask & 0x1) {
						Q.push(make_pair(make_pair(i, j), mask));
						VISITED[i][j][mask] = steps + 1;
					}; break;
					case 'G': if (mask & 0x2) {
						Q.push(make_pair(make_pair(i, j), mask));
						VISITED[i][j][mask] = steps + 1;
					}; break;
					case 'B': if (mask & 0x4) {
						Q.push(make_pair(make_pair(i, j), mask));
						VISITED[i][j][mask] = steps + 1;
					}; break;
					case 'Y': if (mask & 0x8) {
						Q.push(make_pair(make_pair(i, j), mask));
						VISITED[i][j][mask] = steps + 1;
					}; break;
					case 'X': Q.push(make_pair(make_pair(i, j), mask)); VISITED[i][j][mask] = steps + 1;
				}
			} else {
				Q.push(make_pair(make_pair(i, j), mask)); 
				VISITED[i][j][mask] = steps + 1;
			}
		}
	}
} 

int main () {
	scanf("%d%d", &R, &C);
	while (R || C) {
		bool ans = true;
		int i, j, mask;
		for (i = 0; i < R; i++) {
			scanf("%s", GRID[i]);
		}
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) {
				if (GRID[i][j] == '*') {
					Q.push(make_pair(make_pair(i, j), 0));
				}
				for (int k = 0; k < 16; k++) {
					VISITED[i][j][k] = -1;
				}
			}
		}
		while (!Q.empty()) {
			i = Q.front().first.first;
			j = Q.front().first.second;
			mask = Q.front().second;
			int steps = VISITED[i][j][mask];
			if (GRID[i][j] == 'X') {
				printf("Escape possible in %d steps.\n", steps + 1);
				ans = false;
				break;
			}
			check(i, j - 1, mask, steps);
			check(i - 1, j, mask, steps);
			check(i, j + 1, mask, steps);
			check(i + 1, j, mask, steps);
			Q.pop();
		}
		if (ans) {
			printf("The poor student is trapped!\n");
		}
		while (!Q.empty()) {
			Q.pop();
		}
		scanf("%d%d", &R, &C);
	}
	return 0;
}