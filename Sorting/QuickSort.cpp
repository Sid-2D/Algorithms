// Implementaion of Quick Sort.

#include <iostream>
using namespace std;

void swap(int arr[], int i, int j) {
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

int partition(int arr[], int lo, int hi) {
	int pivot = arr[hi];
	int i = lo - 1;
	for (int j = lo; j < hi; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, hi);
	return i + 1;
}

void quickSort(int arr[], int lo, int hi) {
	if (lo < hi) {
		int p = partition(arr, lo, hi);
		quickSort(arr, lo, p - 1);
		quickSort(arr, p + 1, hi);
	}
}

int main () {
	int arr[] = {3, 2, 1, 5, 4};
	quickSort(arr, 0, 4);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << "\t";
	}
	return 0;
}