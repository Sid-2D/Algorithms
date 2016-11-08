// Application of Prim's Algorithm
// Tested on this problem: http://www.spoj.com/problems/MST/

#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
typedef long long int lld;

vector <lld> Taken;
priority_queue < pair<lld, lld> > PQ;
vector < vector < pair <lld, lld> > > AdjList (10008);
pair <lld, lld> tempPair;

void process (lld v) {
	Taken[v] = 1;
	for (int i = 0; i < AdjList[v].size(); i++) {
		tempPair = AdjList[v][i];
		if (!Taken[tempPair.first]) {
			PQ.push(make_pair(-tempPair.second, -tempPair.first));
		}
	}
}

int main () {	
	lld m, n, u, v, weight, mst = 0;
	cin >> m >> n;
	Taken.assign(m + 5, 0);
	while (n--) {
		cin >> u >> v >> weight;
		AdjList[u].push_back(make_pair(v, weight));
		AdjList[v].push_back(make_pair(u, weight));
	}
	process(1);
	while (!PQ.empty()) {
		tempPair = PQ.top();
		PQ.pop();
		u = -tempPair.second;
		weight = -tempPair.first;
		if (!Taken[u]) {
			process(u);
			mst += weight;
		}
	}
	cout << mst << endl;
	return 0;
}