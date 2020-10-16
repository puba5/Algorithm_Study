#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct _map {
	int i[5][5];
	char c[5][5];
	int x[5][5];
	int y[5][5];
} Map;

int N;
vector<Map> eff;
vector<Map> ele;

int dfs(Map map, int index, vector<int> check, int pos, int rot) {
	int dx, dy;
	Map moved;
	check.push_back(index);

	if (pos == 0) {
		dx = 0; dy = 0;
	} else if (pos == 1) {
		dx = 0; dy = 1;
	} else if (pos == 2) {
		dx = 1; dy = 0;
	} else if (pos == 3) {
		dx = 1; dy = 1;
	}

	if (rot == 0) {
		moved.x[0][0] = 0; moved.y[0][0] = 0; moved.x[0][1] = 0; moved.y[0][1] = 0; moved.x[0][2] = 0; moved.y[0][2] = 0; moved.x[0][3] = 0; moved.y[0][3] = 0;
		moved.x[1][0] = 0; moved.y[1][0] = 0; moved.x[1][1] = 0; moved.y[1][1] = 0; moved.x[1][2] = 0; moved.y[1][2] = 0; moved.x[1][3] = 0; moved.y[1][3] = 0;
		moved.x[2][0] = 0; moved.y[2][0] = 0; moved.x[2][1] = 0; moved.y[2][1] = 0; moved.x[2][2] = 0; moved.y[2][2] = 0; moved.x[2][3] = 0; moved.y[2][3] = 0;
		moved.x[3][0] = 0; moved.y[3][0] = 0; moved.x[3][1] = 0; moved.y[3][1] = 0; moved.x[3][2] = 0; moved.y[3][2] = 0; moved.x[3][3] = 0; moved.y[3][3] = 0;
	} else if (rot == 1) {
		moved.x[0][0] = 0; moved.y[0][0] = 3; moved.x[0][1] = 1; moved.y[0][1] = 2; moved.x[0][2] = 2; moved.y[0][2] = 1; moved.x[0][3] = 3; moved.y[0][3] = 0;
		moved.x[1][0] = -1; moved.y[1][0] = 2; moved.x[1][1] = 0; moved.y[1][1] = 1; moved.x[1][2] = 1; moved.y[1][2] = 0; moved.x[1][3] = 2; moved.y[1][3] = -1;
		moved.x[2][0] = -2; moved.y[2][0] = 1; moved.x[2][1] = -1; moved.y[2][1] = 0; moved.x[2][2] = 0; moved.y[2][2] = -1; moved.x[2][3] = 1; moved.y[2][3] = -2;
		moved.x[3][0] = -3; moved.y[3][0] = 0; moved.x[3][1] = -2; moved.y[3][1] = -1; moved.x[3][2] = -1; moved.y[3][2] = -2; moved.x[3][3] = 0; moved.y[3][3] = -3;
	} else if (rot == 2) {
		moved.x[0][0] = 3; moved.y[0][0] = 3; moved.x[0][1] = 3; moved.y[0][1] = 1; moved.x[0][2] = 3; moved.y[0][2] = -1; moved.x[0][3] = 3; moved.y[0][3] = -3;
		moved.x[1][0] = 1; moved.y[1][0] = 3; moved.x[1][1] = 1; moved.y[1][1] = 1; moved.x[1][2] = 1; moved.y[1][2] = -1; moved.x[1][3] = 1; moved.y[1][3] = -3;
		moved.x[2][0] = -1; moved.y[2][0] = 3; moved.x[2][1] = -1; moved.y[2][1] = 1; moved.x[2][2] = -1; moved.y[2][2] = -1; moved.x[2][3] = -1; moved.y[2][3] = -3;
		moved.x[3][0] = -3; moved.y[3][0] = 3; moved.x[3][1] = -3; moved.y[3][1] = 1; moved.x[3][2] = -3; moved.y[3][2] = -1; moved.x[3][3] = -3; moved.y[3][3] = -3;
	} else if (rot == 3) {
		moved.x[0][0] = 3; moved.y[0][0] = 0; moved.x[0][1] = 2; moved.y[0][1] = -1; moved.x[0][2] = 1; moved.y[0][2] = -2; moved.x[0][3] = 0; moved.y[0][3] = -3;
		moved.x[1][0] = 2; moved.y[1][0] = 1; moved.x[1][1] = 1; moved.y[1][1] = 0; moved.x[1][2] = 0; moved.y[1][2] = -1; moved.x[1][3] = -1; moved.y[1][3] = -2;
		moved.x[2][0] = 1; moved.y[2][0] = 2; moved.x[2][1] = 0; moved.y[2][1] = 1; moved.x[2][2] = -1; moved.y[2][2] = 0; moved.x[2][3] = -2; moved.y[2][3] = -1;
		moved.x[3][0] = 0; moved.y[3][0] = 3; moved.x[3][1] = -1; moved.y[3][1] = 2; moved.x[3][2] = -2; moved.y[3][2] = 1; moved.x[3][3] = -3; moved.y[3][3] = 0;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map.i[i+moved.x[i][j]+dx][j+moved.y[i][j]+dy] += eff[index].i[i][j];
			if (ele[index].c[i][j] != 'W') {
				map.c[i+moved.x[i][j]+dx][j+moved.y[i][j]+dy] = ele[index].c[i][j];
			}

			map.i[i+moved.x[i][j]+dx][j+moved.y[i][j]+dy] = max(0, map.i[i+moved.x[i][j]+dx][j+moved.y[i][j]+dy]);
			map.i[i+moved.x[i][j]+dx][j+moved.y[i][j]+dy] = min(9, map.i[i+moved.x[i][j]+dx][j+moved.y[i][j]+dy]);
		}
	}
	if (check.size() == 3) {
		int sum = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				int k = 0;
				if (map.c[i][j] == 'R') {
					k = 7;
				} else if (map.c[i][j] == 'B') {
					k = 5;
				} else if (map.c[i][j] == 'G') {
					k = 3;
				} else if (map.c[i][j] == 'Y') {
					k = 2;
				}
				sum += (k * map.i[i][j]);
			}
		}
		return sum;
	} else {
		int max_val = 0;
		for (int k = 0; k < N; k++) {
			bool b = false;
			for (int i = 0; i < check.size(); i++) {
				if (check[i] == k) {
					b = true;
				}
			}
			if (b) {
				continue;
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					max_val = max(max_val, dfs(map, k, check, i, j));
				}
			}
		}
		return max_val;
	}
	return -1;
}

int main() {
	cin >> N;

	Map map;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			map.i[i][j] = 0;
			map.c[i][j] = 'W';
		}
	}

	for (int n = 0; n < N; n++) {
		Map tmp_eff;
		Map tmp_ele;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> tmp_eff.i[i][j];
			}
		}
		eff.push_back(tmp_eff);

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> tmp_ele.c[i][j];
			}
		}
		ele.push_back(tmp_ele);
	}

	int ans = 0;
	vector<int> check;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				ans = max(ans, dfs(map, k, check, i, j));
			}
		}
	}

	cout << ans << endl;
}
