// My implementation for solving 8 Puzzle problem using A* search.

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

priority_queue < pair <int, vector<int> > > PQ;
pair <int, vector<int> > tempPair;
vector<int> goal;

int getPriority(vector<int> board) {
	int priority = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i * 3 + j] != (i * 3 + j + 1)) {
				priority++;
			}
		}
	}
	priority--;
	return priority;
}

void display(vector<int> board) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board[i * 3 + j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

vector<int> move(vector<int> board, int i, int j, int newI, int newJ) {
	int temp = board[i * 3 + j];
	board[i * 3 + j] = board[newI * 3 + newJ];
	board[newI * 3 + newJ] = temp;
	return board;
}

void makeMove(vector<int> board, int steps) {
	vector<int> tempBoard;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i * 3 + j] == 0) {
				if (i > 0) {
					tempBoard = move(board, i, j, i - 1, j);
					PQ.push(make_pair(-1 * (getPriority(tempBoard) + steps), tempBoard));
				}
				if (i < 2) {
					tempBoard = move(board, i, j, i + 1, j);
					PQ.push(make_pair(-1 * (getPriority(tempBoard) + steps), tempBoard));	
				}
				if (j > 0) {
					tempBoard = move(board, i, j, i, j - 1);
					PQ.push(make_pair(-1 * (getPriority(tempBoard) + steps), tempBoard));
				}
				if (j < 2) {
					tempBoard = move(board, i, j, i, j + 1);
					PQ.push(make_pair(-1 * (getPriority(tempBoard) + steps), tempBoard));
				}
				break;
			}
		}
	}
}

int main() {
	// Define the goal:
	goal.push_back(1);
	goal.push_back(2);
	goal.push_back(3);
	goal.push_back(4);
	goal.push_back(5);
	goal.push_back(6);
	goal.push_back(7);
	goal.push_back(8);
	goal.push_back(0);

	// Current board is: 
	// [0, 1, 3]
	// [4, 2, 5]
	// [7, 8, 6]
	vector<int> board;
	board.push_back(0);
	board.push_back(1);
	board.push_back(3);
	board.push_back(4);
	board.push_back(2);
	board.push_back(5);
	board.push_back(7);
	board.push_back(8);
	board.push_back(6);

	PQ.push(make_pair(-1 * getPriority(board), board));
	vector <int> tempBoard;
	int steps = 0;

	while (!PQ.empty()) {
		tempPair = PQ.top();
		PQ.pop();
		int priority = tempPair.first;
		vector <int> tempBoard = tempPair.second;
		display(tempBoard);
		if (tempBoard == goal) {
			cout << "Steps taken = " << steps << endl;
			break;
		}
		steps++;
		makeMove(tempBoard, steps);
	}
	return 0;
}