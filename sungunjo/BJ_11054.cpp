#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define CHECK_AND_CONTINUE(cond) if (cond) { continue; }

#define MAX_N 1000

typedef enum _way {
	UP = 0,
	DOWN,
	WAY_SIZE
} Way;

int main() {
	int N;
	int A[MAX_N];
	int dp[MAX_N][WAY_SIZE];

	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < WAY_SIZE; j++) {
			dp[i][j] = 0;
		}
	}

	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		scanf("%d", &(A[n]));
	}
	dp[0][UP] = 1;
	for (int i = 1; i < N; i++) {
		int up_max = 0;
		for (int j = 0; j < i; j++) {
			CHECK_AND_CONTINUE(A[i] <= A[j])
			if (up_max < dp[j][UP]) {
				up_max = dp[j][UP];
			}
		}

		dp[i][UP] = up_max + 1;
	}

	dp[N - 1][DOWN] = 1;
	for (int i = N - 2; i >= 0; i--) {
		int down_max = 0;
		for (int j = N - 1; j > i; j--) {
			CHECK_AND_CONTINUE(A[i] <= A[j])
			if (down_max < dp[j][DOWN]) {
				down_max = dp[j][DOWN];
			}
		}
		
		dp[i][DOWN] = down_max + 1;
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int tmp = dp[i][UP] + dp[i][DOWN] - 1;
		if (tmp > ans) {
			ans = tmp;
		}
	}

	printf("%d\n", ans);

	return 0;
}