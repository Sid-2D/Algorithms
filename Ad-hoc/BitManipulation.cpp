#include <iostream>

using namespace std;

void intToBinary(int num) {
	int mask = (1 << 30);
	bool start = false;
	while (mask) {
		if (mask & num) {
			start = true;
			cout << 1;
		} else {
			if (start) {
				cout << 0;
			}
		}
		mask = (mask >> 1);
	}
	cout << "\n";
}

int binaryToInt(char binary[]) {
	int num = 0;
	for (int i = 0; binary[i] != '\0'; i++) {
		num = (num << 1);
		if (1 & (binary[i] - 48)) {
			num++;
		}
	}
	return num;
}

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

void insertBits() {
	int m, n, j = 6, i = 2;
	m = binaryToInt("10011");
	n = binaryToInt("10000000000");
	cout << "10011" << endl << "10000000000" << endl;
	int ones = ~0;
	// Set all ones left of bit j
	int left = ones << (j + 1);
	// Set all ones right of bit i
	int right = ((1 << i) - 1);
	int mask = (left | right);
	int n_cleared = (mask & n);
	int m_shifted = (m << i);
	int ans = (n_cleared | m_shifted);
	intToBinary(ans);
}

void pairWiseSwap() {
	int x = 9;
	int ans = ( ((x & 0xaa) >> 1) | ((x & 0x55) << 1) );
	cout << ans;
}

int main() {
	leastBitsInvert();
	insertBits();
	pairWiseSwap();
	return 0;
}