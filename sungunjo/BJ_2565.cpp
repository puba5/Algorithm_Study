#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_N 100
#define MAX_POLE 500

#define CHECK_AND_CONTINUE(cond) if (cond) { continue; }

int main() {
	int N;
	scanf("%d", &N);

	int input[MAX_POLE + 1];
	memset(input, -1, (MAX_POLE + 1) * sizeof(int));
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		input[a] = b;
	}

	int pole[MAX_N];
	int dp[MAX_N];

	int idx = 0;
	for (int i = 1; i <= MAX_POLE; i++) {
		CHECK_AND_CONTINUE(input[i] == -1)

		pole[idx] = input[i];
		idx += 1;
	}
	int lis = 1;
	dp[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		int max_dp = 0;
		for (int j = 0; j < i; j++) {
			CHECK_AND_CONTINUE(pole[j] >= pole[i])

			max_dp = max(max_dp, dp[j]);
		}
		dp[i] = max_dp + 1;
		lis = max(lis, dp[i]);
	}

	printf("%d\n", (N - lis));

	return 0;
}