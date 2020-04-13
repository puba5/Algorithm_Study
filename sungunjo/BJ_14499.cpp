#include <iostream>
#include <vector>
using namespace std;

typedef struct _dice {
	int top;
	int bottom;
	int left;
	int right;
	int front;
	int back;

	_dice(int _top = 0, int _bottom = 0, 
		int _left = 0, int _right = 0, 
		int _front = 0, int _back = 0) : top(_top), bottom(_bottom),
										left(_left), right(_right),
										front(_front), back(_back) {};

} Dice;

typedef struct _position {
	int x;
	int y;

	_position(int _x, int _y) : x(_x), y(_y) {};
} Position;

typedef enum _direction {
	EAST = 0,
	WEST,
	NORTH,
	SOUTH,
	DIRECTION_SIZE
} Direction;

Position dir_d[DIRECTION_SIZE] = {
	Position(0, 1),
	Position(0, -1),
	Position(-1, 0),
	Position(1, 0)
};

void round_robin(int &a, int &b, int &c, int &d) {
	// 시계방향으로 라운드로빈해주는 함수
	// a -> b -> c -> d -> a
	int _a = a;
	a = d;
	d = c;
	c = b;
	b = _a;
}

void diceMove(Dice &dice, Direction dir) {
	if (dir == EAST) {
		round_robin(dice.top, dice.right, dice.bottom, dice.left);
	} else if (dir == WEST) {
		round_robin(dice.top, dice.left, dice.bottom, dice.right);
	} else if (dir == NORTH) {
		round_robin(dice.top, dice.back, dice.bottom, dice.front);
	} else if (dir == SOUTH) {
		round_robin(dice.top, dice.front, dice.bottom, dice.back);
	}
}

void simul(vector<vector<int> > &map, const vector<Direction> &dir_list, Position dice_pos) {
	int N = map.size();
	int M = map[0].size();
	int K = dir_list.size();

	Dice dice(0, 0, 0, 0, 0, 0);

	for (int k = 0; k < K; k++) {
		dice_pos.x += dir_d[(int) dir_list[k]].x;
		dice_pos.y += dir_d[(int) dir_list[k]].y;

		if ((dice_pos.x < 0) || (dice_pos.y < 0) ||
			(dice_pos.x >= N) || (dice_pos.y >= M)) {
			dice_pos.x -= dir_d[(int) dir_list[k]].x;
			dice_pos.y -= dir_d[(int) dir_list[k]].y;
			continue;
		}

		diceMove(dice, dir_list[k]);

		if (map[dice_pos.x][dice_pos.y] == 0) {
			map[dice_pos.x][dice_pos.y] = dice.bottom;
		} else {
			dice.bottom = map[dice_pos.x][dice_pos.y];
			map[dice_pos.x][dice_pos.y] = 0;
		}

		printf("%d\n", dice.top);
	}
}

int main() {
	int N, M, x, y, K;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

	vector<vector<int> > map(N, vector<int> (M, 0));
	vector<Direction> dir_list(K); 

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			scanf("%d", &(map[n][m]));
		}
	}

	for (int k = 0; k < K; k++) {
		int int_dir;
		scanf("%d", &int_dir);
		dir_list[k] = (Direction) (int_dir - 1);
	}

	simul(map, dir_list, Position(x, y));

	return 0;
}