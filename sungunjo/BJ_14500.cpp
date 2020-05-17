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

int lineFirst(const vector<vector<int> > &map, int x, int y_start) {
	int sum = 0;
	for (int y = y_start; y < y_start + 4; y++) {
		if (y >= map[x].size()) {
			return -1;
		}

		sum += map[x][y];
	}
	return sum;
}

int lineSecond(const vector<vector<int> > &map, int x_start, int y) {
	int sum = 0;
	for (int x = x_start; x < x_start + 4; x++) {
		if (x >= map.size()) {
			return -1;
		}

		sum += map[x][y];
	}

	return sum;
}

int square(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	for (int x = x_start; x < x_start + 2; x++) {
		if (x >= map.size()) {
			return -1;
		}
		for (int y = y_start; y < y_start + 2; y++) {
			if (y >= map[x].size()) {
				return -1;
			}

			sum += map[x][y];
		}
	}

	return sum;
}

int neeunFirst(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;
	for (int x = x_start; x < x_start + 3; x++) {
		if (x >= map.size()) {
			return -1;
		}
		sum += map[x][y];
	}

	x += 2;
	y += 1;
	if ((x >= map.size()) || (y >= map[x].size())) {
		return -1;
	}

	sum += map[x][y];
	return sum;
}

int neeunSecond(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;
	for (int y = y_start; y < y_start + 3; y++) {
		if (y >= map[x].size()) {
			return -1;
		}

		sum += map[x][y];
	}

	x += 1;
	if (x >= map.size()) {
		return -1;
	}

	sum += map[x][y];
	return sum;
}

int neeunThird(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;
	sum += map[x][y];
	y += 1;
	if (y >= map[x].size()) {
		return -1;
	}
	for (int x = x_start; x < x_start + 3; x++) {
		if (x >= map.size()) {
			return -1;
		}

		sum += map[x][y];
	}

	return sum;
}

int neeunFourth(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;

	y+= 2;
	if (y >= map[x].size()) {
		return -1;
	}
	sum += map[x][y];

	x += 1;
	if (x >= map.size()) {
		return -1;
	}
	for (int y = y_start; y < y_start + 3; y++) {
		if (y >= map[x].size()) {
			return -1;
		}

		sum += map[x][y];
	}

	return sum;
}

int neeunFifth(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;

	x += 2;
	if (x >= map.size()) {
		return -1;
	}
	sum += map[x][y];

	y += 1;
	if (y >= map[x].size()) {
		return -1;
	}
	for (int x = x_start; x < x_start + 3; x++) {
		if (x >= map.size()) {
			return -1;
		}

		sum += map[x][y];
	}

	return sum;
} 

int neeunSixth(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;

	sum += map[x][y];

	x += 1;
	if (x >= map.size()) {
		return -1;
	}
	for (int y = y_start; y < y_start + 3; y++) {
		if (y >= map[x].size()) {
			return -1;
		}

		sum += map[x][y];
	}

	return sum;
}

int neeunSeventh(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;

	for (int x = x_start; x < x_start + 3; x++) {
		if (x >= map.size()) {
			return -1;
		}

		sum += map[x][y];
	}

	y += 1;
	if (y >= map[x].size()) {
		return -1;
	}
	sum += map[x][y];

	return sum;
}

int neeunEighth(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;

	for (int y = y_start; y < y_start + 3; y++) {
		if (y >= map[x].size()) {
			return -1;
		}

		sum += map[x][y];
	}

	x += 1;
	y += 2;
	if ((x >= map.size()) || (y >= map[x].size())) {
		return -1;
	}

	sum += map[x][y];

	return sum;
}

int thunderFirst(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;
	for (int x = x_start; x < x_start + 2; x++) {
		if (x >= map.size()) {
			return -1;
		}

		sum += map[x][y];
	}

	y += 1;
	if (y >= map[x].size()) {
		return -1;
	}
	for (int x = x_start + 1; x < x_start + 3; x++) {
		if (x >= map.size()) {
			return -1;
		}

		sum += map[x][y];
	}

	return sum;
}

int thunderSecond(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;

	for (int y = y_start + 1; y < y_start + 3; y++) {
		if (y >= map[x].size()) {
			return -1;
		}

		sum += map[x][y];
	}

	x += 1;
	if (x >= map.size()) {
		return -1;
	}
	for (int y = y_start; y < y_start + 2; y++) {
		if (y >= map[x].size()) {
			return -1;
		}

		sum += map[x][y];
	}

	return sum;
}

