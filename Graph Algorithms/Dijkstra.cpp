// Application of Dijkstra's Algorithm
// Tested on this problem: http://www.spoj.com/problems/SHPATH/

#include <iostream>
#include <utility>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
#include <functional>
using namespace std;
typedef long long int lld;

vector < vector < pair<lld, lld> > > AdjList;
vector < pair<lld, lld> > temp;
 
void dijkstra (lld source, lld destination) {
	vector <lld> cost(10008, INT_MAX);
	priority_queue< pair<lld, lld>, vector< pair<lld, lld> >, greater< pair<lld, lld> > > pq;
	pq.push(make_pair(0, source));
	cost[source] = 0;
	while (!pq.empty()) {
		pair <lld, lld> top = pq.top();
		pq.pop();
		lld d = top.first;
		lld u = top.second;
		if (d > cost[u]) {
			continue;
		}
		if (u == destination) {
			break;
		}
		for (lld j = 0; j < AdjList[u].size(); j++) {
			pair <lld, lld> v = AdjList[u][j];
			if (cost[u] + v.second < cost[v.first]) {
				cost[v.first] = cost[u] + v.second;
				pq.push(make_pair(cost[v.first], v.first));
			}
		} 
	}
	cout << cost[destination] << "\n";
}

int main () {
	lld s, n, p, nr, cost, r;
	string city;
	cin >> s;
	while (s--) {
		cin >> n;
		AdjList.assign(n + 5, temp);
		unordered_map <string, lld> cityMap;
		for (lld i = 1; i <= n; i++) {
			cin >> city;
			cityMap[city] = i;
			cin >> p;
			for (lld j = 0; j < p; j++) {
				cin >> nr >> cost;
				AdjList[i].push_back(make_pair(nr, cost));
				AdjList[nr].push_back(make_pair(i, cost));
			}
		}
		cin >> r;
		string city1, city2;
		for (lld i = 0; i < r; i++) {
			cin >> city1 >> city2;
			lld source = cityMap[city1];
			lld destination = cityMap[city2];
			dijkstra(source, destination);
		}
	}
	return 0;
}