#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define MAP_SIZE 100
#define INIT_MAP_SIZE 3

typedef struct _info {
	int num;
	int cnt;

	_info() : num(0), cnt(0) {};
	_info(int _num, int _cnt) : num(_num), cnt(_cnt) {};
} Info;

bool comp(const Info &a, const Info &b) {
	if (a.cnt < b.cnt) {
		return true;
	} else if (a.cnt > b.cnt) {
		return false;
	} else {
		if (a.num < b.num) {
			return true;
		} else {
			return false;
		}
	}
}

void fillRowToZero(int map[MAP_SIZE][MAP_SIZE], int r, int start) {
	for (int i = start; i < MAP_SIZE; i++) {
		map[r][i] = 0;
	}
}

void fillColToZero(int map[MAP_SIZE][MAP_SIZE], int c, int start) {
	for (int i = start; i < MAP_SIZE; i++) {
		map[i][c] = 0;
	}
}

int calcR(int map[MAP_SIZE][MAP_SIZE], int max_r, int max_c) {
	int max_len = 0;
	for (int r = 0; r < max_r; r++) {
		std::map<int, int> m;
		for (int c = 0; c < max_c; c++) {
			if (map[r][c] == 0) {
				continue;
			}
			std::map<int, int>::iterator key_value = m.find(map[r][c]);
			if (key_value == m.end()) {
				m.insert(make_pair(map[r][c], 1));
			} else {
				(*key_value).second += 1;
			}
		}

		int m_size = m.size();
		int v_idx = 0;
		vector<Info> v(m_size);
		std::map<int, int>::iterator iter = m.begin();
		for (; iter != m.end(); iter++) {
			v[v_idx].num = (*iter).first;
			v[v_idx].cnt = (*iter).second;
			v_idx += 1;
		}
		sort(v.begin(), v.end(), comp);

		int len = min(m_size * 2, MAP_SIZE);
		v_idx = 0;
		for (int i = 0; i < len; i++) {
			map[r][i] = v[v_idx].num;
			i += 1;
			map[r][i] = v[v_idx].cnt;
			v_idx += 1;
		}
		fillRowToZero(map, r, len);
		max_len = max(max_len, len);
	}
	return max_len;
}

int calcC(int map[MAP_SIZE][MAP_SIZE], int max_r, int max_c) {
	int max_len = 0;
	for (int c = 0; c < max_c; c++) {
		std::map<int, int> m;
		for (int r = 0; r < max_r; r++) {
			if (map[r][c] == 0) {
				continue;
			}
			std::map<int, int>::iterator key_value = m.find(map[r][c]);
			if (key_value == m.end()) {
				m.insert(make_pair(map[r][c], 1));
			} else {
				(*key_value).second += 1;
			}
		}

		int m_size = m.size();

		int v_idx = 0;
		vector<Info> v(m_size);
		std::map<int, int>::iterator iter = m.begin();
		for (; iter != m.end(); iter++) {
			v[v_idx].num = (*iter).first;
			v[v_idx].cnt = (*iter).second;
			v_idx += 1;
		}
		sort(v.begin(), v.end(), comp);

		int len = min(m_size * 2, MAP_SIZE);
		v_idx = 0;
		for (int i = 0; i < len; i++) {
			map[i][c] = v[v_idx].num;
			i += 1;
			map[i][c] = v[v_idx].cnt;
			v_idx += 1;
		}
		fillColToZero(map, c, len);
		max_len = max(max_len, len);
	}
	return max_len;
}

void simulation(int map[MAP_SIZE][MAP_SIZE], int &row_num, int &col_num) {
	if (row_num < col_num) {
		row_num = calcC(map, row_num, col_num);
	} else {
		col_num = calcR(map, row_num, col_num);
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int r, c, k;
	cin >> r >> c >> k;

	int map[MAP_SIZE][MAP_SIZE];

	for (int i = 0; i < MAP_SIZE; i++) {
		memset(map, 0, MAP_SIZE * sizeof(int));
	}

	for (int i = 0; i < INIT_MAP_SIZE; i++) {
		for (int j = 0; j < INIT_MAP_SIZE; j++) {
			cin >> map[i][j];
		}
	}

	int ans = -1;
	int row_num = INIT_MAP_SIZE, col_num = INIT_MAP_SIZE;
	for (int i = 0; i <= 100; i++) {
		if (map[r - 1][c - 1] == k) {
			ans = i;
			break;
		}
		simulation(map, row_num, col_num);
	}

	cout << ans << "\n";

	return 0;
}