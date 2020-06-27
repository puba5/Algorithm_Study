#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
#include <tuple>
using namespace std;

#define RIPE_TOMATO 1
#define UNDERCOOKED_TOMATO 0
#define NULL_SPACE -1

#define D_LEN 4

int g_dx[D_LEN] = {-1, 0, 1, 0};
int g_dy[D_LEN] = {0, 1, 0, -1};

int main() {
	int M, N;
	scanf("%d %d", &M, &N);

	vector<vector<int> > box(N, vector<int> (M, 0) );
	
	queue<tuple<int, int, int> > q;

	int remained = 0;

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			scanf("%d", &(box[n][m]));
			if (box[n][m] == RIPE_TOMATO) {
				q.push(make_tuple(n, m, 0));
			} else if (box[n][m] == UNDERCOOKED_TOMATO) {
				remained += 1;
			}
		}
	}

	int time = 0;

	while (!q.empty()) {
		tuple<int, int, int> c = q.front(); q.pop();
		time = get<2>(c);

		for (int di = 0; di < D_LEN; di++) {
			tuple<int, int, int> n = make_tuple(get<0>(c) + g_dx[di], get<1>(c) + g_dy[di], get<2>(c) + 1);

			if ((get<0>(n) < 0) || (N <= get<0>(n)) ||
				(get<1>(n) < 0) || (M <= get<1>(n)) ||
				(box[get<0>(n)][get<1>(n)] != UNDERCOOKED_TOMATO)) {
				continue;
			}

			box[get<0>(n)][get<1>(n)] = RIPE_TOMATO;
			remained -= 1;
			q.push(n);
		}


	}

	if (remained == 0) {
		printf("%d\n", time);
	} else {
		printf("-1\n");
	}
	

	return 0;
}