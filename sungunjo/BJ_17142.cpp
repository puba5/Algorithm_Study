#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_MAP_SIZE 50
#define MAX_M 10
#define MAX_SEC 888888888

#define SPACE -3
#define WALL -2
#define VIRUS -1

#define IOS_SETTING \
ios::sync_with_stdio(false); \
cin.tie(NULL); \
cout.tie(NULL); 

#define CHECK_AND_CONTINUE(cond) \
if (cond) { \
	continue; \
}

typedef enum _dir {
	DIR_UP = 0,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_SIZE
} Dir;

typedef struct _pos {
	int x;
	int y;

	_pos() : x(0), y(0) {};
	_pos(int _x, int _y) : x(_x), y(_y) {};
} Pos;

Pos dxy[DIR_SIZE] = {
	Pos(-1, 0),
	Pos(0, 1),
	Pos(1, 0),
	Pos(0, -1)
};

void init_map(int ***map, int N) {
	*map = new int*[N];
	for (int i = 0; i < N; i++) {
		(*map)[i] = new int[N];
		memset((*map)[i], 0, N * sizeof(int));
	}
}

void copy_map(int **src_map, int ***dest_map, int N) {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			(*dest_map)[x][y] = src_map[x][y];
		}
	}
}

int check(int **initial_map, int **map, int N) {
	int sec = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (map[x][y] == SPACE) {
				return MAX_SEC;
			}

			CHECK_AND_CONTINUE((initial_map[x][y] == WALL) || 
								(initial_map[x][y] == VIRUS))
			sec = max(sec, map[x][y]);

		}
	}
	return sec;
}

int simulation(int **map, int N, int M, Pos *actived) {
	int sec = 0;
	int **copied_map;
	init_map(&copied_map, N);
	copy_map(map, &copied_map, N);

	queue<Pos> q;
	for (int i = 0; i < M; i++) {
		copied_map[actived[i].x][actived[i].y] = sec;
		q.push(Pos(actived[i].x, actived[i].y));
	}
	while (!q.empty()) {
		Pos now = q.front(); q.pop();

		for (int d = 0; d < DIR_SIZE; d++) {
			Pos next(now.x + dxy[d].x, now.y + dxy[d].y);

			CHECK_AND_CONTINUE((next.x < 0) || (next.y < 0) ||
								(next.x >= N) || (next.y >= N) ||
								((copied_map[next.x][next.y] != SPACE) && (copied_map[next.x][next.y] != VIRUS)))
								
			sec = copied_map[now.x][now.y] + 1;
			copied_map[next.x][next.y] = sec;
			q.push(next);
		}
	}


	return check(map, copied_map, N);
}

int go(int **map, int N, int M, const vector<Pos> &virus, int virus_idx, Pos *actived, int actived_idx) {
	if (actived_idx == M) {
		return simulation(map, N, M, actived);
	}

	int min_sec = MAX_SEC;
	for (int i = virus_idx; i < virus.size(); i++) {
		actived[actived_idx] = virus[i];
		int sec_result = go(map, N, M, virus, i + 1, actived, actived_idx + 1);
		min_sec = min(min_sec, sec_result);
	}

	return min_sec;
}

int main() {
	IOS_SETTING

	int N, M;
	cin >> N >> M;

	int **map;
	init_map(&map, N);
	vector<Pos> virus;
	Pos *actived = new Pos[M];

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> map[x][y];
			map[x][y] += SPACE;
			if (map[x][y] == VIRUS) {
				virus.push_back(Pos(x, y));
			}
		}
	}

	int ans = go(map, N, M, virus, 0, actived, 0);
	cout << ((ans == MAX_SEC) ? (-1) : (ans)) << "\n";

	return 0;
}