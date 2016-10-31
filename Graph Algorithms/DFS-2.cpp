// Application of Depth First Search
// Tested on this problem: http://www.spoj.com/problems/ALLIZWEL/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string STR = "ALLIZZWELL"; 
char MATRIX[108][108];
int VISITED[108][108];
int R, C;
bool ANS = false;

void dfs (int pos, int i, int j) {
	if (pos + 1 == STR.length()) {
		ANS = true;
		return;
	}
	VISITED[i][j] = 1;
	if (i < R - 1 && j < C - 1) {
		if (MATRIX[i + 1][j + 1] == STR[pos + 1] && VISITED[i + 1][j + 1] == 0) {
			dfs(pos + 1, i + 1, j + 1);
		}
	}
	if (i < R - 1) {
		if (MATRIX[i + 1][j] == STR[pos + 1] && VISITED[i + 1][j] == 0) {
			dfs(pos + 1, i + 1, j);	
		}	
	}
	if (j < C - 1) {
		if (MATRIX[i][j + 1] == STR[pos + 1] && VISITED[i][j + 1] == 0) {
			dfs(pos + 1, i, j + 1);
		}
	}
	if (i > 0 && j > 0) {
		if (MATRIX[i - 1][j - 1] == STR[pos + 1] && VISITED[i - 1][j - 1] == 0) {
			dfs(pos + 1, i - 1, j - 1);
		}
	}
	if (j > 0) {
		if (MATRIX[i][j - 1] == STR[pos + 1] && VISITED[i][j - 1] == 0) {
			dfs(pos + 1, i, j - 1);
		}
	}
	if (i > 0) {
		if (MATRIX[i - 1][j] == STR[pos + 1] && VISITED[i - 1][j] == 0) {
			dfs(pos + 1, i - 1, j);
		}
	}	
	if (i < R - 1 && j > 0) {
		if (MATRIX[i + 1][j - 1] == STR[pos + 1] && VISITED[i + 1][j - 1] == 0) {
			dfs(pos + 1, i + 1, j - 1);
		}	
	}
	if (i > 0 && j < C - 1) {
		if (MATRIX[i - 1][j + 1] == STR[pos + 1] && VISITED[i - 1][j + 1] == 0) {
			dfs(pos + 1, i - 1, j + 1);
		}
	}
	VISITED[i][j] = 0;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> R >> C;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> MATRIX[i][j];
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (MATRIX[i][j] == 'A') {
					dfs(0, i, j);
					if (ANS) {
						break;
					}
					memset(VISITED, 0, 108 * 108);
				}
			}
			if (ANS) {
				break;
			}
		}
		if (ANS) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		ANS = false;
	} 
	return 0;
}