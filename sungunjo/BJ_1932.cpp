#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_TRIANGLE 500

int main() {
	int n;
	scanf("%d", &n);

	int triangle[MAX_TRIANGLE][MAX_TRIANGLE];
	int dp[MAX_TRIANGLE][MAX_TRIANGLE];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &(triangle[i][j]));
		}
	}

	for (int j = 0; j <= n - 1; j++) {
		dp[n - 1][j] = triangle[n - 1][j];
	}
	
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
		}
	}

	printf("%d\n", dp[0][0]);

	return 0;
}