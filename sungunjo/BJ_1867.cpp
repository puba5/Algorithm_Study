#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define DIR_NUM 8
#define INF 888888888

typedef struct _node {
	int x;
	int y;
	int cushion_cnt;

	_node(int _x = 0, int _y = 0, int _cushion_cnt = 0) : x(_x), y(_y), cushion_cnt(_cushion_cnt) {};
} Node;


Node dir[DIR_NUM] = {
	Node(-1, -2),
	Node(-2, -1),
	Node(-2, 1),
	Node(-1, 2),
	Node(1, 2),
	Node(2, 1),
	Node(2, -1),
	Node(1, -2)
};

int main() {
	int m, n;

	scanf("%d %d", &m, &n);
	vector<vector<int> > map(m, vector<int> (n, 0));
	vector<vector<long long> > way_map(m, vector<long long> (n, 0));
	vector<vector<int> > cushion_map(m, vector<int> (n, INF));
	Node start, end;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &(map[i][j]));
			if (map[i][j] == 3) {
				start.x = i;
				start.y = j;
			} else if (map[i][j] == 4) {
				end.x = i;
				end.y = j;
			}
		}
	}

	int min_cushion = -1;
	long long total_way = 0;
	vector<Node> q;
	vector<Node> goal;
	way_map[start.x][start.y] = 1;
	cushion_map[start.x][start.y] = 0;
	q.push_back(start);
	vector<Node> cycle;

	while (q.empty() == false) {
		Node now = q.front(); q.erase(q.begin());
		long long now_way = way_map[now.x][now.y];
printf("now x = %d, y = %d, cushion = %d\n", now.x, now.y, now.cushion_cnt);
//printf("cyc x = %d, y = %d\n", cycle_start.x, cycle_start.y);
		

		if ((min_cushion != -1) && (min_cushion < now.cushion_cnt)) {
			vector<Node>::iterator iter;
			for (iter = goal.begin(); iter != goal.end(); iter++) {
				total_way += way_map[iter->x][iter->y];
				way_map[iter->x][iter->y] = 0;
			}
			break;
		}

		for (int d = 0; d < DIR_NUM; d++) {
			Node next(now.x + dir[d].x, now.y + dir[d].y, now.cushion_cnt);
			
			if ((next.x < 0) || (next.y < 0) ||
				(next.x >= m) || (next.y >= n) ||
				(map[next.x][next.y] == 2)) {
				continue;
			}

			if (map[next.x][next.y] == 4) {//printf("way to (%d, %d) plus\n", next.x, next.y);//
				goal.push_back(now);
				min_cushion = now.cushion_cnt;
			} else if (map[next.x][next.y] == 1) {
				if (map[now.x][now.y] == 1) {
					cycle.push_back(next);
					if ((cycle.begin()->x == (cycle.end() - 1)->x) &&
						(cycle.begin()->y == (cycle.end() - 1)->y)) {printf("cycled\n");
						for (int r = 0; r < cycle.size() - 1; r++) {
							q.erase(q.begin());
						}
						cycle.clear();
					}
				}

				if (cushion_map[next.x][next.y] >= now.cushion_cnt) {
					way_map[next.x][next.y] += now_way;
					cushion_map[next.x][next.y] = now.cushion_cnt;
					q.insert(q.begin(), next);
				}
			} else {
				cycle.clear();
				next.cushion_cnt += 1;				
				if (cushion_map[next.x][next.y] >= next.cushion_cnt) {
					way_map[next.x][next.y] += now_way;
					cushion_map[next.x][next.y] = next.cushion_cnt;
					q.push_back(next);
				}
			}
		}
	}

	printf("%d\n", min_cushion);
	if (min_cushion != -1) {
		printf("%lld\n", total_way);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4lld ", way_map[i][j]);
		}printf("\n");
	}
	

	return 0;
}