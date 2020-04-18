#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int x, y;
		scanf("%d %d", &x, &y);

		int dist = y - x;
		int min_N = ceil(sqrt(dist)) - 1;
		int cnt = min_N * 2;

		if (dist - (min_N * (min_N + 1)) > 0) {
			cnt += 1;
		}

		printf("%d\n", cnt);
	}

	return 0;
}