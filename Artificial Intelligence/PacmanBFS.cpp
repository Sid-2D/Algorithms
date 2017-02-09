// Algorithm for Pacman to reach food particle in a 2D Grid using BFS
// Problem Link - https://www.hackerrank.com/challenges/pacman-bfs

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

// Grid
vector<string> Grid;

// Stack
vector< pair <int, int> > ans, path, Parents;

// Queue
queue<pair <int, int> > Queue;

pair<int, int> temp;
int checkTable[40][40];
int Pr, Pc, Fr, Fc, r, c;

void bfs() {
	temp = Queue.front();
	Queue.pop();
	int i = temp.first;
	int j = temp.second;
	ans.push_back(make_pair(i, j));
	if (i == Fr && j == Fc) {
		return;
	}
	if (i - 1 >= 0) {
		if (!checkTable[i - 1][j] && Grid[i - 1][j] != '%') {
			Queue.push(make_pair(i - 1, j));
			Parents[(i - 1) * c + j] = make_pair(i, j);
			checkTable[i - 1][j]++;
		}
	}
	if (j - 1 >= 0) {
		if (!checkTable[i][j - 1] && Grid[i][j - 1] != '%') {
			Queue.push(make_pair(i, j - 1));
			Parents[i * c + (j - 1)] = make_pair(i, j);
			checkTable[i][j - 1]++;
		}
	}
	if (j + 1 < c) {
		if (!checkTable[i][j + 1] && Grid[i][j + 1] != '%') {
			Queue.push(make_pair(i, j + 1));
			Parents[i * c + (j + 1)] = make_pair(i, j);
			checkTable[i][j + 1]++;
		}
	}
	if (i + 1 < r) {
		if (!checkTable[i + 1][j] && Grid[i + 1][j] != '%') {
			Queue.push(make_pair(i + 1, j));
			Parents[(i + 1) * c + j] = make_pair(i, j);
			checkTable[i + 1][j]++;
		}
	}
	if (!Queue.empty()) {
		bfs();
	}
}

int main() {
	cin >> Pr >> Pc;
	cin >> Fr >> Fc;
	cin >> r >> c;
	string str;
	for(int i = 0; i < r; i++) {
		cin >> str;
		Grid.push_back(str);
	}
	Parents.assign(r * c, make_pair(0, 0));
	Parents[Pr * c + Pc] = make_pair(-1, -1);
	checkTable[Pr][Pc] = 1;
	Queue.push(make_pair(Pr, Pc));
	bfs();
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	temp = Parents[Fr * c + Fc];
	path.push_back(make_pair(Fr, Fc));
	while (temp.first != -1) {
		path.push_back(temp);
		temp = Parents[temp.first * c + temp.second];
	}
	cout << path.size() - 1 << endl;
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i].first << " " << path[i].second << "\n";
	}
}