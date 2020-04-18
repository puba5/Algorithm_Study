#include <iostream>
#include <vector>
using namespace std;

#define APPLE -2
#define SPACE -1

typedef enum _comp_dir {
	NORTH = 0,
	EAST,
	SOUTH,
	WEST,
	COMP_DIR_SIZE
} CompDir;


typedef struct _pos {
	int x;
	int y;
	
	_pos(int _x, int _y) : x(_x), y(_y) {};
} Pos;

typedef struct _dir_conv {
	int sec;
	char dir;

	_dir_conv(int _sec, char _dir) : sec(_sec), dir(_dir) {};
} DirConv;

typedef struct _state {
	Pos head;
	Pos tail;
	CompDir dir;

	_state(Pos _head, Pos _tail, CompDir _dir) : head(_head), tail(_tail), dir(_dir) {};
} State;


Pos dir[COMP_DIR_SIZE] = {
	Pos(-1, 0),
	Pos(0, 1),
	Pos(1, 0),
	Pos(0, -1)
};


// 테스트용
void printMap(const vector<vector<int> > &map) {
	int N = map.size();
	printf("\n========================================\n");
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			printf("%3d ", map[x][y]);
		}
		printf("\n");
	}
	printf("========================================\n");
}

int simul(vector<vector<int> > &map, vector<DirConv> &dir_conv) {
	// 시작 뱀 세팅
	int N = map.size();
	State state(Pos(0, 0), Pos(0, 0), EAST);
	map[0][0] = 0;

	int dir_conv_index = 0;

	// 게임 반복
	while(true) {
		// x초 이동
		Pos next_head(state.head.x + dir[state.dir].x, state.head.y + dir[state.dir].y);
		int next_sec = map[state.head.x][state.head.y] + 1;

		// 벽 충돌시 게임 끝
		if ((next_head.x < 0) || (next_head.y < 0) ||
			(next_head.x >= N) || (next_head.y >= N)) {
			return next_sec;
		}

		// 머리 이동 후 뭐 있는지 파악
		state.head = next_head;
		if (map[next_head.x][next_head.y] == APPLE) {
			// 사과 먹은 경우
			map[next_head.x][next_head.y] = next_sec;

		} else if (map[next_head.x][next_head.y] == SPACE) {
			// 빈 공간인 경우 꼬리도 이동
			map[next_head.x][next_head.y] = next_sec;
			// 다음 꼬리 위치 찾아서 변경
			for (int d = 0; d < COMP_DIR_SIZE; d++) {
				Pos next_tail(state.tail.x + dir[d].x, state.tail.y + dir[d].y);
				int next_tail_sec = map[state.tail.x][state.tail.y] + 1;
				if ((next_tail.x < 0) || (next_tail.y < 0) ||
					(next_tail.x >= N) || (next_tail.y >= N)) {
					continue;
				}

				if (map[next_tail.x][next_tail.y] == next_tail_sec) {
					// 다음 꼬리 위치 찾았으면 이전 꼬리 지움
					map[state.tail.x][state.tail.y] = SPACE;
					state.tail = next_tail;
					break;
				}
			}
		} else {
			// 자기 자신 몸이랑 마주친 경우 게임 끝
			return next_sec;
		}

		// x초 종료, 방향 전환
		if ((dir_conv_index < dir_conv.size()) &&
			(next_sec == dir_conv[dir_conv_index].sec)) {
			if (dir_conv[dir_conv_index].dir == 'L') {
				// 왼쪽으로 회전
				state.dir = (CompDir) (((int) state.dir + COMP_DIR_SIZE - 1) % COMP_DIR_SIZE);
			} else if (dir_conv[dir_conv_index].dir == 'D') {
				// 오른쪽으로 회전
				state.dir = (CompDir) (((int) state.dir + 1) % COMP_DIR_SIZE);
			}

			dir_conv_index += 1;
		}
	}

	return -1;
}


int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	// 사과: -2, 빈공간: -1, 뱀: 0 이상 int
	vector<vector<int> > map(N, vector<int> (N, SPACE));
	for (int k = 0; k < K; k++) {
		int _x, _y;
		scanf("%d %d", &_x, &_y);

		map[_x - 1][_y - 1] = APPLE;
	}

	int L;
	scanf("%d", &L);
	vector<DirConv> dir_conv;
	
	for (int l = 0; l < L; l++) {
		int _sec;
		char _dir;
		scanf("%d %c", &_sec, &_dir);

		dir_conv.push_back(DirConv(_sec, _dir));
	}

	printf("%d\n", simul(map, dir_conv));

	return 0;
}