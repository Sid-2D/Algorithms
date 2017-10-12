#include <iostream>
#include <cstdlib>
#include <climits>

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

bool checkBST(n *root, int min, int max) {
	if (root -> left == NULL && root -> right == NULL) {
		return (root -> data > min) && (root -> data <= max);
	}
	bool left = true, right = true;
	if (root -> left != NULL) {
		left = checkBST(root -> left, min, root -> data);
	}
	if (root -> right != NULL) {
		right = checkBST(root -> right, root -> data, max);
	}
	return left && right;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	// root = addNode(arr, 0, 4);
	cout << "Inorder:\n";
	root = init(3);
	root -> left = init(1);
	root -> left -> right = init(1);
	root -> right = init(4);
	root -> right -> right = init(5);
	inorderRecursion(root);
	bool isBST = checkBST(root, INT_MIN, INT_MAX);
	if (isBST) {
		cout << "\nIt is a BST.";
	} else {
		cout << "\nIt is not a BST.";
	}
	return 0;
}