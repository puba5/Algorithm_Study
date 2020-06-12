#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	int left = 1, right = K;
	int ans = 0;
	while (left <= right) {
		int cnt = 0;
		int mid = (left + right) / 2;

		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}
		if (cnt < K) {
			left = mid + 1;
		} else {
			ans = mid;
			right = mid - 1;
		}
	}

	printf("%d\n", ans); 
	return 0;
}