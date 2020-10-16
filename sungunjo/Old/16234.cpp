#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

int N, L, R;
int A[55][55];
pair<int, int> d[4];

int main() {
	d[0] = make_pair(-1, 0);
	d[1] = make_pair(0, 1);
	d[2] = make_pair(1, 0);
	d[3] = make_pair(0, -1);

	cin >> N >> L >> R;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> A[r][c];
		}
	}

	int ans = 0;
	while(1) {
		bool moved = false;
		int un = 0;
		int map[55][55] = {0, };
		int after[2505] = {0, };
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (map[r][c] != 0) {
					continue;
				}

				queue< pair<int, int> > q;
				int people = 0;
				int country = 0;
 
				un++;
				country++;
				map[r][c] = un;
				people += A[r][c];
				q.push(make_pair(r, c));

				while(!q.empty()) {
					pair<int, int> c = q.front(); q.pop();

					for (int i = 0; i < 4; i++) {
						pair<int, int> next = make_pair(c.first + d[i].first, c.second + d[i].second);

						if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= N || map[next.first][next.second] != 0) {
							continue;
						}

						int differ = abs(A[c.first][c.second] - A[next.first][next.second]);
						if (L <= differ && differ <= R) {
							country++;
							map[next.first][next.second] = un;
							people += A[next.first][next.second];
							q.push(next);
						}

					}
				}

				after[un] = people / country;
			}
		}
	
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (A[r][c] != after[map[r][c]]) {
					moved = true;
					A[r][c] = after[map[r][c]];
				}
			}
		}

		if (moved) {
			ans++;
		} else {
			break;
		}
	}

	cout << ans << endl;
}	


	
