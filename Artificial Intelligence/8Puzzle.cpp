// My implementation for solving 8 Puzzle problem using A* search.

#include <iostream>
#include <queue>
#include <cmath>
#include <utility>
#include <vector>
#include <set>

using namespace std;

priority_queue < pair <int, vector<int> > > PQ;
pair <int, vector<int> > tempPair;
vector<int> goal;

// A global hash to prevent same state to be inserted again
set < vector<int> > checked;
 
// Hamming priority function
int getHammingPriority(vector<int> board) {
	int priority = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i * 3 + j] != goal[i * 3 + j]) {
				priority++;
			}
		}
	}
	priority--;
	return priority;
}

// Manhattan priority function
int getManhattanPriority(vector<int> board) {
	int priority = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i * 3 + j] == 1) {
				priority += abs(i - 0) + abs(j - 0);
			} else if (board[i * 3 + j] == 2) {
				priority += abs(i - 0) + abs(j - 1);
			} else if (board[i * 3 + j] == 3) {
				priority += abs(i - 0) + abs(j - 2);
			} else if (board[i * 3 + j] == 4) {
				priority += abs(i - 1) + abs(j - 2);
			} else if (board[i * 3 + j] == 5) {
				priority += abs(i - 2) + abs(j - 2);
			} else if (board[i * 3 + j] == 6) {
				priority += abs(i - 2) + abs(j - 1);
			} else if (board[i * 3 + j] == 7) {
				priority += abs(i - 2) + abs(j - 0);
			} else if (board[i * 3 + j] == 8) {
				priority += abs(i - 1) + abs(j - 0);
			}
		}
	}
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
					if (checked.find(tempBoard) == checked.end()) {
						PQ.push(make_pair(-1 * (getManhattanPriority(tempBoard) + steps), tempBoard));
						checked.insert(tempBoard);
					}
				}
				if (i < 2) {
					tempBoard = move(board, i, j, i + 1, j);
					if (checked.find(tempBoard) == checked.end()) {
						PQ.push(make_pair(-1 * (getManhattanPriority(tempBoard) + steps), tempBoard));
						checked.insert(tempBoard);
					}
				}
				if (j > 0) {
					tempBoard = move(board, i, j, i, j - 1);
					if (checked.find(tempBoard) == checked.end()) {
						PQ.push(make_pair(-1 * (getManhattanPriority(tempBoard) + steps), tempBoard));
						checked.insert(tempBoard);
					}
				}
				if (j < 2) {
					tempBoard = move(board, i, j, i, j + 1);
					if (checked.find(tempBoard) == checked.end()) {
						PQ.push(make_pair(-1 * (getManhattanPriority(tempBoard) + steps), tempBoard));
						checked.insert(tempBoard);
					}
				}
				break;
			}
		}
	}
}

int main() {
	// Goal board is:
	// [1, 2, 3]
	// [8, 0, 4]
	// [7, 6, 5]
	goal.push_back(1);
	goal.push_back(2);
	goal.push_back(3);
	goal.push_back(8);
	goal.push_back(0);
	goal.push_back(4);
	goal.push_back(7);
	goal.push_back(6);
	goal.push_back(5);

	// Current board is: 
	// [1, 3, 4]
	// [8, 0, 5]
	// [7, 2, 6]
	vector<int> board;
	board.push_back(1);
	board.push_back(3);
	board.push_back(4);
	board.push_back(8);
	board.push_back(0);
	board.push_back(5);
	board.push_back(7);
	board.push_back(2);
	board.push_back(6);

	PQ.push(make_pair(-1 * getManhattanPriority(board), board));
	vector <int> tempBoard;
	int steps;
	int examinations = 0;
	while (!PQ.empty()) {
		tempPair = PQ.top();
		PQ.pop();
		int priority = tempPair.first;
		vector <int> tempBoard = tempPair.second;
		if (tempBoard == goal) {
			cout << "Moves required = " << -1 * priority << endl;
			cout << "State Examinations = " << examinations << endl;
			break;
		}
		examinations++;
		steps = -1 * priority - getManhattanPriority(tempBoard);
		makeMove(tempBoard, steps + 1);
	}
	if (PQ.empty()) {
		cout << "Solution not possible." << endl;
	}
	return 0;
}