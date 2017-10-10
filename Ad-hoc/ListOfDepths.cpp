#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>

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

void preorderRecursion(n *root) {
	cout << root -> data << " ";
	if (root -> left != NULL) {
		preorderRecursion(root -> left);
	}
	if (root -> right != NULL) {
		preorderRecursion(root -> right);
	}
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

typedef struct listNode list;

struct listNode {
	n *data;
	list *next;
};

list* initList(n *treeNode) {
	list *temp = (list*)malloc(sizeof(list));
	temp -> data = treeNode;
	temp -> next = NULL;
	return temp;
}

void display(list *root) {
	while (root != NULL) {
		cout << root -> data -> data << " ";
		root = root -> next;
	}
	cout << "\n";
}

void makeLists() {
	queue <n*> Q1, Q2;
	Q1.push(root);
	bool one = true;
	n *treeNode;
	vector <list*> lists;
	list *currentList = NULL, *lastNode = NULL;
	while (1) {
		if (one) {
			if (Q1.empty()) {
				lists.push_back(currentList);
				currentList = lastNode = NULL;
				if (Q2.empty()) {
					break;
				}
				one = false;
				continue;
			}
			treeNode = Q1.front();
			Q1.pop();
			if (treeNode -> left != NULL) {
				Q2.push(treeNode -> left);
			}
			if (treeNode -> right != NULL) {
				Q2.push(treeNode -> right);
			}
		} else {
			if (Q2.empty()) {
				lists.push_back(currentList);
				currentList = lastNode = NULL;
				if (Q1.empty()) {
					break;
				}
				one = true;
				continue;
			}
			treeNode = Q2.front();
			Q2.pop();
			if (treeNode -> left != NULL) {
				Q1.push(treeNode -> left);
			}
			if (treeNode -> right != NULL) {
				Q1.push(treeNode -> right);
			}
		}
		if (currentList == NULL) {
			currentList = initList(treeNode);
			lastNode = currentList;	
		} else {
			lastNode -> next = initList(treeNode);
			lastNode = lastNode -> next;
		}
	}
	for (vector <list*>::const_iterator it = lists.begin(); it != lists.end(); it++) {
		display(*it);
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6};
	root = addNode(arr, 0, 5);
	preorderRecursion(root);
	cout << "\n";
	makeLists();
	return 0;
}