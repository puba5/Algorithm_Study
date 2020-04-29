#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_N 100
#define NUM_SIZE 10
#define MAX_DP 1000000000

int main() {
	int N;
	scanf("%d", &N);
	
	long long dp[MAX_N + 1][NUM_SIZE];

	dp[1][0] = 0;
	for (int i = 1; i < NUM_SIZE; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j < NUM_SIZE - 1; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MAX_DP;
		}
	}

	long long ans = 0;
	for (int j = 0; j < NUM_SIZE; j++) {
		ans = (ans + dp[N][j]) % MAX_DP;
	}

	printf("%lld\n", ans);

	return 0;
}