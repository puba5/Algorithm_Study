#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_WALL 3
#define D_SIZE 4

#define SPACE 0
#define WALL 1
#define VIRUS 2

#define CHECK_AND_CONTINUE(cond) if (cond) { continue; }

int dx[D_SIZE] = {-1, 0, 1, 0};
int dy[D_SIZE] = {0, 1, 0, -1};

int cntSafeArea(const vector<vector<int> > &map) {
	int N = map.size();
	int M = map[0].size();
	
	int cnt = 0;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (map[n][m] == 0) {
				cnt += 1;
			}
		}
	}

	return cnt;
}

int spreadVirus(vector<vector<int> > map) {
	int N = map.size();
	int M = map[0].size();

	vector<vector<bool> > check(N, vector<bool> (M, false));

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++){ 
			CHECK_AND_CONTINUE((map[n][m] != VIRUS) || (check[n][m] == true))
			
			queue<int> q_x;
			queue<int> q_y;
			q_x.push(n);
			q_y.push(m);
			check[n][m] = true;
			while (!q_x.empty()) {
				int x = q_x.front(); q_x.pop();
				int y = q_y.front(); q_y.pop();

				for (int i = 0; i < D_SIZE; i++) {
					int next_x = x + dx[i];
					int next_y = y + dy[i];
					
					CHECK_AND_CONTINUE((next_x < 0) || (next_y < 0) || 
										(next_x >= N) || (next_y >= M) || 
										(map[next_x][next_y] == WALL) ||
										(check[next_x][next_y] == true))
										
					map[next_x][next_y] = VIRUS;
					q_x.push(next_x);
					q_y.push(next_y);
					check[next_x][next_y] = true;
				}
			}
		}
	}

	return cntSafeArea(map);
}

int go(vector<vector<int> > &map, int prev_x, int prev_y, int wall_cnt) {
	if (wall_cnt == MAX_WALL) {
		return spreadVirus(map);
	}

	int N = map.size();
	int M = map[0].size();

	int max_safe_area = 0;

	for (int n = prev_x; n < N; n++) {
		for (int m = ((n == prev_x) ? (prev_y + 1) : (0)); m < M; m++) {
			CHECK_AND_CONTINUE(map[n][m] != SPACE)

			map[n][m] = WALL;
			max_safe_area = max(max_safe_area, go(map, n, m, wall_cnt + 1));
			map[n][m] = SPACE;
		}
	}

	return max_safe_area;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	vector<vector<int> > map(N, vector<int> (M));

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			scanf("%d", &(map[n][m]));
		}
	}

	printf("%d\n", go(map, 0, -1, 0));

	return 0;
}