// Application of Kruskal's Algorithm
// Tested on this problem: http://www.spoj.com/problems/MST/

#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lld;

class UnionFind {
	vector <lld> p, rank;
public:
	UnionFind (lld N) {
		rank.assign(N, 0);
		p.assign(N, 0);
		for (lld i = 0; i < N; i++) {
			p[i] = i;
		}
	}
	lld findSet (lld i) {
		return p[i] == i ? i : findSet(p[i]);
	}
	bool isSameSet (lld i, lld j) {
		return findSet(i) == findSet(j);
	}
	void unionSet (lld i, lld j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i);
			int y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
			} else {
				p[x] = y;
				if (rank[x] == rank[y]) {
					rank[y]++;
				}
			}
		}
	}
};

int main () {
	lld m, n, u, v, weight;
	cin >> m >> n;
	vector < pair<lld, pair<lld, lld> > > Edges;
	for (lld i = 0; i < n; i++) {
		cin >> u >> v >> weight;
		Edges.push_back(make_pair(weight, make_pair(u, v)));
	}
	sort(Edges.begin(), Edges.end());
	UnionFind UF(m + 5);
	lld ans = 0;
	for (vector < pair<lld, pair<lld, lld> > >::iterator it = Edges.begin(); it != Edges.end(); it++) {
		pair<lld, pair<lld, lld> > ele = *it;
		if (!UF.isSameSet(ele.second.first, ele.second.second)) {
			ans += ele.first;
			UF.unionSet(ele.second.first, ele.second.second);
		}
	}
	cout << ans << "\n";
	return 0;
}