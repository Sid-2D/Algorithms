// Application of Depth First Search
// Tested on this problem: http://www.spoj.com/problems/BUGLIFE/

#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;
vector < vector<int> > ADJ_LIST(2007);
int VISIT[2007][2];
bool ANS = true;

int switchGender (int gender) {
	return (gender == 1) ? 0 : 1;
}

void dfs (int vertex, int gender, bool start) {
	if (start) {
		for (int i = 0; i < ADJ_LIST[vertex].size(); i++) {
			int neighbour = ADJ_LIST[vertex][i];
			if (VISIT[neighbour][0]) {
				VISIT[vertex][1] = gender = switchGender(VISIT[neighbour][1]);
			}
		}
	} else {
		VISIT[vertex][1] = gender;		
	}
	VISIT[vertex][0] = 1;
	for (int i = 0; i < ADJ_LIST[vertex].size(); i++) {
		int neighbour = ADJ_LIST[vertex][i];
		if (VISIT[neighbour][0] == 0) {
			dfs(neighbour, switchGender(gender), false);
		} else if (VISIT[neighbour][1] == gender) {
			ANS = false;
			return;
		}
	}
}

int main () {
	long long int j, t, n, i, scenario = 1;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		int v1, v2;
		for (j = 0; j < i; j++) {
			scanf("%d%d", &v1, &v2);
			ADJ_LIST[v1].push_back(v2);
		}
		for (j = 1; j <= n; j++) {
			if (VISIT[j][0] == 0 && ANS) {
				dfs(j, 0, true);
			}
		}
		if (ANS) {
			cout << "Scenario #" << scenario++ << ":";
			cout << "\nNo suspicious bugs found!\n";
		} else {
			cout << "Scenario #" << scenario++ << ":";
			cout << "\nSuspicious bugs found!\n";
		}
		for (int j = 1; j <= n; j++) {
			ADJ_LIST[j].clear();
		}
		memset(VISIT, 0, sizeof(int) * 2007 * 2);
		ANS = true;
	}
}