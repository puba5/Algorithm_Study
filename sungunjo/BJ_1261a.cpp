#include <iostream>
#include <vector>
#include <queue>
#include <utility>
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

	_node(int _x, int _y, int _broked_wall) : x(_x), y(_y), broked_wall(_broked_wall) {};
} Node;

pair<int, int> dir[4] = {
	make_pair(-1, 0),
	make_pair(0, 1),
	make_pair(1, 0),
	make_pair(0, -1)
};


// 우선순위 bfs 사용
int priority_bfs(vector<vector<int> > &map) {
	int X = map.size();
	int Y = map[0].size();

	priority_queue<Node, vector<Node>, greater<Node> > q;
	q.push(Node(0, 0, 0));
	map[0][0] = -1;

	while (q.empty() != true) {
		Node now = q.top(); q.pop();

		for (int d = 0; d < DIR_SIZE; d++) {
			Node next(now.x + dir[d].first, now.y + dir[d].second, now.broked_wall);

			if ((next.x < 0) || (next.y < 0) ||
				(next.x >= X) || (next.y >= Y) ||
				(map[next.x][next.y] == -1)) {
				continue;
			}

			if ((next.x == X - 1) && (next.y == Y - 1)) {
				return next.broked_wall;
			} 
			
			if (map[next.x][next.y] == 1) {
				next.broked_wall += 1;
			}
			
			q.push(next);
			map[next.x][next.y] = -1;
		}
	}

	return 0;
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

	printf("%d", priority_bfs(map));

	return 0;
}