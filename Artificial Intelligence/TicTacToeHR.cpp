// Unbeatable Tic Tic Toe game using Minimax Algorithm, written for Hackerrank challenge
// Link - https://www.hackerrank.com/challenges/tic-tac-toe

#include <cstdio>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool isMovesLeft(vector<string> board) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == '_') {
				return true;
			}
		}
	}
	return false;
}

int evaluate(vector<string> b, char player, char opponent) {
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

int minimax(vector<string> board, int depth, bool playerMove, char player, char opponent) {
	int score = evaluate(board, player, opponent);
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
					best = max(best, minimax(board, depth + 1, !playerMove, player, opponent));
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
					best = min(best, minimax(board, depth + 1, !playerMove, player, opponent));
					// Undo move
					board[i][j] = '_'; 
				}
			}
		}
		return best;
	}
}

void nextMove(char player, vector <string> board){
    int bestVal = -1000;
	int row = -1;
	int col = -1;
	bool turn = false;
	char opponent = (player == 'X') ? 'O' : 'X';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == '_') {
				board[i][j] = player;
				int moveVal = minimax(board, 0, turn, player, opponent);
				board[i][j] = '_';
				if (moveVal > bestVal) {
					row = i;
					col = j;
					bestVal = moveVal;
				}
			}
		}
	}
	printf("%d %d\n", row, col);
}

int main(void) {

    char player;
    vector <string> board;
    cin >> player;
    for(int i=0; i<3; i++) {
      string s; cin >> s;
      board.push_back(s);
    }
   	nextMove(player,board);
    return 0;
}