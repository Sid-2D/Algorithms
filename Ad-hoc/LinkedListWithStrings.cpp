#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct node n;

struct node {
	string str;
	n *next;
} *temp, *root;

n* init(string str) {
	temp = (n*)malloc(sizeof(n));
	temp -> str = str;
	temp -> next = NULL;
	return temp;
}

void display() {
	temp = root;
	while (temp != NULL) {
		cout << temp -> str << "\n";
		temp = temp -> next;
	}
}

int main() {
	root = init("Sid");
	string arr[] = {"garrison", "cartman", "butters"};
	n *current = root;
	for (int i = 0; i < 3; i++) {
		current -> next = init(arr[i]);
		current = current -> next;
	}
	display();
	return 0;
}