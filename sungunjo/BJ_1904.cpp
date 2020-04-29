#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_DP 15746

int main() {
	int N;
	scanf("%d", &N);

	vector<int> dp(N + 1);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MAX_DP;
	}

	printf("%d\n", dp[N]);

	return 0;
}