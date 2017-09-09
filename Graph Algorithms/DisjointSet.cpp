// Link: https://www.hackerrank.com/domains/data-structures/disjoint-set

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int VISITED[30006];
vector < vector <int> > ADJ_LIST(30006); 

int bfs (int start) {
	queue <int> Q;
	Q.push(start);
	VISITED[start] = 1;
	int connectedComponents = 0;
	while (!Q.empty()) {
		int node = Q.front();
		connectedComponents++;
		Q.pop();
		for (int i = 0; i < ADJ_LIST[node].size(); i++) {
			if (!VISITED[ADJ_LIST[node][i]]) {
				Q.push(ADJ_LIST[node][i]);
				VISITED[ADJ_LIST[node][i]] = 1;
			}
		}
	}
	return connectedComponents;
}

int main () {
	int n, g, b, max = 0, min = 30006;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> g >> b;
		ADJ_LIST[g].push_back(b);
		ADJ_LIST[b].push_back(g);
	}
	for (int i = 1; i <= n; i++) {
		if (!VISITED[i] && ADJ_LIST[i].size()) {
			int connectedComponents = bfs(i);
			if (connectedComponents > max) {
				max = connectedComponents;
			}
			if (connectedComponents < min) {
				min = connectedComponents;
			}
		}
	}
	cout << min << " " << max;
	return 0;
}