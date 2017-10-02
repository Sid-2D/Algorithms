#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
	string str;
	char compress[30], countString[33];
	cin >> str;
	char prev = '1';
	int count = 1, j = 0, len = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == prev) {
			count++;
		} else {
			sprintf(countString, "%d", count);
			strcat(compress, countString);
			count = 1;
			j += strlen(countString);
			prev = str[i];
			compress[j++] = str[i];
		}
	}
	sprintf(countString, "%d", count);
	strcat(compress, countString);
	j += strlen(countString);
	compress[j] = '\0';
	cout << compress;
	return 0;
}