#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int ret;
int map[9][8][8];
int cctv[9];								// 1 ~ 8th cctv type
int C;
int cx[9], cy[9];							// 1 ~ 8th cctv axis
int dEnd[6] = {0, 4, 2, 4, 4, 1};

void mark(int i, int axis, int sign) {
	if (axis == 0) {						// axis x
		if (sign == 1) {
			for (int x = cx[i] + sign; x < N; x++) {
				if (map[i][x][cy[i]] != 6) {
					map[i][x][cy[i]] = cctv[i];
				} else {
					break;
				}
			}
		} else if (sign == -1) {
			for (int x = cx[i] + sign; x >= 0; x--) {
				if (map[i][x][cy[i]] != 6) {
					map[i][x][cy[i]] = cctv[i];
				} else {
					break;
				}
			}
		}
	} else if (axis == 1) {						// axis y
		if (sign == 1) {
			for (int y = cy[i] + sign; y < M; y++) {
				if (map[i][cx[i]][y] != 6) {
					map[i][cx[i]][y] = cctv[i];
				} else {
					break;
				}
			}
		} else if (sign == -1) {
			for (int y = cy[i] + sign; y >= 0; y--) {
				if (map[i][cx[i]][y] != 6) {
					map[i][cx[i]][y] = cctv[i];
				} else {
					break;
				}
			}
		}
	}
}

void checkMap(int i, int d) {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			map[i][x][y] = map[i-1][x][y];
		}
	}

	if (cctv[i] == 1) {
		if (d == 0) {
			mark(i, 0, 1);
		} else if (d == 1) {
			mark(i, 1, -1);
		} else if (d == 2) {
			mark(i, 0, -1);
		} else if (d == 3) {
			mark(i, 1, 1);
		}

	} else if (cctv[i] == 2) {
		if (d == 0) {
			mark(i, 0, 1); mark(i, 0, -1);
		} else if (d == 1) {
			mark(i, 1, 1); mark(i, 1, -1);
		}
	} else if (cctv[i] == 3) {
		if (d == 0) {
			mark(i, 1, 1); mark(i, 0, 1);
		} else if (d == 1) {
			mark(i, 0, 1); mark(i, 1, -1);
		} else if (d == 2) {
			mark(i, 1, -1); mark(i, 0, -1);
		} else if (d == 3) {
			mark(i, 0, -1); mark(i, 1, 1);
		}

	} else if (cctv[i] == 4) {
		if (d == 0) {
			mark(i, 0, -1); mark(i, 1, 1); mark(i, 0, 1);
		} else if (d == 1) {
			mark(i, 1, 1); mark(i, 0, 1); mark(i, 1, -1);
		} else if (d == 2) {
			mark(i, 0, 1); mark(i, 1, -1); mark(i, 0, -1);
		} else if (d == 3) {
			mark(i, 1, -1); mark(i, 0, -1); mark(i, 1, 1);
		}

	} else if (cctv[i] == 5) {
		if (d == 0) {
			mark(i, 0, 1); mark(i, 1, -1); mark(i, 0, -1); mark(i, 1, 1);
		}
	}
}

int go(int i, int d) {
	int ret = 0;
	if (i > 0) checkMap(i, d);

	if (i == C) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (map[i][x][y] == 0) {
					ret++;
				}
			}
		}
	} else {
		ret = go(i+1, 0);
		for (int dNext = 1; dNext < dEnd[cctv[i+1]]; dNext++) {
			ret = min(ret, go(i+1, dNext));
		}
	}
	return ret;
}

int main() {
	cin >> N >> M;

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> map[0][x][y];
			if (0 < map[0][x][y] && map[0][x][y] < 6) {
				C++;
				cctv[C] = map[0][x][y];
				cx[C] = x; cy[C] = y;
			}
		}
	}
	cout << go(0, 0) << endl;
	return 0;
}
