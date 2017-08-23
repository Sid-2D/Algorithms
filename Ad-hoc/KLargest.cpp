#include <iostream>

using namespace std;

void swap (unsigned int arr[], int i, int j) {
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

int main() {
	int t, k, size;
	unsigned int arr[108];
	cin >> t;
	while (t--) {
		cin >> size >> k;
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < size; j++) {
				if (arr[j] > arr[i]) {
					swap(arr, i, j);
				}
			}
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}