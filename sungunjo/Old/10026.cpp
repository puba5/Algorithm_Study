#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int main() {
	int N;
	scanf("%d ", &N);

	vector<vector<char> > paint(N, vector<char>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			paint[i][j] = getchar();
			if (paint[i][j] == '\n') {
				paint[i][j] = getchar();
			}
		}
	}

	queue<pair<int, int> > q[2];
	vector<vector<bool> > check[2];
	int area[2];

	for (int t = 0; t < 2; t++) {
		check[t].assign(N, vector<bool>(N, false));
		area[t] = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[t][i][j] == true) {
					continue;
				}

				q[t].push(make_pair(i, j));
				check[t][i][j] = true;
				area[t]++;

				while(!q[t].empty()) {
					pair<int, int> now = q[t].front(); q[t].pop();

					char now_color = paint[now.first][now.second];

					if (now_color == 'G') {
						paint[now.first][now.second] = 'R';
					}

					for (int d = 0; d < 4; d++) {
						pair<int, int> next = make_pair(now.first + di[d], now.second + dj[d]);

						if ((next.first < 0) || (next.second < 0) || (N <= next.first) || (N <= next.second) || 
							(check[t][next.first][next.second] == true) ||
							(paint[next.first][next.second] != now_color)) {
							continue;
						}

						q[t].push(next);
						check[t][next.first][next.second] = true;

					}
				}

			}
		}
	}

	printf("%d %d\n", area[0], area[1]);

	return 0;
}
