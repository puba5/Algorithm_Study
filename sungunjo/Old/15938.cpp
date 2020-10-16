#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

#define LIMIT 1000000007

int map[405][405][205];

int main() {
	int ans = 9;

	pair<int, int> dir[4];
	dir[0] = make_pair(-1, 0);
	dir[1] = make_pair(0, 1);
	dir[2] = make_pair(1, 0);
	dir[3] = make_pair(0, -1);

	int xs, ys, T, xh, yh, N;
	int xd, yd;
	cin >> xs >> ys >> T >> xh >> yh >> N;
	xd = 200 - xs; yd = 200 - ys;
	xs = xs + xd; ys = ys + yd;
	xh = xh + xd; yh = yh + yd;
	if ((xh < 0) || (400 < xh) || (yh < 0) || (400 < yh)) {
		cout << 0 << endl;
		return 0;
	} else if ((xs == xh) && (ys == yh)) {
		cout << 1 << endl;
		return 0;
	}
	map[xh][yh][0] = -9;
	map[xs][ys][0] = 1;
	for (int i = 0; i < N; i++) {
		int xi, yi;
		cin >> xi >> yi;
		xi = xi + xd; yi = yi + yd;
		if ((0 <= xi) && (xi <= 400) && (0 <= yi) && (yi <= 400)) {
			map[xi][yi][0] = -1;
		}
	}


	for (int t = 0; t < T; t++) {
		for (int x = 0; x <= 400; x++) {
			for (int y = 0; y <= 400; y++) {
				if ((map[x][y][0] < 0) || (map[x][y][t] == 0)) {
					continue;
				}
				for (int d = 0; d < 4; d++) {
					pair<int, int> tmp(x+dir[d].first, y+dir[d].second);

					if ((0 <= tmp.first) && (tmp.first <= 400) && (0 <= tmp.second) && (tmp.second <= 400)) {
						if (map[tmp.first][tmp.second][0] != -1) {
							map[tmp.first][tmp.second][t+1] = (map[tmp.first][tmp.second][t+1] + map[x][y][t]) % LIMIT;
						}
					}

				}

			}
		}

		ans = (ans + map[xh][yh][t]) % LIMIT;
	}
	ans = (ans + map[xh][yh][T]) % LIMIT;

	cout << ans << endl;
}
