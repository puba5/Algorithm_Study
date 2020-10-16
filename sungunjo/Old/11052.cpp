#include <iostream>
using namespace std;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int P[1001];
int dp[1001][1001];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	for (int k = 0; k <= N; k++) {
		dp[1][k] = k*P[1];
	}

	for (int i = 2; i <= N; i++) {
		for (int k = 0; k <= N; k++) {
			dp[i][k] = dp[i-1][k];
			for (int j = 1; j <= k; j++) {
				if (k-(i*j) >= 0) {
					dp[i][k] = MAX(dp[i][k], dp[i-1][k-(i*j)]+j*P[i]);
				}
			}
		}
	}

	cout << dp[N][N] << endl;

	return 0;
}
