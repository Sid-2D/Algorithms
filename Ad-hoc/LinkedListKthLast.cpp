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
		n *Node = init(arr[i]);
		temp -> next = Node;
		temp = temp -> next;
	}
	n *runner1 = root, *runner2 = root;
	int k = 3, difference = 0;
	while (runner1 -> next != NULL) {
		difference++;
		runner1 = runner1 -> next;
		if (difference >= 3) {
			runner2 = runner2 -> next;
		}
	}
	display(root);
	cout << runner2 -> data << "\n";
	return 0;
}