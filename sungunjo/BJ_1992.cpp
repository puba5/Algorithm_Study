#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define IOS_SYNC_SETTING \
ios::sync_with_stdio(false); \
cin.tie(NULL); \
cout.tie(NULL); \

int check(int **map, int len, int start_x, int start_y) {
	int end_x = start_x + len;
	int end_y = start_y + len;
	int start_value = map[start_x][start_y];
	for (int x = start_x; x < end_x; x++) {
		for (int y = start_y; y < end_y; y++) {
			if (start_value != map[x][y]) {
				return -1;
			}
		}
	}
	return start_value;
}

void go(int **map, int len, int start_x, int start_y) {
	int check_result = check(map, len, start_x, start_y);
	
	if (check_result == -1) {
		cout << "(";

		int next_len = len / 2;
		int left_up_x = start_x, left_up_y = start_y;
		int right_up_x = start_x, right_up_y = start_y + next_len;
		int left_down_x = start_x + next_len, left_down_y = start_y;
		int right_down_x = start_x + next_len, right_down_y = start_y + next_len;

		go(map, next_len, left_up_x, left_up_y);
		go(map, next_len, right_up_x, right_up_y);
		go(map, next_len, left_down_x, left_down_y);
		go(map, next_len, right_down_x, right_down_y);

		cout << ")";
	} else {
		cout << check_result;
	}
}

int main() {
	IOS_SYNC_SETTING

	int N;
	cin >> N;

	int **map = new int*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
	}

	for (int x = 0; x < N; x++) {
		string line;
		cin >> line;
		for (int y = 0; y < N; y++) {
			map[x][y] = line[y] - '0';
		}
	}
	
	go(map, N, 0, 0);


	return 0;
}