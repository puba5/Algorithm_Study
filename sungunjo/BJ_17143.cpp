#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

typedef struct _shark {
	int r;
	int c;
	int s;
	int d;
	int z;

	_shark() : r(-1), c(-1), s(-1), d(-1), z(-1) {};
	_shark(int _r, int _c, int _s, int _d, int _z) : r(_r), c(_c), s(_s), d(_d), z(_z) {};
	
} Shark;

int moveToMinus(int max, int now, int s, bool &dir);
int moveToPlus(int max, int now, int s, bool &dir);

int moveToMinus(int max, int now, int s, bool &dir) {
	dir = false;
	int move_to = now - s;
	if (move_to < 0) {
		return moveToPlus(max, 0, (-1 * move_to), dir);
	} else {
		return move_to;
	}
}

int moveToPlus(int max, int now, int s, bool &dir) {
	dir = true;
	int move_to = now + s;
	if (move_to >= max) {
		return moveToMinus(max, max - 1, move_to - (max - 1), dir);
	} else {
		return move_to;
	}
}

void print(vector<vector<Shark*> > &map) {
			for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[0].size(); j++) {
				if (map[i][j] != NULL) {
					printf("%2d ", map[i][j]->z);
				} else {
					printf("%2d ", 0);
				}
			}printf("\n");
		}
}

void moveShark(vector<vector<Shark*> > &new_map, Shark *shark) {
	int R = new_map.size();
	int C = new_map[0].size();
	bool dir;
	switch (shark->d) {
		case UP:
			shark->r = moveToMinus(R, shark->r, shark->s, dir);
			if (dir == true) {
				shark->d = DOWN;
			}
			break;
		case DOWN:
			shark->r = moveToPlus(R, shark->r, shark->s, dir);
			if (dir == false) {
				shark->d = UP;
			}
			break;
		case LEFT:
			shark->c = moveToMinus(C, shark->c, shark->s, dir);
			if (dir == true) {
				shark->d = RIGHT;
			}
			break;
		case RIGHT:
			shark->c = moveToPlus(C, shark->c, shark->s, dir);
			if (dir == false) {
				shark->d = LEFT;
			}
			break;
		default:
			break;
	}
	
	if (new_map[shark->r][shark->c] != NULL) {
		if (new_map[shark->r][shark->c]->z > shark->z) {
			delete(shark);
			return;
		} else {
			delete(new_map[shark->r][shark->c]);
		}
	}

	new_map[shark->r][shark->c] = shark;
}

int fishermanTurn(vector<vector<Shark*> > &map, int c) {
	int R = map.size();
	for (int r = 0; r < R; r++) {
		if (map[r][c] != NULL) {
			int size = map[r][c]->z;
			delete(map[r][c]);
			map[r][c] = NULL;

			return size;
		}
	}

	return 0;
}

void sharkTurn(vector<vector<Shark*> > &map) {
	int R = map.size();
	int C = map[0].size();
	vector<vector<Shark*> > new_map(R, vector<Shark*> (C, NULL));
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (map[r][c] != NULL) {
				moveShark(new_map, map[r][c]);
			}
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			map[r][c] = new_map[r][c];
		}
	}
}

int go(vector<vector<Shark*> > &map) {
	int R = map.size();
	int C = map[0].size();
	int cnt = 0;
	for (int i = 0; i < C; i++) {
		cnt += fishermanTurn(map, i);	
		sharkTurn(map);
	}

	return cnt;
}

int main() {
	int R, C, M;
	scanf("%d %d %d", &R, &C, &M);

	vector<vector<Shark*> > map(R, vector<Shark*> (C, NULL));

	for (int m = 0; m < M; m++) {
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		r -= 1; c -= 1;

		map[r][c] = new Shark(r, c, s, d, z);
	}
	
	printf("%d\n", go(map));

	return 0;
}