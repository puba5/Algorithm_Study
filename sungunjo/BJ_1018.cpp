#include <iostream>
#include <vector>
using namespace std;

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define CHESS_BORAD_SIZE 8

// (0, 0) 이 W 로 시작하는 체스판 상에서 좌표에 따른 색 리턴하는 함수
char GetColorForCoordinate(int x, int y) {
	if ((x + y) % 2 == 0) {
		return 'W';
	} else {
		return 'B';
	}
}

// x,y 를 원점으로 자르면 몇 칸 색칠해야 하는지 리턴
// 기본적으로 (0, 0) 이 W 로 시작하는 체스판 상에서 몇 칸 색칠해야하는지 계산한 다음
// 만약 이 값이 32 보다 클 경우 64에서 빼서 리턴함
// => (0, 0) 을 B 로 시작하는 경우는 W 로 시작하는 경우의 반대만큼 칠해야 하기 때문
int CutAndCount(const vector<vector<char> > &board, int x, int y) {
	int cnt = 0;
	for (int i = x; i < (x + CHESS_BORAD_SIZE); i++) {
		for (int j = y; j < (y + CHESS_BORAD_SIZE); j++) {
			if (GetColorForCoordinate(i - x, j - y) != board[i][j]) {
				cnt += 1;
			}
		}
	}

	int chess_board_area = CHESS_BORAD_SIZE * CHESS_BORAD_SIZE;
	if (cnt > (chess_board_area / 2)) {
		cnt = chess_board_area - cnt;
	}

	return cnt;
}

int main() {
	int M, N;

	scanf("%d %d", &M, &N);
	
	vector<vector<char> > board(M, vector<char> (N));

	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			scanf(" %c", &(board[m][n]));
		}
	}

	int ans = CHESS_BORAD_SIZE * CHESS_BORAD_SIZE;
	for (int m = 0; m <= (M - CHESS_BORAD_SIZE); m++) {
		for (int n = 0; n <= (N - CHESS_BORAD_SIZE); n++) {
			ans = MIN(ans, CutAndCount(board, m, n));
		}
	}

	printf("%d\n", ans);

	return 0;
}