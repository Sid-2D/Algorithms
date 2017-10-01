#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	char str[100];
	gets(str);
	int spaces = 0, length = strlen(str);
	for (int i = 0; i < length; i++) {
		if (str[i] == ' ') {
			spaces++;
		}
	}
 	str[length + spaces * 2] = '\0';
	for (int i = length - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			spaces--;
			str[i + spaces * 2] = '%';
			str[i + spaces * 2 + 1] = '2';
			str[i + spaces * 2 + 2] = '0';
		} else {
			str[i + spaces * 2] = str[i];
		}
 	}
 	cout << "\n" << str;
 	return 0;
}