// Implementation of Strassen's Algorithm for multiplying simple 2D Matrices.

#include <iostream>
using namespace std;

void print(int arr[][2]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void strassen(int arr1[][2], int arr2[][2]) {
	int a, b, c, d, e, f, g, h;
	a = arr1[0][0];
	b = arr1[0][1];
	c = arr1[1][0];
	d = arr1[1][1];
	e = arr2[0][0];
	f = arr2[0][1];
	g = arr2[1][0];
	h = arr2[1][1];
	int m1, m2, m3, m4, m5, m6, m7;
	m1 = a * (f - h);
	m2 = (a + b) * h;
	m3 = (c + d) * e;
	m4 = d * (g - e);
	m5 = (a + d) * (e + h);
	m6 = (b - d) * (g + h);
	m7 = (a - c) * (e + f);
	int ans[2][2];
	ans[0][0] = m5 + m4 - m2 + m6;
	ans[0][1] = m1 + m2;
	ans[1][0] = m3 + m4;
	ans[1][1] = m1 + m5 - m3 - m7;
	print(ans);
}

int main () {
	int arr1[2][2];
	int arr2[2][2], i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			cin >> arr1[i][j];
		}
	}
	print(arr1);
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			cin >> arr2[i][j];
		}
	}
	print(arr2);
	strassen(arr1, arr2);
	return 0;
}