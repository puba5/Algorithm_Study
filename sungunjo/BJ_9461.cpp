#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_N 100

int main() {
	int T;
	scanf("%d", &T);
	long long dp[MAX_N + 1];

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i <= MAX_N; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);

		printf("%lld\n", dp[N]);
	}

	return 0;
}