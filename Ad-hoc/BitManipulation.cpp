#include <iostream>

using namespace std;

void leastBitsInvert() {
	int x = 29, y = 15;
	int mask = 1 << 24;
	int count = 0;
	while (mask) {
		if ((mask&x) != (mask&y)) {
			count++;
		}
		mask = (mask>>1);
	}
	cout << count;
	// Using XOR
	count = 0;
	for (int i = x ^ y; i != 0; i = (i >> 1)) {
		count += (i & 1);
	}
	cout << "\n" << count;
	count = 0;
	for (int i = x ^ y; i != 0; i = i & (i - 1)) {
		count++;
	}
	cout << "\n" << count;	
}

int main() {
	leastBitsInvert();
	return 0;
}