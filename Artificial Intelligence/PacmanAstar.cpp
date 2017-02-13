// Algorithm for Pacman to reach food particle in a 2D Grid using A* search
// Problem Link - https://www.hackerrank.com/challenges/pacman-astar

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

vector<string> Grid;

priority_queue < pair<int, pair<int, int> > > PQ;

vector< pair<int, int> > Path, Parents;

pair< int, pair<int, int> > temp;
int checkTable[40][40];
int Pr, Pc, Fr, Fc, r, c, steps = 0;

int getManhattanPriority(int r, int c) {
	return -1 * (abs(r - Fr) + abs(c - Fc));
}

void Astar() {
	temp = PQ.top();
	PQ.pop();
	int i = temp.second.first;
	int j = temp.second.second;
	if (i == Fr && j == Fc) {
		return;
	}
	if (i - 1 >= 0) {
		if (!checkTable[i - 1][j] && Grid[i - 1][j] != '%') {
			int distance = steps;
			if (Grid[i][j] != '.') {
				distance++;
			}
			PQ.push(make_pair(distance + getManhattanPriority(i - 1, j), make_pair(i - 1, j)));
			Parents[(i - 1) * c + j] = make_pair(i, j);
			checkTable[i - 1][j]++;
		}
	}
	if (j - 1 >= 0) {
		if (!checkTable[i][j - 1] && Grid[i][j - 1] != '%') {
			int distance = steps;
			if (Grid[i][j] != '.') {
				distance++;
			}
			PQ.push(make_pair(distance + getManhattanPriority(i, j - 1), make_pair(i, j - 1)));
			Parents[i * c + (j - 1)] = make_pair(i, j);
			checkTable[i][j - 1]++;
		}
	}
	if (j + 1 < c) {
		if (!checkTable[i][j + 1] && Grid[i][j + 1] != '%') {
			int distance = steps;
			if (Grid[i][j] != '.') {
				distance++;
			}
			PQ.push(make_pair(distance + getManhattanPriority(i, j + 1), make_pair(i, j + 1)));
			Parents[i * c + (j + 1)] = make_pair(i, j);
			checkTable[i][j + 1]++;
		}
	}
	if (i + 1 < r) {
		if (!checkTable[i + 1][j] && Grid[i + 1][j] != '%') {
			int distance = steps;
			if (Grid[i][j] != '.') {
				distance++;
			}
			PQ.push(make_pair(distance + getManhattanPriority(i + 1, j), make_pair(i + 1, j)));
			Parents[(i + 1) * c + j] = make_pair(i, j);
			checkTable[i + 1][j]++;
		}
	}
	if (!PQ.empty()) {
		steps++;
		Astar();
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
	PQ.push(make_pair(steps + getManhattanPriority(Pr, Pc), make_pair(Pr, Pc)));
	steps++;
	Astar();
	pair<int, int> temp;
	temp = Parents[Fr * c + Fc];
	Path.push_back(make_pair(Fr, Fc));
	while (temp.first != -1) {
		Path.push_back(temp);
		temp = Parents[temp.first * c + temp.second];
	}
	cout << Path.size() - 1 << endl;
	for (int i = Path.size() - 1; i >= 0; i--) {
		cout << Path[i].first << " " << Path[i].second << "\n";
	}
}