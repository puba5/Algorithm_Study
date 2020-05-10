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

#define CHECK_AND_BREAK(cond) \
if (cond) { \
break; \
}

#define MAX_ANS 88888888

typedef enum _sect {
	SECT_FIRST = 0,
	SECT_SECOND,
	SECT_THIRD,
	SECT_FOURTH,
	SECT_FIFTH,
	
	SECT_SIZE
} Sect;

void init_map(int ***map, int map_size) {
	(*map) = new int*[map_size];
	for (int x = 0; x < map_size; x++) {
		(*map)[x] = new int[map_size];
		memset((*map)[x], 0, map_size * sizeof(int));
	}
}


int calcFirstSect(const int **map, int N, int x, int y, int d1, int d2) {
	int sum = 0;

	int r_start = 0;
	int r_end = x;
	int c_start = 0;
	int c_end = y + 1;
	for (int r = r_start; r < r_end; r++) {
		for (int c = 0; c < c_end; c++) {
			sum += map[r][c];
		}
	}
	r_start = x;
	r_end = x + d1;
	c_start = 0;
	c_end = y;
	for (int r = r_start; r < r_end; r++) {
		for (int c = c_start; c < c_end; c++) {
			sum += map[r][c];
		}
		c_end -= 1;
	}

	return sum;
}

int calcSecondSect(const int **map, int N, int x, int y, int d1, int d2) {
	int sum = 0;	
	
	int r_start = 0;
	int r_end = x;
	int c_start = y + 1;
	int c_end = N;
	for (int r = r_start; r < r_end; r++) {
		for (int c = c_start; c < c_end; c++) {
			sum += map[r][c];
		}
	}
	r_start = x;
	r_end = x + d2 + 1;
	c_start = y + 1;
	c_end = N;
	for (int r = r_start; r < r_end; r++) {
		for (int c = c_start; c < c_end; c++) {
			sum += map[r][c];
		}
		c_start += 1;
	}

	return sum;
}

int calcThirdSect(const int **map, int N, int x, int y, int d1, int d2) {
	int sum = 0;	

	int r_start = x + d1;
	int r_end = x + (d1 + d2) + 1;
	int c_start = 0;
	int c_end = y - d1;
	for (int r = r_start; r < r_end; r++) {
		for (int c = c_start; c < c_end; c++) {
			sum += map[r][c];
		}
		c_end += 1;
	}

	r_start = x + (d1 + d2) + 1;
	r_end = N;
	c_start = 0;
	c_end = y - d1 + d2;
	for (int r = r_start; r < r_end; r++) {
		for (int c = c_start; c < c_end; c++) {
			sum += map[r][c];
		}
	}

	return sum;
}

int calcFourthSect(const int **map, int N, int x, int y, int d1, int d2) {
	int sum = 0;	

	int r_start = x + d2 + 1;
	int r_end = x + (d1 + d2) + 1;
	int c_start = y + d2;
	int c_end = N;
	for (int r = r_start; r < r_end; r++) {
		for (int c = c_start; c < c_end; c++) {
			sum += map[r][c];
		}
		c_start -= 1;
	}
	r_start = x + (d1 + d2) + 1;
	r_end = N;
	c_start = y - d1 + d2;
	c_end = N;
	for (int r = r_start; r < r_end; r++) {
		for (int c = c_start; c < c_end; c++) {
			sum += map[r][c];
		}
	}

	return sum;
}

void calcSectSum(const int **map, int N, int x, int y, int d1, int d2, int total, vector<int> &result) {
	int without_fifth = 0;

	result[SECT_FIRST] = calcFirstSect(map, N, x, y, d1, d2);
	without_fifth += result[SECT_FIRST];

	result[SECT_SECOND] = calcSecondSect(map, N, x, y, d1, d2);
	without_fifth += result[SECT_SECOND];

	result[SECT_THIRD] = calcThirdSect(map, N, x, y, d1, d2);
	without_fifth += result[SECT_THIRD];

	result[SECT_FOURTH] = calcFourthSect(map, N, x, y, d1, d2);
	without_fifth += result[SECT_FOURTH];

	result[SECT_FIFTH] = total - without_fifth;
}

int solution(const int **map, int N, int total) {
	vector<int> result(SECT_SIZE);

	int ans = MAX_ANS;
	for (int x = 0; x < N - 1; x++) {
		for (int y = 0; y < N - 1; y++) {
			for (int d1 = 1; d1 < N; d1++) {
				for (int d2 = 1; d2 < N; d2++) {
					CHECK_AND_BREAK((x + d1 + d2 >= N) ||
									(y + d2 >= N) ||
									(y - d1 < 0))
						
					calcSectSum(map, N, x, y, d1, d2, total, result);
					sort(result.begin(), result.end());
					ans = min(ans, result[result.size() - 1] - result[0]);
				}
			}
		}
	}

	return ans;
}

int main() {
	IOS_SETTING

	int N;
	cin >> N;
	int **map;
	init_map(&map, N);

	int total = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> map[x][y];
			total += map[x][y];
		}
	}

	cout << solution((const int **) map, N, total) << "\n";

	return 0;
}