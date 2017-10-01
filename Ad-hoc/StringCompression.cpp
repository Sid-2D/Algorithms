#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string str;
	char compress[30];
	cin >> str;
	char prev = '1';
	int count = 1, j = 0, len = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == prev) {
			count++;
			if (count > 2) {
				j -= len;
			}
			int temp = count;
			len = ceil(log10(count));
			while (temp) {
				int digit = temp % 10;
				// if (count == 10) {
				// 	cout << "temp = " << temp << ", dig = " << digit << "\n";
				// 	cout << j + len - 1 << " = " << (char)(digit + 48) << "\n";
				// }
				temp = temp / 10;
				compress[j + len - 1] = (char)(digit + 48);
				j++;
			}
		} else {
			count = 1;
			prev = str[i];
			compress[j++] = str[i];
		}
	}
	compress[j] = '\0';
	cout << compress;
	return 0;
}