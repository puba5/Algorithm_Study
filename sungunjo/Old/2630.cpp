#include <iostream>
#include <vector>
using namespace std;

int white, blue;

void go(vector<vector<int> > &map, int x, int y, int len) {
	int color = map[x][y];
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (map[i][j] != color) {
				int new_len = len / 2;
				go(map, x, y, new_len);
				go(map, x, y + new_len, new_len);
				go(map, x + new_len, y, new_len);
				go(map, x + new_len, y + new_len, new_len);
				return;
			}
		}
	}

	if (color == 0) {
		white++;
	} else {
		blue++;
	}
	return;
}

int main() {
	int N;
	white = 0; blue = 0;
	scanf("%d", &N);
	vector<vector<int> > v(N, vector<int> (N, -1));
	for (int i = 0 ; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	go(v, 0, 0, N);

	printf("%d\n%d\n", white, blue);

	return 0;
}
