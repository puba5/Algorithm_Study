#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

typedef enum _kind {
	MINUS = 0,
	ZERO,
	PLUS,
	KIND_SIZE
} Kind;

bool check(const vector<vector<int> > &map, int x_start, int y_start, int size) {
	int num = map[x_start][y_start];
	for (int i = x_start; i < x_start + size; i++) {
		for (int j = y_start; j < y_start + size; j++) {
			if (num != map[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void go(const vector<vector<int> > &map, int x_start, int y_start, int size, int ans[KIND_SIZE]) {
	if (check(map, x_start, y_start, size) == true) {
		if (map[x_start][y_start] == -1) {
			ans[MINUS] += 1;
		} else if (map[x_start][y_start] == 0) {
			ans[ZERO] += 1;
		} else {
			ans[PLUS] += 1;
		}
	} else {
		int new_size = size / 3;
		go(map, x_start, y_start, new_size, ans);
		go(map, x_start, y_start + new_size, new_size, ans);
		go(map, x_start, y_start + (2 * new_size), new_size, ans);

		go(map, x_start + new_size, y_start, new_size, ans);
		go(map, x_start + new_size, y_start + new_size, new_size, ans);
		go(map, x_start + new_size, y_start + (2 * new_size), new_size, ans);

		go(map, x_start + (2 * new_size), y_start, new_size, ans);
		go(map, x_start + (2 * new_size), y_start + new_size, new_size, ans);
		go(map, x_start + (2 * new_size), y_start + (2 * new_size), new_size, ans);

	}
}

int main() {
	int k;
	cin >> k;

	vector<vector<int> > map(k, vector<int> (k));
	int ans[KIND_SIZE] = {0, 0, 0};

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			cin >> map[i][j];
		}
	}
	
	go(map, 0, 0, k, ans);
	cout << ans[MINUS] << "\n" << ans[ZERO] << "\n" << ans[PLUS] << "\n";

	return 0;
}