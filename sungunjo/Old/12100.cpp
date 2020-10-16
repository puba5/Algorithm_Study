#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;

typedef enum _dir {
	UP,
	DOWN,
	LEFT,
	RIGHT
} Dir;


int go(int cnt, int board[][21], Dir d) {
	int temp[21][21];

	for (int i = 0; i < N; i++) {
		memcpy(temp[i], board[i], sizeof(board[i]));
	}

	if (d == UP) {
		for (int j = 0; j < N; j++) {
			bool merged = false;
			int top = 0;
			if (temp[0][j] != 0) {
				top++;
			}
			for (int i = 1; i < N; i++) {
				if (temp[i][j] != 0) {
					int block = temp[i][j];
					temp[i][j] = 0;
					if ((!merged) && (temp[top-1][j] == block)){
						temp[top-1][j] += block;
						merged = true;
					} else {
						temp[top][j] = block;
						top++;
						merged = false;
					}
				}
			}
		}
	} else if (d == DOWN) {
		for (int j = 0; j < N; j++) {
			bool merged = false;
			int bottom = N-1;
			if (temp[N-1][j] != 0) {
				bottom--;
			}
			for (int i = N-2; i >= 0; i--) {
				if (temp[i][j] != 0) {
					int block = temp[i][j];
					temp[i][j] = 0;
					if ((!merged) && (temp[bottom+1][j] == block)) {
						temp[bottom+1][j] += block;
						merged = true;
					} else {
						temp[bottom][j] = block;
						bottom--;
						merged = false;
					}
				}
			}
		}
	} else if (d == LEFT) {
		for (int i = 0; i < N; i++) {
			bool merged = false;
			int side = 0;
			if (temp[i][0] != 0) {
				side++;
			}
			for (int j = 1; j < N; j++) {
				if (temp[i][j] != 0) {
					int block = temp[i][j];
					temp[i][j] = 0;
					if ((!merged) && (temp[i][side-1] == block)) {
						temp[i][side-1] += block; 
						merged = true;
					} else {
						temp[i][side] = block;
						side++;
						merged = false;
					}
				}
			}
		}
	} else if (d == RIGHT) {
		for (int i = 0; i < N; i++) {
			bool merged = false;
			int side = N-1;
			if (temp[i][N-1] != 0) {
				side--;
			}
			for (int j = N-2; j >= 0; j--) {
				if (temp[i][j] != 0) {
					int block = temp[i][j];
					temp[i][j] = 0;
					if ((!merged) && (temp[i][side+1] == block)) {
						temp[i][side+1] += block; 
						merged = true;
					} else {
						temp[i][side] = block;
						side--;
						merged = false;
					}
				}
			}
		}	
	}

	int ret = 0;

	if (cnt < 4) {
		for (int i = 0; i < 4; i++) {
			ret = max(ret, go(cnt+1, temp, (Dir)i));
		}
	} else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret = max(ret, temp[i][j]);
			}
		}
	}

	return ret;
}

int main() {
	cin >> N;

	int board[21][21];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		ans = max(ans, go(0, board, (Dir)i));
	}

	cout << ans << endl;

	return 0;
}
