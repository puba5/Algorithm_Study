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

#define RIPPED 1
#define UNDERCOOKED 0
#define EMPTY -1

#define D_LEN 6

#define X 0
#define Y 1
#define Z 2
#define T 3

int g_dx[D_LEN] = {-1, 0, 1, 0, 0, 0};
int g_dy[D_LEN] = {0, 1, 0, -1, 0, 0};
int g_dz[D_LEN] = {0, 0, 0, 0, -1, 1};

int main() {
	int M, N, H;
	scanf("%d %d %d", &M, &N, &H);

	vector<vector<vector<int> > > box(H, vector<vector<int> > (N, vector<int> (M)));
	queue<tuple<int, int, int, int> > q;
	int remain = 0;

	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				scanf("%d", &(box[h][n][m]));	

				if (box[h][n][m] == RIPPED) {
					q.push(make_tuple(h, n, m, 0));
				} else if (box[h][n][m] == UNDERCOOKED) {
					remain += 1;
				}
			}
		}
	}
	int ans = 0;

	while (!q.empty()) {
		tuple<int, int, int, int> c = q.front(); q.pop();
		if (ans != get<T>(c)) {
			ans = get<T>(c);
		}

		for (int d = 0; d < D_LEN; d++) {
			tuple<int, int, int, int> n = make_tuple(get<X>(c) + g_dx[d],
													get<Y>(c) + g_dy[d],
													get<Z>(c) + g_dz[d],
													get<T>(c) + 1);
			
			if ((get<X>(n) < 0) || (H <= get<X>(n)) ||
				(get<Y>(n) < 0) || (N <= get<Y>(n)) ||
				(get<Z>(n) < 0) || (M <= get<Z>(n)) ||
				(box[get<X>(n)][get<Y>(n)][get<Z>(n)] != UNDERCOOKED)) {
				continue;
			}

			box[get<X>(n)][get<Y>(n)][get<Z>(n)] = RIPPED;
			q.push(n);
			remain -= 1;
		}
	}

	if (remain > 0) {
		ans = -1;
	}

	printf("%d\n", ans);

	return 0;
}