#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
using namespace std;

enum {
	UP, DOWN, LEFT, RIGHT
};

vector< pair<int, char> > vx[300001], vy[300001];

void insert(vector< pair<int, char> > &v, pair<int, char> input) {
    int left = 0, right = (int)v.size() - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if (mid < input.first) {
            left = mid + 1;
        } else if (input.first < mid) {
            right = mid - 1;
        } else {
            return;
        }
    }
    
    if (left < (int)v.size()) {
        v.insert(v.begin() + left, input);
    } else {
        v.push_back(input);
    }
}

pair<int, int> check(int x, int y, int dir, int index, int cnt, int dist, int total_dist) {
	if (dir == UP) {
		if (index == -1) {
			index = vy[y].size() - 1;
			if (index < 0) {
				return make_pair(0, 0);
			}
		}
		dist += (x - vy[y][index].first);

		int new_x = vy[y][index].first;

		if (vy[y][index].second == '!') {
			cnt++;
			total_dist += dist;
			if (index > 0) {
				index--;
				return check(new_x, y, dir, index, cnt, dist, total_dist);
			} else {
				return make_pair(cnt, total_dist);
			}
		} else if (vy[y][index].second == '/') {
			int len = vx[new_x].size();
			int new_y = -1;
			for (int i = 0; i < len; i++) {
				if (vx[new_x][i].first > y) {
					new_y = vx[new_x][i].first;
					index = i;
					break;
				}
			}
			if (new_y != -1) {
				return check(new_x, y, RIGHT, index, cnt, dist, total_dist);
			} else {
				return make_pair(cnt, total_dist);
			}
		} else if (vy[y][index].second == '\\') {
			int new_y = -1;
			for (int i = vx[new_x].size()-1; i >= 0; i--) {
				if (vx[new_x][i].first < y) {
					new_y = vx[new_x][i].first;
					index = i;
					break;
				}
			}
			if (new_y != -1) {
				return check(new_x, y, LEFT, index, cnt, dist, total_dist);
			} else {
				return make_pair(cnt, total_dist);
			}
		}
	} else if (dir == DOWN) {
		if (index == -1) {
			index = 0;
			if (vy[y].size() == 0) {
				return make_pair(0, 0);
			}
		}

		dist += (vy[y][index].first - x);

		int new_x = vy[y][index].first;

		if (vy[y][index].second == '!') {
			cnt++;
			total_dist += dist;
			if (index < vy[y].size() - 1) {
				index++;
				return check(new_x, y, dir, index, cnt, dist, total_dist);
			} else {
				return make_pair(cnt, total_dist);
			}
		} else if (vy[y][index].second == '/') {
			int new_y = -1;
			for (int i = vx[new_x].size() - 1; i >= 0; i--) {
				if (vx[new_x][i].first < y) {
					new_y = vx[new_x][i].first;
					index = i;
					break;
				}
			}
			if (new_y != -1) {
				return check(new_x, y, LEFT, index, cnt, dist, total_dist);
			} else {
				return make_pair(cnt, total_dist);
			}
		} else if (vy[y][index].second == '\\') {
			int len = vx[new_x].size();
			int new_y = -1;
			for (int i = 0; i < len; i++) {
				if (vx[new_x][i].first > y) {
					new_y = vx[new_x][i].first;
					index = i;
					break;
				}
			}
			if (new_y != -1) {
				return check(new_x, y, RIGHT, index, cnt, dist, total_dist);
			} else {
				return make_pair(cnt, total_dist);
			}
		}

	} else if (dir == LEFT) {
		if (index == -1) {
			index = vx[x].size() - 1;
			if (index < 0) {
				return make_pair(0, 0);
			}
		}

		dist += (y - vx[x][index].first);

		int new_y = vx[x][index].first;

		if (vx[x][index].second == '!') {
			cnt++;
			total_dist += dist;
			if (index > 0) {
				index--;
				return check(x, new_y, dir, index, cnt, dist, total_dist);
			} else {
				return make_pair(cnt, total_dist);
			}
		} else if (vx[x][index].second == '/') {
			int len = vy[new_y].size();
			int new_x = -1;
			for (int i = 0; i < len; i++) {
				if (vy[new_y][i].first > x) {
					new_x = vy[new_y][i].first;
					index = i;
					break;
				}
			}
			if (new_x != -1) {
				return check(x, new_y, DOWN, index, cnt, dist, total_dist);
			} else {
				return make_pair(cnt, total_dist);
			}
		} else if (vx[x][index].second == '\\') {
			int new_x = -1;
			for (int i = vy[new_y].size()-1; i >= 0; i--) {
				if (vy[new_y][i].first < x) {
					new_x = vy[new_y][i].first;
					index = i;
					break;
				}
			}
			if (new_x != -1) {
				return check(x, new_y, UP, index, cnt, dist, total_dist);
			} else {
				return make_pair(cnt, total_dist);
			}
		}

	} else if (dir == RIGHT) {
		if (index == -1) {
			index = 0;
			if (vx[x].size() == 0) {
				return make_pair(0, 0);
			}
		}
		dist += (vx[x][index].first - y);

		int new_y = vx[x][index].first;

		if (vx[x][index].second == '!') {
			cnt++;
			total_dist += dist;
			if (index < vx[x].size() - 1) {
				index++;
				return check(x, new_y, dir, index, cnt, dist, total_dist);
			} else {
				return make_pair(cnt, total_dist);
			}
		} else if (vx[x][index].second == '/') {
			int new_x = -1;
			for (int i = vy[new_y].size()-1; i >= 0; i--) {
				if (vy[new_y][i].first < x) {
					new_x = vy[new_y][i].first;
					index = i;
					break;
				}
			}
			if (new_x != -1) {
				return check(x, new_y, UP, index, cnt, dist, total_dist);
			} else {
				return make_pair(cnt, total_dist);
			}
		} else if (vx[x][index].second == '\\') {
			int len = vy[new_y].size();
			int new_x = -1;
			for (int i = 0; i < len; i++) {
				if (vy[new_y][i].first > x) {
					new_x = vy[new_y][i].first;
					index = i;
					break;
				}
			}
			if (new_x != -1) {
				return check(x, new_y, DOWN, index, cnt, dist, total_dist);
			} else {
				return make_pair(cnt, total_dist);
			}
		}
	}
	return make_pair(-1, -1);
}

int main() {
	int N, M, K, Q;
	cin >> N >> M >> K >> Q;

	for (int k = 0; k < K; k++) {
		int x, y;
		char c;
		scanf("%d %d %c", &x, &y, &c);
		insert(vx[x], make_pair(y, c));
		insert(vy[y], make_pair(x, c));
	}


	for (int q = 0; q < Q; q++) {
		char tmp[300001];

		scanf("%s", &tmp);
		char *tmp2 = &tmp[1];

		int dir;
		int _x, _y;
		if (tmp[0] == 'D') {
			dir = UP;
			_x = N+1; _y = atoi(tmp2);
		} else if (tmp[0] == 'U') {
			dir = DOWN;
			_x = 0; _y = atoi(tmp2);
		} else if (tmp[0] == 'R') {
			dir = LEFT;
			_x = atoi(tmp2); _y = M+1;
		} else if (tmp[0] == 'L') {
			dir = RIGHT;
			_x = atoi(tmp2); _y = 0;
		}
		pair<int, int> ans = check(_x, _y, dir, -1, 0, 0, 0);
		printf("%d %d\n", ans.first, ans.second);
	}

	return 0;
}
