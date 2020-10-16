#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define INF 88888888

int N, H, M;
bool ladder[35][15] = {false, };

bool check(bool lad[][15]) {
	bool ret = true;
	bool temp[35][15];
	for (int i = 0; i <= H; i++) {
		memcpy(temp[i], lad[i], sizeof(lad[i]));
	}

	for (int i = 1; i <= N; i++) {
		int c = i;
		for (int r = 1; r <= H; r++) {
			if (temp[r][c] == true) {
				c++; 	
			} else if (temp[r][c-1] == true) {
				c--;
			}

			if (abs(c - i) > abs(H - r)) {
				ret = false;
				break;
			}
		}
		if (c != i) {
			ret = false;
			break;
		}
	}

	return ret;

}

int go(int cnt, bool lad[][15], int rv, int cv) {
	int ret = INF;
	bool temp[35][15];
	for (int i = 0; i <= H; i++) {
		memcpy(temp[i], lad[i], sizeof(lad[i]));
	}
	temp[rv][cv] = true;
	cnt++;

	if (check(temp) == true) {
		ret = cnt;
	} else if (cnt == 3) {
		ret = INF;
	} else {
		for (int c = cv; c < N; c++) {
			for (int r = (c == cv) ? rv + 1 : 1; r <= H; r++ ) {
				if ((temp[r][c] == false) && (temp[r][c-1] == false)) {
					ret = min(ret, go(cnt, temp, r, c));
					if (ret == cnt + 1) {
						c = N; r = H + 1;
					}
				}
			}
		}
	}

	return ret;
}


int main() {
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = true;
	}

	int ans = INF;

	if (check(ladder) == true) {
		ans = 0;
	} else {
		for (int c = 1; c < N; c++) {
			for (int r = 1; r <= H; r++) {
				if ((ladder[r][c] == false) && (ladder[r][c-1] == false)) {
					ans = min(ans, go(0, ladder, r, c));
					if (ans == 1) {
						c = N; r = H + 1;
					}
				}
			}
		}
	}

	if (ans == INF) {
		ans = -1;
	}

	cout << ans << endl;

}
