#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

bool isPossibleToConstruct(const vector<int> &road, vector<bool> &slide, int k, int L) {
	int dif = road[k] - road[k - 1];
	if (abs(dif) != 1) {
		return false;
	}

	if (dif > 0) {
		int end = k - L;
		if ((end < 0) || (slide[k - 1] == true)) {
			return false;
		} else {
			slide[k - 1] = true;
		}
		for (int i = k - 2; i >= end; i--) {
			if ((slide[i] == true) || (road[i] != road[k - 1])) {
				return false;
			} else {
				slide[i] = true;
			}
		}
	} else {
		int end = k + L - 1;
		if ((end >= road.size()) || (slide[k] == true)) {
			return false;
		} else {
			slide[k] = true;
		}
		for (int i = k + 1; i <= end; i++) {
			if ((slide[i] == true) || (road[i] != road[k])) {
				return false;
			} else {
				slide[i] = true;
			}
		}
	}

	return true;
}

int solution(const vector<vector<int> > &map, int N, int L) {
	int cnt = N;
	for (int x = 0; x < N; x++) {
		vector<bool> slide(N, false);
		for (int y = 1; y < N; y++) {
			if (map[x][y] != map[x][y - 1]) {
				if (isPossibleToConstruct(map[x], slide, y, L) == true) {
					if (map[x][y] < map[x][y - 1]) {
						y += (L - 1);
					}
					continue;
				} else {
					cnt -= 1;
					break;
				}
			}
		}
	}

	return cnt;
}

int main() {
	int N, L;
	scanf("%d %d", &N, &L);

	vector<vector<int> > map(N, vector<int> (N));
	vector<vector<int> > map_rot(N, vector<int> (N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &(map[i][j]));
			map_rot[j][i] = map[i][j];
		}
	}
	
	printf("%d\n", solution(map, N, L) + solution(map_rot, N, L));

	return 0;
}