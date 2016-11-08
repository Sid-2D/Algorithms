// Was earlier trying to do this with BFS but found a better ad-hoc way to do it.
// Tested on this problem: http://www.spoj.com/problems/CATM

#include <iostream>
#include <cmath>
using namespace std;

int R, C, k;
int mx, my, c1x, c1y, c2x, c2y;

int distance (int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

bool check (int x, int y) {
	if (distance(mx, my, x, y) < distance(c1x, c1y, x, y) && distance(mx, my, x, y) < distance(c2x, c2y, x, y)) {
		return true;
	}
	return false;
}

int main() {
	cin >> R >> C;
	cin >> k;
	while (k--) {		
		cin >> mx >> my >> c1x >> c1y >> c2x >> c2y;
		if (check (1, my) || check (mx, C) || check (mx, 1) || check (R, my)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}