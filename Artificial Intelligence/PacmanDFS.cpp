// Algorithm for Pacman to reach food particle in a 2D Grid using DFS
// Problem Link - https://www.hackerrank.com/challenges/pacman-dfs

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// Grid
vector<string> Grid;

// Stack
vector< pair <int, int> > Stack, ans, path, Parents;

pair<int, int> temp;
int checkTable[40][40];
int Pr, Pc, Fr, Fc, r, c;

void dfs() {
	temp = Stack.back();
	Stack.pop_back();
	int i = temp.first;
	int j = temp.second;
	ans.push_back(make_pair(i, j));
	if (i == Fr && j == Fc) {
		Stack.clear();
		return;
	}
	if (i - 1 >= 0) {
		if (!checkTable[i - 1][j] && Grid[i - 1][j] != '%') {
			Stack.push_back(make_pair(i - 1, j));
			Parents[(i - 1) * c + j] = make_pair(i, j);
			checkTable[i - 1][j]++;
		}
	}
	if (j - 1 >= 0) {
		if (!checkTable[i][j - 1] && Grid[i][j - 1] != '%') {
			Stack.push_back(make_pair(i, j - 1));
			Parents[i * c + (j - 1)] = make_pair(i, j);
			checkTable[i][j - 1]++;
		}
	}
	if (j + 1 < c) {
		if (!checkTable[i][j + 1] && Grid[i][j + 1] != '%') {
			Stack.push_back(make_pair(i, j + 1));
			Parents[i * c + (j + 1)] = make_pair(i, j);
			checkTable[i][j + 1]++;
		}
	}
	if (i + 1 < r) {
		if (!checkTable[i + 1][j] && Grid[i + 1][j] != '%') {
			Stack.push_back(make_pair(i + 1, j));
			Parents[(i + 1) * c + j] = make_pair(i, j);
			checkTable[i + 1][j]++;
		}
	}
	if (!Stack.empty()) {
		dfs();
	}
}

int main() {
	cin >> Pr >> Pc;
	cin >> Fr >> Fc;
	cin >> r >> c;
	Parents.assign(r * c, make_pair(0, 0));
	string str;
	for(int i = 0; i < r; i++) {
		cin >> str;
		Grid.push_back(str);
	}
	Parents[Pr * c + Pc] = make_pair(-1, -1);
	checkTable[Pr][Pc] = 1;
	Stack.push_back(make_pair(Pr, Pc));
	dfs();
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	pair<int, int> temp = Parents[Fr * c + Fc];
	path.push_back(make_pair(Fr, Fc));
	while (temp.first != -1) {
		path.push_back(temp);
		temp = Parents[temp.first * c + temp.second];
	}
	cout << path.size() - 1 << endl;
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i].first << " " << path[i].second << "\n";
	}
	return 0;
}