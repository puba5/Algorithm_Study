#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int count(vector<vector<int> > &map) {
	int i_size = map.size();
	int j_size = map[0].size();
	int ret = 0;

	for (int i = 0; i < i_size; i++) {
		for (int j = 0; j < j_size; j++) {
			if (map[i][j] == 0) {
				ret++;
			}
		}
	}

	return ret;
}

int simulation(vector<vector<int> > map, vector<int> &wx, vector<int> &wy) {
	int i_size = map.size();
	int j_size = map[0].size();
	int wx_size = wx.size();
	int wy_size = wy.size();
	int dx[4] = {-1, 0, 1,  0};
	int dy[4] = { 0, 1, 0, -1};

	for (int i = 0; i < 3; i++) {
		map[wx[i]][wy[i]] = 1;
	}

	for (int i = 0; i < i_size; i++) {
		for (int j = 0; j < j_size; j++) {
			if (map[i][j] != 2) {
				continue;
			}

			queue<int> qx;
			queue<int> qy;

			map[i][j] = 3;
			qx.push(i); qy.push(j);
			while((!qx.empty()) && (!qy.empty())) {
				int x = qx.front(); qx.pop();
				int y = qy.front(); qy.pop();

				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];

					if ((nx < 0) || (ny < 0) || (nx >= i_size) || (ny >= j_size) || (map[nx][ny] != 0)) {
						continue;
					}
					map[nx][ny] = 3;
					qx.push(nx); qy.push(ny);
				}
			}
		}
	}
	
	return count(map);
}

void go(vector<vector<int> > &map, int x, int y, vector<int> wx, vector<int> wy, int &sim_result) {
	int i_size = map.size();
	int j_size = map[0].size();

	wx.push_back(x); wy.push_back(y);

	if ((wx.size() == 3) && (wy.size() == 3)) {
		sim_result = max(sim_result, simulation(map, wx, wy));
		return;
	}

	for (int i = x; i < i_size; i++) {
		int j = 0;
		if (i == x) {
			j = y + 1;
		}
		for (j; j < j_size; j++) {
			if (map[i][j] == 0) {
				go(map, i, j, wx, wy, sim_result);
			}
		}
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	vector<vector<int> > map(N, vector<int> (M, 0));

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			register int tmp;
			scanf("%d", &tmp);
			switch(tmp) {
				case 1:
					map[n][m] = 1;
					break;
				case 2:
					map[n][m] = 2;
					break;
				default:
					break;
			}
		}
	}

	vector<int> wx, wy;
	int sim_result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0) {
				continue;
			}

			go(map, i, j, wx, wy, sim_result);
		}
	}

	printf("%d\n", sim_result);

	return 0;
}
