// Application of Breadth First Search
// Tested on this problem: http://www.spoj.com/problems/ELEVTRBL/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

long long int VISITED[10000008];

int main () {
	long long int f, s, g, u, d;
	queue <long long int> Q;
	cin >> f >> s >> g >> u >> d;
	Q.push(s);
	bool ans = false;
	memset(VISITED, -1, sizeof(long long int) * 10000008);
	VISITED[s] = 0;
	while (!Q.empty()) {
		int floor = Q.front();
		if (floor == g) {
			ans = true;
			break;
		}
		Q.pop();
		if (floor + u <= f && VISITED[floor + u] == -1) {
			Q.push(floor + u);
			VISITED[floor + u] = VISITED[floor] + 1;
		}
		if (floor - d >= 1 && VISITED[floor - d] == -1) {
			Q.push(floor - d);
			VISITED[floor - d] = VISITED[floor] + 1;
		}
	} 
	if (ans) {
		cout << VISITED[g];
	} else {
		cout << "use the stairs";
	}
	return 0;
}