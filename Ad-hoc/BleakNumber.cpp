// Link: http://practice.geeksforgeeks.org/problems/bleak-numbers/0

#include <iostream>
#include <cmath>

using namespace std;

int getSetBits(long long unsigned int num) {
    long long unsigned int mask = 1 << 16;
    int ans = 0;
    while (mask) {
        if (mask & num) {
            ans++;
        }
        mask = (mask>>1);
    }
    return ans;
}

int main() {
	//code
	long long unsigned int n, t;
	cin >> t;
	while (t--) {
	    cin >> n;
	    int start = 0, ans = 1;
	    if (n >= 16) {
	        start = n - 16;
	    }
	    for (long long unsigned int i = start; i <= n; i++) {
	        if (i + getSetBits(i) == n) {
	            ans = 0;
	            break;
	        }
	    }
	    cout << ans << "\n";
	}
	return 0;
}