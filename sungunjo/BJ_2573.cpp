#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _node {
	int x;
	int y;

	_node(int _x, int _y) : x(_x), y(_y) {};
} Node;

void simul(vector<vector<int> > &map, const vector<Node> &dir) {
	int N = map.size();
	int M = map[0].size();

	vector<vector<int> > sea(N, vector<int> (M, 0));

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (map[n][m] == 0) {
				continue;
			}

			for (int d = 0; d < dir.size(); d++) {
				Node near(n + dir[d].x, m + dir[d].y); 
				if ((near.x < 0) || (near.y < 0) ||
					(near.x >= N) || (near.y >= M) || 
					(map[near.x][near.y] != 0)) {
					continue;
				}

				sea[n][m] += 1;
			}
		}
	}
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (map[n][m] == 0) {
				continue;
			}

			map[n][m] = max(0, map[n][m] - sea[n][m]);
		}
	}
}

int bfs(const vector<vector<int> > &map, const vector<Node> &dir) {
	int N = map.size();
	int M = map[0].size();
	vector<vector<bool> > visited(N, vector<bool> (M, false));
	int island_cnt = 0;

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if ((map[n][m] == 0) ||
				(visited[n][m] == true)) {
				continue;
			}
			
			queue<Node> q;
			q.push(Node(n, m));
			visited[n][m] = true;
			island_cnt += 1;
			if (island_cnt >= 2) {
				return island_cnt;
			}
			while (q.empty() != true) {
				Node now = q.front(); q.pop();

				for (int d = 0; d < dir.size(); d++) {
					Node next(now.x + dir[d].x, now.y + dir[d].y);
					
					if ((next.x < 0) || (next.y < 0) ||
						(next.x >= N) || (next.y >= M) ||
						(map[next.x][next.y] == 0) ||
						(visited[next.x][next.y] == true)) {
						continue;
					}
					
					q.push(next);
					visited[next.x][next.y] = true;
				}
			}
		}
	}

	return island_cnt;
}

int main() {
	vector<Node> dir;
	dir.push_back(Node(-1, 0));
	dir.push_back(Node(0, 1));
	dir.push_back(Node(1, 0));
	dir.push_back(Node(0, -1));

	int N, M;
	scanf("%d %d", &N, &M);

	vector<vector<int> > map(N, vector<int> (M, 0));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			scanf("%d", &(map[n][m]));
		}
	}

	int year = 0, island_cnt = 0;
	do {
		simul(map, dir);
		year += 1;
	} while ((island_cnt = bfs(map, dir)) == 1);

	if (island_cnt == 0) {
		year = 0;
	}

	printf("%d\n", year);

	return 0;
}