#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node n;

struct Node {
	int data;
	n *next;
};

n* init(int data) {
	n *temp = (n*)malloc(sizeof(n));
	temp -> data = data;
	temp -> next = NULL;
	return temp;
}

void display(n *root) {
	while (root != NULL) {
		cout << root -> data << " ";
		root = root -> next;
	}
	cout << "\n";
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6};
	n *root = init(arr[0]);
	n *temp = root, *mid;
	for (int i = 1; i <= 5; i++) {
		temp -> next = init(arr[i]);
		temp = temp -> next;
		if (i == 3) {
			mid = temp;
		}
	}
	display(root);
	*mid = *(mid -> next);
	display(root);
	return 0;
}