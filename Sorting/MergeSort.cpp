// Implementation of Merge Sort.

#include <cstdio>
#include <iostream>
using namespace std;

void merge (int arr[], int l, int mid, int r) {
	int L[10], R[10], n1 = mid - l + 1, n2 = r - mid;
	for (int i = 0; i < n1; i++) {
		L[i] = arr[l + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = arr[mid + 1 + i];
	}
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = R[j++];
		}
	}
	while (i < n1) {
		arr[k++] = L[i++];
	}
	while (j < n2) {
		arr[k++] = R[j++];
	}
}

void mergesort (int arr[], int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergesort(arr, l, mid);
		mergesort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}

int main () {
	int arr[] = {3, 2, 1, 5, 4};
	mergesort(arr, 0, 4);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << "\t";
	}
	return 0;
}