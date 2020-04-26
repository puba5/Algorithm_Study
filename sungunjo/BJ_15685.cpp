#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

#define MAP_SIZE 100

#define CHECK_AND_CONTINUE(cond) if (cond) { continue; }

typedef enum _dir {
	RIGHT = 0,
	UP,
	LEFT,
	DOWN,
	DIR_SIZE
} Dir;

int dx[DIR_SIZE] = {1, 0, -1, 0};
int dy[DIR_SIZE] = {0, -1, 0, 1};

Dir rotDir(Dir d) {
	return (Dir) (((int) d + 1) % DIR_SIZE);
}

void drawDragonCurve(vector<vector<bool> > &map, int init_x, int init_y, Dir init_d, int init_g) {
	stack<Dir> full_dir_log;
	
	map[init_y][init_x] = true;
	int now_x = init_x + dx[init_d];
	int now_y = init_y + dy[init_d];
	
	map[now_y][now_x] = true;
	full_dir_log.push(init_d);

	for (int g = 0; g < init_g; g++) {
		stack<Dir> prev_dir_log = full_dir_log;

		while (prev_dir_log.empty() != true) {
			Dir prev_d = prev_dir_log.top(); prev_dir_log.pop();
			Dir next_d = rotDir(prev_d);
			now_x += dx[next_d];
			now_y += dy[next_d];
			
			CHECK_AND_CONTINUE((now_x < 0) || (now_y < 0) || (now_x > MAP_SIZE) || (now_y > MAP_SIZE))

			map[now_y][now_x] = true;
			full_dir_log.push(next_d);
		}
	}
}

int count(const vector<vector<bool> > &map) {
	int cnt = 0;

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if ((map[i][j] == true) && (map[i][j + 1] == true) &&
				(map[i + 1][j] == true) && (map[i + 1][j + 1] == true)) {
				cnt += 1;
			}
		}
	}

	return cnt;
}

int main() {
	vector<vector<bool> > map(MAP_SIZE + 1, vector<bool> (MAP_SIZE + 1, false));

	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);

		drawDragonCurve(map, x, y, (Dir) d, g);
	}

	printf("%d\n", count(map));


	return 0;
}