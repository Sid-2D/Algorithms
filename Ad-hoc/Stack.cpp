#include <iostream>

using namespace std;

#define MAX 1000

class Stack {
	int top;
public:
	int arr[MAX];

	Stack() {
		top = -1;
	}

	bool push(int x) {
		if (top >= MAX) {
			cout << "Stack overflow";
			return false;
		}
		arr[++top] = x;
		return true;
	}

	int pop() {
		if (top < 0) {
			cout << "Stack underflow";
			return 0;
		}
		int x = arr[top--];
		return x;
	}

	bool isEmpty() {
		return top < 0;
	}
};

int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	return 0;
}