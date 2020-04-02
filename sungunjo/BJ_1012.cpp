#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _node {
	int x;
	int y;
	_node(int _x, int _y) : x(_x), y(_y) {};
} Node;

vector<Node> dir;

int main() {
	dir.push_back(Node(-1, 0));
	dir.push_back(Node(0, 1));
	dir.push_back(Node(1, 0));
	dir.push_back(Node(0, -1));

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int M, N, K;
		scanf("%d %d %d", &M, &N, &K);
		vector<vector<int> > map(N, vector<int> (M, 0));
		for (int k = 0; k < K; k++) {
			int x, y;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
		
		int worm_cnt = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (map[n][m] != 1) {
					continue;
				}

				queue<Node> q;
				q.push(Node(n, m));
				map[n][m] = -1;
				worm_cnt += 1;
				while (q.empty() != true) {
					Node now = q.front(); q.pop();

					for (int d = 0; d < dir.size(); d++) {
						Node next(now.x + dir[d].x, now.y + dir[d].y);
						if ((next.x < 0) || (next.y < 0) ||
							(next.x >= N) || (next.y >= M) ||
							(map[next.x][next.y] != 1)) {
							continue;
						}
						q.push(next);
						map[next.x][next.y] = -1;
					}
				}
			}
		}

		printf("%d\n", worm_cnt);
	}
}