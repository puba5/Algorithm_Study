#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

#define INF 888888888

int N;
int map[25][25];

int main() {
	pair<int, int> shark;
	pair<int, int> d[4];
	int shark_size = 2;
	int ate_number = 0;

	d[0] = make_pair(-1, 0);
	d[1] = make_pair(0, -1);
	d[2] = make_pair(0, 1);
	d[3] = make_pair(1, 0);

	cin >> N;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
			if (map[r][c] == 9) {
				shark = make_pair(r, c);
				map[r][c] = 0;
			}
		}
	}

	int ans = 0;

	while (1) {
		int temp[25][25];
		bool ate = false;
		int time = 1;
		pair<int, int> ate_pos;
		for (int r = 0; r < N; r++) {
			memcpy(temp[r], map[r], sizeof(map[r]));
		}

		queue< pair<int, int> > q;
		queue<int> p;
		temp[shark.first][shark.second] = INF;
		q.push(shark);
		p.push(time);

		while (!q.empty()) {
			pair<int, int> c = q.front(); q.pop();
			int t = p.front(); p.pop();
			
			if (ate && (t != time)) {
				break;
			}

			for (int i = 0; i < 4; i++) {
				pair<int, int> next = make_pair(c.first + d[i].first, c.second + d[i].second);

				if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= N ||
					temp[next.first][next.second] > shark_size) {
					continue;
				}

				if (0 < temp[next.first][next.second] && temp[next.first][next.second] < shark_size) {
					if (ate) {
						if (ate_pos.first > next.first) {
							ate_pos = next;
						} else if ((ate_pos.first == next.first) && (ate_pos.second > next.second)) {
							ate_pos = next;
						}
					} else {
						ate = true;
						ate_number++;
						ate_pos = next;
						time = t;
					}
				} else {
					temp[next.first][next.second] = INF;
					q.push(next);
					p.push(t + 1);
				}
			}
		}

		if (ate) {
			map[ate_pos.first][ate_pos.second] = 0;
			shark = ate_pos;
			ans += time;
			if (ate_number == shark_size) {
				shark_size++;
				ate_number = 0;
			}
		} else {
			break;
		}

	}

	cout << ans << endl;
}
