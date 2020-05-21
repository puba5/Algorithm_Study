#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define IOS_SETTING \
ios::sync_with_stdio(false); \
cin.tie(NULL); \
cout.tie(NULL);

#define SPACE 0
#define WALL 1

typedef struct _pos {
	int x;
	int y;

	_pos() : x(0), y(0) {};
	_pos(int _x, int _y) : x(_x), y(_y) {};

} Pos;

typedef enum _dir {
	DIR_HORIZONTAL = 0,
	DIR_DIAGONAL,
	DIR_VERTICAL,
	DIR_SIZE
} Dir;

class Pipe {
private:
	Pos back;
	Pos front;

	int N;

	Dir dir;

public:
	Pipe();
	Pipe(int _N);

	bool moveHorizontal(const vector<vector<int> > &map);
	bool moveDiagonal(const vector<vector<int> > &map);
	bool moveVertical(const vector<vector<int> > &map);

	bool isEnd(const vector<vector<int> > &map);
};

int go(const vector<vector<int> > &map, Pipe pipe) {
	if (pipe.isEnd(map)) {
		return 1;
	}

	int sum = 0;

	Pipe origin_pipe = pipe;
	if (pipe.moveHorizontal(map) == true) {
		sum += go(map, pipe);
	}
	pipe = origin_pipe;
	if (pipe.moveDiagonal(map) == true) {
		sum += go(map, pipe);
	}
	pipe = origin_pipe;
	if (pipe.moveVertical(map) == true) {
		sum += go(map, pipe);
	}

	return sum;
}

int main() {
	IOS_SETTING

	int N;
	cin >> N;

	vector<vector<int> > map(N, vector<int> (N));
	Pipe pipe(N);

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> map[x][y];
		}
	}

	cout << go(map, pipe) << "\n";

	return 0;
}

Pipe::Pipe() {
	(*this).back.x = 0;
	(*this).back.y = 0;

	(*this).front.x = 0;
	(*this).front.y = 1;

	(*this).dir = DIR_HORIZONTAL;
}

Pipe::Pipe(int _N) {
	(*this).back.x = 0;
	(*this).back.y = 0;

	(*this).front.x = 0;
	(*this).front.y = 1;

	(*this).dir = DIR_HORIZONTAL;

	(*this).N = _N;
}

bool Pipe::moveHorizontal(const vector<vector<int> > &map) {
	if (((*this).dir == DIR_VERTICAL)||
		((*this).front.y + 1 >= (*this).N) ||
		(map[(*this).front.x][(*this).front.y + 1] == WALL)) {
		return false;
	}

	(*this).back.x = (*this).front.x;
	(*this).back.y = (*this).front.y;

	(*this).front.y += 1;

	(*this).dir = DIR_HORIZONTAL;

	return true;
}

bool Pipe::moveDiagonal(const vector<vector<int> > &map) {
	if (((*this).front.x + 1 >= (*this).N) ||
		((*this).front.y + 1 >= (*this).N) ||
		(map[(*this).front.x + 1][(*this).front.y] == WALL) ||
		(map[(*this).front.x][(*this).front.y + 1] == WALL) ||
		(map[(*this).front.x + 1][(*this).front.y + 1] == WALL)) {
		return false;
	}
	(*this).back.x = (*this).front.x;
	(*this).back.y = (*this).front.y;

	(*this).front.x += 1;
	(*this).front.y += 1;

	(*this).dir = DIR_DIAGONAL;

	return true;
}

bool Pipe::moveVertical(const vector<vector<int> > &map) {
	if (((*this).dir == DIR_HORIZONTAL) ||
		((*this).front.x + 1 >= (*this).N) ||
		(map[(*this).front.x + 1][(*this).front.y] == WALL)) {
		return false;
	}
	(*this).back.x = (*this).front.x;
	(*this).back.y = (*this).front.y;

	(*this).front.x += 1;

	(*this).dir = DIR_VERTICAL;

	return true;
}

bool Pipe::isEnd(const vector<vector<int> > &map) {
	if (((*this).front.x == map.size() - 1) &&
		((*this).front.y == map.size() - 1)) {
		return true;
	} else {
		return false;
	}
}