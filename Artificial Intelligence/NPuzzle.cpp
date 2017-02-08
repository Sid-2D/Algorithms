// Algorithm to N-Puzzle problem using A* search
// Problem Link - https://www.hackerrank.com/challenges/n-puzzle

#include <iostream>
#include <queue>
#include <cmath>
#include <utility>
#include <vector>
#include <set>

using namespace std;

priority_queue < pair <int, pair < vector<int>, vector<char> > > > PQ;
pair <int, pair < vector<int>, vector<char> > > tempPair;
vector<int> goal;
int k;

// A global hash to prevent same state to be inserted again
set < vector<int> > checked;

pair<int, int> get2DIndex(int num) {
	pair<int, int> index;
	index.first = num / k;
	index.second = num % k;
	return index;
}

int getManhattanPriority(vector<int> board) {
	int priority = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (board[i * k + j]) {
				pair<int, int> index = get2DIndex(board[i * k + j]);
				priority += abs((i * k) - index.first) + abs(j - index.second);
			}
		}
	}
	return priority;
}

vector<int> move(vector<int> board, int i, int j, int newI, int newJ) {
	int temp = board[i * k + j];
	board[i * k + j] = board[newI * k + newJ];
	board[newI * k + newJ] = temp;
	return board;
}

void makeMove(vector<int> board, vector<char> moves, int steps) {
	vector<int> tempBoard;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (board[i * k + j] == 0) {
				vector<char> childMoves = moves;
				if (i > 0) {
					tempBoard = move(board, i, j, i - 1, j);
					if (checked.find(tempBoard) == checked.end()) {
						childMoves.push_back('U');
						PQ.push(make_pair(-1 * (getManhattanPriority(tempBoard) + steps), make_pair(tempBoard, childMoves)));
						checked.insert(tempBoard);
						childMoves.pop_back();
					}
				}
				if (i < k - 1) {
					tempBoard = move(board, i, j, i + 1, j);
					if (checked.find(tempBoard) == checked.end()) {
						childMoves.push_back('D');
						PQ.push(make_pair(-1 * (getManhattanPriority(tempBoard) + steps), make_pair(tempBoard, childMoves)));
						checked.insert(tempBoard);
						childMoves.pop_back();
					}
				}
				if (j > 0) {
					tempBoard = move(board, i, j, i, j - 1);
					if (checked.find(tempBoard) == checked.end()) {
						childMoves.push_back('L');
						PQ.push(make_pair(-1 * (getManhattanPriority(tempBoard) + steps), make_pair(tempBoard, childMoves)));
						checked.insert(tempBoard);
						childMoves.pop_back();
					}
				}
				if (j < k - 1) {
					tempBoard = move(board, i, j, i, j + 1);
					if (checked.find(tempBoard) == checked.end()) {
						childMoves.push_back('R');
						PQ.push(make_pair(-1 * (getManhattanPriority(tempBoard) + steps), make_pair(tempBoard, childMoves)));
						checked.insert(tempBoard);
						childMoves.pop_back();
					}
				}
				return;
			}
		}
	}
}

vector<int> slideEmptyTile(vector<int> board, int r, int c) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (board[i * k + j] == 0) {
				int newI = i + r;
				int newJ = j + c;
			 	int temp = board[i * k + j];
				board[i * k + j] = board[newI * k + newJ];
				board[newI * k + newJ] = temp;
				return board;
			}
		}
	}
	return board;
}

void print(vector<int> board) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			cout << board[i * k + j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
 
void printMoves(vector<char> moves, vector<int> board) {
	print(board);
	for (int i = 0; i < moves.size(); i++) {
		if (moves[i] == 'L') {
			board = slideEmptyTile(board, 0, -1);
		} else if (moves[i] == 'R') {
			board = slideEmptyTile(board, 0, 1);
		} else if (moves[i] == 'U') {
			board = slideEmptyTile(board, -1, 0);
		} else if (moves[i] == 'D') {
			board = slideEmptyTile(board, 1, 0);
		}
		print(board);
	}
}

int main() {
	cin >> k;
	vector<int> board, tempBoard;
	int num;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			cin >> num;
			board.push_back(num);
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			goal.push_back(i * k + j);
		}
	}
	vector<char> moves;
	checked.insert(board);
	PQ.push(make_pair(-1 * getManhattanPriority(board), make_pair(board, moves)));
	int steps;
	while (!PQ.empty()) {
		tempPair = PQ.top();
		PQ.pop();
		int priority = tempPair.first;
		tempBoard = tempPair.second.first;
		if (tempBoard == goal) {
			cout << tempPair.second.second.size() << endl;
			for (int i = 0; i < tempPair.second.second.size(); i++) {
				switch(tempPair.second.second[i]) {
					case 'L': cout << "LEFT\n"; break;
					case 'R': cout << "RIGHT\n"; break;
					case 'U': cout << "UP\n"; break;
					case 'D': cout << "DOWN\n"; break;
				}
			}
			// printMoves(tempPair.second.second, board);
			break;
		}
		steps = -1 * priority - getManhattanPriority(tempBoard);
		makeMove(tempBoard, tempPair.second.second, steps + 1);
	}
	return 0;
}