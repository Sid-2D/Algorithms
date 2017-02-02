#include <iostream>
#include <cmath>
using namespace std;

struct Move {
	int row;
	int col;
};

char player = 'X', opponent = 'O';

bool isMovesLeft(char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == '_') {
				return true;
			}
		}
	}
	return false;
}

int evaluate(char b[3][3]) {
	// Rows
	for (int i = 0; i < 3; i++) {
		if (b[i][0] == b[i][1] && b[i][1] == b[i][2]) {
			if (b[i][0] == player) {
				return 10;
			} else if (b[i][0] == opponent) {
				return -10;
			}
		}
	}
	// Columns
	for (int i = 0; i < 3; i++) {
		if (b[0][i] == b[1][i] && b[1][i] == b[2][i]) {
			if (b[0][i] == player) {
				return 10;
			} else if (b[0][i] == opponent) {
				return -10;
			}
		}
	}
	// Diagonals
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
		if (b[0][0] == player) {
			return 10;
		} else if (b[0][0] == opponent) {
			return -10;
		}
	}
	if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
		if (b[0][2] == player) {
			return 10;
		} else if (b[0][2] == opponent) {
			return -10;
		}
	}
	// No wins
	return 0;
}

int minimax(char board[3][3], int depth, bool playerMove) {
	cout << depth << endl;
	int score = evaluate(board);
	// If player wins
	if (score == 10) {
		return score;
	}
	// If AI wins
	if (score == -10) {
		return score;
	}
	// If board full
	if (isMovesLeft(board) == false) {
		return 0;
	}
	// If player's move
	if (playerMove) {
		int best = -1000;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				// Check if cell empty
				if (board[i][j] == '_') {
					board[i][j] = player;
					best = max(best, minimax(board, depth + 1, !playerMove));
					// Undo move
					board[i][j] = '_';
				}
			}
		}
		return best;
	} else {
		int best = 1000;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				// Check if cell empty
				if (board[i][j] == '_') {
					board[i][j] = opponent;
					best = min(best, minimax(board, depth + 1, !playerMove));
					// Undo move
					board[i][j] = '_'; 
				}
			}
		}
		return best;
	}
}

Move findBestMove(char board[3][3]) {
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == '_') {
				board[i][j] = player;
				int moveVal = minimax(board, 0, false);
				board[i][j] = '_';
				if (moveVal > bestVal) {
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}
	printf("The value of move is : %d\n\n", bestVal);
	return bestMove;
}

int main() {
	char board[3][3] = {
		{'X', 'O', 'O'},
		{'O', 'O', 'X'}, 
		{'X', '_', '_'}
	};
	Move bestMove = findBestMove(board);
	printf("The optimal move is: \n");
	printf("Row: %d, Col: %d\n", bestMove.row, bestMove.col);
	return 0;
}