#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

#define LIMIT 11

int N, M;
char map[10][10];
pair<int, int> d[4];


int go(pair<int, int> B, pair<int, int> R, int di, int c) {
	if (c == LIMIT) {
		return LIMIT;
	}
	int ret = LIMIT;
	bool goal = false;
	bool fail = true;
	while (1) {
		bool bMoved = false;
		bool rMoved = false;

		pair<int, int> nextB = make_pair(B.first+d[di].first, B.second+d[di].second);
		pair<int, int> nextR = make_pair(R.first+d[di].first, R.second+d[di].second);
		if ((map[nextB.first][nextB.second] != '#') && ((goal) || (nextB != R))) {
			B = nextB;
			bMoved = true;
			fail = false;
		}
	
		if ((!goal) && (map[nextR.first][nextR.second] != '#') && (nextR != B)) {
			R = nextR;
			rMoved = true;
			fail = false;
		}

		if ((!bMoved) && (map[nextB.first][nextB.second] != '#') && ((goal) || (nextB != R))) {
			B = nextB;
			bMoved =true;
			fail = false;
		}

		if ((bMoved) && (map[B.first][B.second] == 'O')) {
			ret = LIMIT;
			fail = true;
			break;
		} else if ((!goal) && (rMoved) && (map[R.first][R.second] == 'O')) {
			ret = c;
			goal = true;
		}

		if ((!bMoved) && (!rMoved)) {
			break;
		}
	}
	if (!fail) {
		for (int i = 0; i < 4; i++) {
			if ((i != di) && (i != (di+2) % 4)) {
				ret = min(ret, go(B, R, i, c+1));
			}
		}
	}
	
	return ret;
}

int main() {
	int ret = LIMIT;
	d[0] = make_pair(-1, 0);
	d[1] = make_pair(0, 1);
	d[2] = make_pair(1, 0);
	d[3] = make_pair(0, -1);

	cin >> N >> M;
	pair <int, int> B, R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				B = make_pair(i, j);
				map[i][j] = '.';
			} else if (map[i][j] == 'R') {
				R = make_pair(i, j);
				map[i][j] = '.';
			}
		}
	}
	for (int i = 0 ; i < 4; i++) {
		ret = min(ret, go(B, R, i, 1));
	}
	if (ret >= LIMIT) {
		ret = -1;
	}
	cout << ret << endl;

	return 0;
}
