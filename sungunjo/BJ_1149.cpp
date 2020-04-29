#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_HOUSE 1000

typedef enum _color {
	RED = 0,
	GREEN,
	BLUE,
	COLOR_SIZE
} Color;

int main() {
	int N;
	scanf("%d", &N);

	int dp[MAX_HOUSE][COLOR_SIZE];
	int house[MAX_HOUSE][COLOR_SIZE];

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &(house[i][RED]), &(house[i][GREEN]), &(house[i][BLUE]));
	}

	dp[0][RED] = house[0][RED];
	dp[0][GREEN] = house[0][GREEN];
	dp[0][BLUE] = house[0][BLUE];

	for (int i = 1; i < N; i++) {
		dp[i][RED] = min(dp[i - 1][GREEN], dp[i - 1][BLUE]) + house[i][RED];
		dp[i][GREEN] = min(dp[i - 1][RED], dp[i - 1][BLUE]) + house[i][GREEN];
		dp[i][BLUE] = min(dp[i - 1][RED], dp[i - 1][GREEN]) + house[i][BLUE];
	}

	printf("%d\n", min(dp[N - 1][RED], min(dp[N - 1][GREEN], dp[N - 1][BLUE])));

	return 0;
}