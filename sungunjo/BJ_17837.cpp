#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

/* defined */
#define IOS_SETTING \
ios::sync_with_stdio(false); \
cin.tie(NULL); \
cout.tie(NULL);

#define ANS_MAX 1000

/* enum */
typedef enum _color {
	COLOR_WTHIE = 0,
	COLOR_RED,
	COLOR_BLUE,
	COLOR_SIZE
} Color;

typedef enum _dir {
	DIR_RIGHT = 0,
	DIR_LEFT,
	DIR_UP,
	DIR_DOWN,
	DIR_SIZE
} Dir;


/* struct */
typedef struct _pos {
	int x;
	int y;
	
	_pos() : x(0), y(0) {};
	_pos(int _x, int _y) : x(_x), y(_y) {};
} Pos;

typedef struct _chessman {
	Pos pos;
	Dir dir;
	_chessman *up;
	_chessman *down;
} Chessman;


/* global variable */
Pos dxy[DIR_SIZE] = {
	Pos(0, 1),
	Pos(0, -1),
	Pos(-1, 0),
	Pos(1, 0)
};


/* function */
void changeDir(Dir &dir) {
	if (dir == DIR_RIGHT) {
		dir = DIR_LEFT;
	} else if (dir == DIR_LEFT) {
		dir = DIR_RIGHT;
	} else if (dir == DIR_UP) {
		dir = DIR_DOWN;
	} else if (dir == DIR_DOWN) {
		dir = DIR_UP;
	}
}

void swapChessman(Chessman **a, Chessman **b) {
	Chessman *tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

void moveToWhite(vector<vector<Chessman*> > &chessman_map, Chessman &chessman) {
	chessman_map[chessman.pos.x][chessman.pos.y] = chessman.down;	
	if (chessman.down != NULL) {
		(*chessman.down).up = NULL;
	}

	Pos next_pos(chessman.pos.x + dxy[chessman.dir].x, chessman.pos.y + dxy[chessman.dir].y);
	Chessman *now = &chessman;

	while ((*now).up != NULL) {
		(*now).pos.x = next_pos.x;
		(*now).pos.y = next_pos.y;
		now = (*now).up;
	}

	(*now).pos.x = next_pos.x;
	(*now).pos.y = next_pos.y;

	chessman.down = chessman_map[chessman.pos.x][chessman.pos.y];
	if (chessman.down != NULL) {
		(*chessman.down).up = &chessman;
	}
	
	chessman_map[chessman.pos.x][chessman.pos.y] = now;
}

void moveToRed(vector<vector<Chessman*> > &chessman_map, Chessman &chessman) {
	moveToWhite(chessman_map, chessman);
	
	Chessman *now = &chessman;
	while ((*now).up != NULL) {
		swapChessman(&((*now).up), &((*now).down));
		now = (*now).down;
	}
	swapChessman(&((*now).up), &((*now).down));
	swapChessman(&((*now).down), &(chessman.up));
	if ((*now).down != NULL) {
		(*(*now).down).up = now;
	}

	chessman_map[chessman.pos.x][chessman.pos.y] = &chessman;
}

void moveToBlue(const vector<vector<Color> > &color_map, vector<vector<Chessman*> > &chessman_map, Chessman &chessman) {
	changeDir(chessman.dir);
	
	Pos next_pos(chessman.pos.x + dxy[chessman.dir].x, chessman.pos.y + dxy[chessman.dir].y);
	if ((next_pos.x < 0) || (next_pos.y < 0) || 
		(next_pos.x >= color_map.size()) || (next_pos.y >= color_map.size()) ||
		(color_map[next_pos.x][next_pos.y] == COLOR_BLUE)) {
			return;
	}
		
	if (color_map[next_pos.x][next_pos.y] == COLOR_WTHIE) {
		moveToWhite(chessman_map, chessman);
	} else if (color_map[next_pos.x][next_pos.y] == COLOR_RED) {
		moveToRed(chessman_map, chessman);
	}
}

void move(const vector<vector<Color> > &color_map, vector<vector<Chessman*> > &chessman_map, Chessman &chessman) {
	Pos next_pos(chessman.pos.x + dxy[chessman.dir].x, chessman.pos.y + dxy[chessman.dir].y);
	
	if ((next_pos.x < 0) || (next_pos.y < 0) || 
		(next_pos.x >= color_map.size()) || (next_pos.y >= color_map.size())) {
			moveToBlue(color_map, chessman_map, chessman);
	} else {
		if (color_map[next_pos.x][next_pos.y] == COLOR_WTHIE) {
			moveToWhite(chessman_map, chessman);
		} else if (color_map[next_pos.x][next_pos.y] == COLOR_RED) {
			moveToRed(chessman_map, chessman);
		} else if (color_map[next_pos.x][next_pos.y] == COLOR_BLUE) {
			moveToBlue(color_map, chessman_map, chessman);
		}
	}

}

bool check(const vector<vector<Chessman*> > &chessman_map, int remain) {
	for (int x = 0; x < chessman_map.size(); x++) {
		for (int y = 0; y < chessman_map[x].size(); y++) {
			int cnt = 0;
			Chessman *now = chessman_map[x][y];
			while (now != NULL) {
				cnt += 1;
				now = (*now).down;
			}

			if (cnt >= 4) {
				return true;
			}

			remain -= cnt;
			if (remain < 4) {
				return false;
			}
		}
	}
	return false;
}

bool simulation(const vector<vector<Color> > &color_map, vector<vector<Chessman*> > &chessman_map, vector<Chessman> &chessman_list) {
	for (int i = 0; i < chessman_list.size(); i++) {
		move(color_map, chessman_map, chessman_list[i]);
		if (check(chessman_map, chessman_list.size()) == true) {
			return true;
		}
	}
	return false;
}

/* solution */
int solution(const vector<vector<Color> > &color_map, vector<vector<Chessman*> > &chessman_map, vector<Chessman> &chessman_list) {
	for (int ans = 1; ans <= ANS_MAX; ans++) {
		if (simulation(color_map, chessman_map, chessman_list) == true) {
			return ans;
		}
	}

	return -1;
}


/* main */
int main() {
	IOS_SETTING

	int N, K;
	cin >> N >> K;

	vector<vector<Color> > color_map(N, vector<Color> (N));
	vector<vector<Chessman*> > chessman_map(N, vector<Chessman*> (N, NULL));
	vector<Chessman> chessman_list(K);

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			int input_color;
			cin >> input_color;
			color_map[x][y] = (Color) input_color;
		}
	}

	for (int k = 0; k < K; k++) {
		int input_x, input_y, input_dir;
		cin >> input_x >> input_y >> input_dir;
		chessman_list[k].pos.x = input_x - 1;
		chessman_list[k].pos.y = input_y - 1;
		chessman_list[k].dir = (Dir) (input_dir - 1);
		chessman_list[k].up = NULL;
		chessman_list[k].down = NULL;
		chessman_map[chessman_list[k].pos.x][chessman_list[k].pos.y] = &(chessman_list[k]);
	}
	check(chessman_map, 0);
	cout << solution(color_map, chessman_map, chessman_list) << "\n";

	return 0;
}