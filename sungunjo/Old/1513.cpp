#include <iostream>
using namespace std;

#define LIMIT 1000007

int N, M, C;
int dp[51][51][51][51];
int cx[51], cy[51];

bool exist_in(int x, int y) {
	for (int i = 1; i <= C; i++) {
		if (x == cx[i] && y == cy[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	cin >> N >> M >> C;

	dp[1][1][0][0] = 1;
	for (int i = 1; i <= C; i++) {
		cin >> cx[i] >> cy[i];
		if (cx[i] == 1 && cy[i] == 1) {
			dp[1][1][i][1] = 1;
			dp[1][1][0][0] = 0;
		}
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			for (int i = 0; i <= C; i++) {
				for (int k = 0; k <= C; k++) {
					if (dp[x][y][i][k] != 0) {
						continue;
					}

					if (exist_in(x, y)) {
						if ((x == cx[i] && y == cy[i]) && (k != 0) && (i != 0)) {
							for (int j = 0; j < i; j++) {
								dp[x][y][i][k] = (dp[x][y][i][k] + dp[x-1][y][j][k-1] + dp[x][y-1][j][k-1]) % LIMIT;
							}
						} else {
							dp[x][y][i][k] = 0;
						}
					} else {
						dp[x][y][i][k] = (dp[x-1][y][i][k] + dp[x][y-1][i][k]) % LIMIT;
					}
				}
			}
		}
	}

	for (int k = 0; k <= C; k++) {
		int temp = 0;
		for (int i = 0; i <= C; i++) {
			 temp = (temp + dp[N][M][i][k]) % LIMIT;
		}
		cout << temp;
		if (k == C) {
			cout << endl;
		} else {
			cout << " ";
		}
	}

	return 0;
}
