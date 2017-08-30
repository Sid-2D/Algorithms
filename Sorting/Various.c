#include <stdio.h>

void bsearch(int a[], int x) {
	int i=1, j, n = 5, start = 0, last = 4, mid;
	while(start<=last) {
		mid = (start + last) / 2;
		if(a[mid]==x) {
			printf("Ele. found at pos %d!\n", mid + 1);
			i = 0;
			break;
		}
		if(a[mid] < x) {
			start = mid+1;
		}
		else {
			last = mid-1;
		}
	}
	if(i) {
		printf("Ele. not found!\n");
	}
}

void display(int a[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void bubblesort(int a[], int n) {
	int i, j, tmp, swapped;
	for(i = 0; i < n; i++) {
		swapped = 0;
		for(j = 0; j < n - i - 1; j++) {
			if(a[j] > a[j + 1]) {
				swapped = 1;
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
			}
		}
		// Optimization for sorted arrays
		if (!swapped) {
			break;
		}
	}
	display(a, n);
}

void insertionsort(int a[], int n) {
	int i, j, tmp, k, x;
	for(i = 1; i < n; i++) {
		j = i - 1;
		x = a[i];
		while(j >= 0 && x < a[j]) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1]=x;
	}
	display(a, n);
}

int partition(int a[], int start, int last) {
	int pivot, i, j, tmp, dp = start;
	pivot = a[dp];
	for(i = start + 1; i <= last; i++) {
		if(a[i] < pivot) {
			dp++;
			tmp = a[dp];
			a[dp] = a[i];
			a[i] = tmp;
		}
	}
	tmp = a[dp];
	a[dp] = a[start];
	a[start] = tmp;
	return dp;
}

void quicksort(int a[], int start, int last) {
	int pivot;
	if(start < last) {
		pivot = partition(a, start, last);
		quicksort(a, start, pivot - 1);
		quicksort(a, pivot + 1, last);
	}
}

void merge(int a[], int l, int m, int r) {
	int i, j, k, n1, n2, L[10], R[10];
	n1 = m - l + 1;
	n2 = r - m;
	for(i = 0;i < n1; i++) {
		L[i] = a[l + i];
	}
	for(j = 0;j < n2; j++) {
		R[j] = a[m + 1 + j];
	}
	i = j = 0;
	k = l;
	while(i < n1 && j < n2) {
		if(L[i] < R[j]) {
			a[k++] = L[i++];
		}
		else {
			a[k++] = R[j++];
		}
	}
	while(i < n1) {
		a[k++] = L[i++];
	}
	while(j < n2) {
		a[k++] = R[j++];
	}
}

void mergesort(int a[], int l, int r) {
	if(l < r) {
		int m = (l + r) / 2;
		mergesort(a, l, m);
		mergesort(a, m+1, r);
		merge(a, l, m, r);
	}
}

void radixsort(int a[], int size) {
	int *bucket[10], i, j, end = 1, div = 1, index, r;
	//Initialise the buckets.
	for(i = 0;i < 10; i++) {
		bucket[i] = (int*)malloc(sizeof(int)*(size + 1));
	}
	while(end) {
		int freq[10] = {0};	//Number of elements in each bucket.
		end = 0;
		for(i = 0;i < size; i++) {
			index = (a[i] / div) % 10;
			if(a[i] / (div * 10)) {	//Check if we have a number with more digits left.
				end=1;
			}
			bucket[index][freq[index]++] = a[i];
		}
		div *= 10;
		r = 0;
		//Change the array according to the buckets.
		for (i = 0; i < 10; i++)
			for(j = 0; j < freq[i]; j++) {
				a[r++] = bucket[i][j];
			}
	}
}
void countingsort(int a[], int size) {
	int i, cnt[30] = {0}, out[9];
	//Get the frequency.
	for(i = 0; i < size; i++) {
		cnt[a[i]]++;
	}
	//Calculate the indices.
	for(i = 1; i < size; i++) {
		cnt[i] += cnt[i - 1];
	}
	//Rearrange and sort the array.
	for(i = 0;i < size; i++) {
		out[(cnt[a[i]]--) - 1] = a[i];
	}
	for(i = 0; i < size; i++) {
		a[i] = out[i];
	}
}

int main() {
	int a[9] = {12, 7, 10, 5, 6, 1, 25, 23, 9}, i, j, n=9, x, t;
	printf("Before:\n");
	display(a, n);
	countingsort(a, n);
	printf("After:\n");
	display(a, n);
	return 0;
}