int thunderThird(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;

	for (int x = x_start + 1; x < x_start + 3; x++) {
		if (x >= map.size()) {
			return -1;
		}

		sum += map[x][y];
	}

	y += 1;
	if (y >= map[x].size()) {
		return -1;
	}
	for (int x = x_start; x < x_start + 2; x++) {
		if (x >= map.size()) {
			return -1;
		}

		sum += map[x][y];
	}

	return sum;
}

int thunderFourth(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;

	for (int y = y_start; y < y_start + 2; y++) {
		if (y >= map[x].size()) {
			return -1;
		}

		sum += map[x][y];
	}

	x += 1;
	if (x >= map.size()) {
		return -1;
	}
	for (int y = y_start + 1; y < y_start + 3; y++) {
		if (y >= map[x].size()) {
			return -1;
		}

		sum += map[x][y];
	}

	return sum;
}

int hatFirst(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;

	for (int y = y_start; y < y_start + 3; y++) {
		if (y >= map[x].size()) {
			return -1;
		}

		sum += map[x][y];
	}
	x += 1;
	y += 1;
	if ((x >= map.size()) || (y >= map[x].size())) {
		return -1;
	}
	sum += map[x][y];
	
	return sum;
}

int hatSecond(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;

	x += 1;
	if (x >= map.size()) {
		return -1;
	}
	sum += map[x][y];

	y += 1;
	if (y >= map[x].size()) {
		return -1;
	}
	for (int x = x_start; x < x_start + 3; x++) {
		if (x >= map.size()) {
			return -1;
		}

		sum += map[x][y];
	}

	return sum;
}

int hatThird(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;
	y += 1;
	if (y >= map[x].size()) {
		return -1;
	}
	sum += map[x][y];

	x += 1;
	if (x >= map.size()) {
		return -1;
	}
	for (int y = y_start; y < y_start + 3; y++) {
		if (y >= map[x].size()) {
			return -1;
		}

		sum += map[x][y];
	}

	return sum;
}

int hatFourth(const vector<vector<int> > &map, int x_start, int y_start) {
	int sum = 0;
	int x = x_start;
	int y = y_start;

	for (int x = x_start; x < x_start + 3; x++) {
		if (x >= map.size()) {
			return -1;
		}

		sum += map[x][y];
	}

	x += 1;
	y += 1;
	if ((x >= map.size()) || (y >= map[x].size())) {
		return -1;
	}

	sum += map[x][y];

	return sum;
}

int solution(const vector<vector<int> > &map) {
	int max_sum = 0;
	for (int x = 0; x < map.size(); x++) {
		for (int y = 0; y < map[x].size(); y++) {
			max_sum = max(max_sum, lineFirst(map, x, y));
			max_sum = max(max_sum, lineSecond(map, x, y));
			max_sum = max(max_sum, square(map, x, y));
			max_sum = max(max_sum, neeunFirst(map, x, y));
			max_sum = max(max_sum, neeunSecond(map, x, y));
			max_sum = max(max_sum, neeunThird(map, x, y));
			max_sum = max(max_sum, neeunFourth(map, x, y));
			max_sum = max(max_sum, neeunFifth(map, x, y));
			max_sum = max(max_sum, neeunSixth(map, x, y));
			max_sum = max(max_sum, neeunSeventh(map, x, y));
			max_sum = max(max_sum, neeunEighth(map, x, y));
			max_sum = max(max_sum, thunderFirst(map, x, y));
			max_sum = max(max_sum, thunderSecond(map, x, y));
			max_sum = max(max_sum, thunderThird(map, x, y));
			max_sum = max(max_sum, thunderFourth(map, x, y));
			max_sum = max(max_sum, hatFirst(map, x, y));
			max_sum = max(max_sum, hatSecond(map, x, y));
			max_sum = max(max_sum, hatThird(map, x, y));
			max_sum = max(max_sum, hatFourth(map, x, y));
		}
	}

	return max_sum;
}

int main() {
	IOS_SETTING

	int N, M;
	cin >> N >> M;
	vector<vector<int> > map(N, vector<int> (M));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> map[n][m];
		}
	}

	cout << solution(map) << "\n";

	return 0;
}