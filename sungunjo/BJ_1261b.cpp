#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
using namespace std;

#define DIR_SIZE 4

typedef struct _node {
	int x;
	int y;
	int broked_wall;

	bool operator > (const _node &rhs) const {
		if (this->broked_wall > rhs.broked_wall) {
			return true;
		} else {
			return false;
		}
	}

	_node(int _x, int _y, int _broked_wall = 0) : x(_x), y(_y), broked_wall(_broked_wall) {};
} Node;

pair<int, int> dir[4] = {
	make_pair(-1, 0),
	make_pair(0, 1),
	make_pair(1, 0),
	make_pair(0, -1)
};


// 우선순위큐 다익스트라 사용
int priority_dijkstra(vector<vector<int> > &map) {
	int X = map.size();
	int Y = map[0].size();

	vector<vector<int> > dist(X, vector<int> (Y, INT32_MAX));

	priority_queue<Node, vector<Node>, greater<Node> > pq;
	dist[0][0] = 0;
	pq.push(Node(0, 0));

	while (pq.empty() != true) {
		Node s = pq.top(); pq.pop();

		for (int d = 0; d < DIR_SIZE; d++) {
			Node near(s.x + dir[d].first, s.y + dir[d].second);

			if ((near.x < 0) || (near.y < 0) ||
				(near.x >= X) || (near.y >= Y)) {
				continue;
			}

			if (dist[near.x][near.y] > dist[s.x][s.y] + map[near.x][near.y]) {
				dist[near.x][near.y] = dist[s.x][s.y] + map[near.x][near.y];
				near.broked_wall = dist[near.x][near.y];
				pq.push(near);
			}
		}
	}

	return dist[X - 1][Y - 1];
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	vector<vector<int> > map(M, vector<int> (N, 0));

	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			scanf("%1d", &(map[m][n]));
		}
	}

	printf("%d", priority_dijkstra(map));

	return 0;
}