#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_N 100000

int main() {
	int N;
	scanf("%d", &N);

	int num[MAX_N];
	int dp[MAX_N];

	for (int i = 0; i < N; i++) {
		scanf("%d", &(num[i]));
	}

	dp[0] = num[0];
	int ans = dp[0];
	for (int i = 1; i < N; i++) {
		dp[i] = max(0, dp[i - 1]) + num[i];
		ans = max(ans, dp[i]);
	}

	printf("%d\n", ans);

	return 0;
}