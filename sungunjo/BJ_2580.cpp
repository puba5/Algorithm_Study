#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define CHECK_AND_CONTINUE(cond) if (cond) { continue; }

#define SECT_SIZE 3
#define LINE_SIZE 9
#define NUM_SIZE 9

typedef struct _pos {
	int x;
	int y;

	_pos() : x(0), y(0) {};
	_pos(int _x, int _y) : x(_x), y(_y) {};
} Pos;

void print(const int board[LINE_SIZE][LINE_SIZE]) {
	for (int i = 0; i < LINE_SIZE; i++) {
		for (int j = 0; j < LINE_SIZE; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

bool sudoku(int board[LINE_SIZE][LINE_SIZE], const vector<Pos> &blank, int index,
			bool row_check[LINE_SIZE][NUM_SIZE + 1], bool col_check[LINE_SIZE][NUM_SIZE + 1], 
			bool sect_check[SECT_SIZE][SECT_SIZE][NUM_SIZE + 1]) {

	if (index == blank.size()) {
		print(board);
		return true;
	}
	

	for (int num = 1; num <= NUM_SIZE; num++) {
		int r = blank[index].x;
		int c = blank[index].y;
		int sect_r = r / 3;
		int sect_c = c / 3;
		
		CHECK_AND_CONTINUE((row_check[r][num] == true) || (col_check[c][num] == true) || 
							(sect_check[sect_r][sect_c][num] == true))

		board[r][c] = num;

		row_check[r][num] = true;
		col_check[c][num] = true;
		sect_check[sect_r][sect_c][num] = true;
		
		if (sudoku(board, blank, index + 1, row_check, col_check, sect_check) == true) {
			return true;
		}

		row_check[r][num] = false;
		col_check[c][num] = false;
		sect_check[sect_r][sect_c][num] = false;
	}

	return false;
}

int main() {
	int board[LINE_SIZE][LINE_SIZE];
	bool row_check[LINE_SIZE][NUM_SIZE + 1];
	bool col_check[LINE_SIZE][NUM_SIZE + 1];
	bool sect_check[SECT_SIZE][SECT_SIZE][NUM_SIZE + 1];

	for (int i = 0; i < LINE_SIZE; i++) {
		for (int n = 0; n <= NUM_SIZE; n++) {
			row_check[i][n] = false;
			col_check[i][n] = false;
		}
	}

	for (int i = 0; i < SECT_SIZE; i++) {
		for (int j = 0; j < SECT_SIZE; j++) {
			for (int n = 0; n <= NUM_SIZE; n++) {
				sect_check[i][j][n] = false;
			}
		}
	}

	vector<Pos> blank;

	for (int i = 0; i < LINE_SIZE; i++) {
		for (int j = 0; j < LINE_SIZE; j++) {
			scanf("%d", &(board[i][j]));
			if (board[i][j] == 0) {
				blank.push_back(Pos(i, j));
			} else {
				row_check[i][board[i][j]] = true;
				col_check[j][board[i][j]] = true;
				sect_check[i / 3][j / 3][board[i][j]] = true;
			}
		}
	}

	sudoku(board, blank, 0, row_check, col_check, sect_check);

	return 0;
}