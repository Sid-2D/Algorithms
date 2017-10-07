#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

typedef struct node n;

struct node {
	int data;
	n *left;
	n *right;
} *root;

n* init(int data) {
	n *vertex = (n*)malloc(sizeof(n));
	vertex -> data = data;
	vertex -> left = vertex -> right = NULL;
	return vertex;
}

void inorderRecursion(n *root) {
	if (root -> left != NULL) {
		inorderRecursion(root -> left);
	}
	cout << root -> data << " ";
	if (root -> right != NULL) {
		inorderRecursion(root -> right);
	}
}

void preorderRecursion(n *root) {
	cout << root -> data << " ";
	if (root -> left != NULL) {
		preorderRecursion(root -> left);
	}
	if (root -> right != NULL) {
		preorderRecursion(root -> right);
	}
}

void postorderRecursion(n *root) {
	if (root -> left != NULL) {
		postorderRecursion(root -> left);
	}
	if (root -> right != NULL) {
		postorderRecursion(root -> right);
	}
	cout << root -> data << " ";
}

n* addNode(int arr[], int start, int end) {
	int mid = (start + end) / 2;
	n *temp = init(arr[mid]);
	if (start < mid) {
		temp -> left = addNode(arr, start, mid - 1);
	}
	if (mid < end) {
		temp -> right = addNode(arr, mid + 1, end);
	}
	return temp; 
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6};
	root = addNode(arr, 0, 5);
	cout << "Inorder:\n"; 
	inorderRecursion(root);
	cout << "\nPreorder:\n"; 
	preorderRecursion(root);
	cout << "\nPostorder:\n"; 
	postorderRecursion(root);
	return 0;
}