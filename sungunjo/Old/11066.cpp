#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T, K;
	int c[501];
	int dp[501][501];

	cin >> T;
	
	for (int t = 0; t < T; t++) {
		cin >> K;

		for (int k = 0; k < K; k++) {
			cin >> c[k];
		}
	
		for (int i = 0; i < K-1; i++) {
			for (int j = i+1; j < K; j++) {
				dp[i][j] = 88888;
				for (int k = i; k <= j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
				}
			}
		}
	}
	

	return 0;
}
