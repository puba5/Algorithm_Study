#include <iostream>
#include <utility>
using namespace std;

int main() {
	int N, M, r, c, d;
	int map[51][51];
	pair<int, int> dir[4];
	int ret = 0;
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	dir[0] = make_pair(-1, 0);
	dir[1] = make_pair(0, 1);
	dir[2] = make_pair(1, 0);
	dir[3] = make_pair(0, -1);

	while(1) {
		if (map[r][c] == 0) {
			map[r][c] = 2;
			ret++;
		}
		bool found = false;
		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;
			pair<int, int> next = make_pair(r+dir[d].first, c+dir[d].second);
			if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M || map[next.first][next.second] != 0) {
				continue;
			}

			r = next.first; c = next.second;
			found = true;
			break;
		}
		if (found == false) {
			pair<int, int> back = make_pair(r-dir[d].first, c-dir[d].second);
			if (back.first < 0 || back.first >= N || back.second < 0 || back.second >= M || map[back.first][back.second] == 1) {
				break;
			} else {
				r = back.first; c = back.second;
			}
		}
	}

	cout << ret << endl;

}
