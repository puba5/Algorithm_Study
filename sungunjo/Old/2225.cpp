#include <iostream>
using namespace std;

#define LIMIT 1000000000

int dp[201][201];

int main() {
	int N, K;
	cin >> N >> K;
	dp[0][0] = 1;
	
	for (int k = 1; k <= K; k++) {
		for (int n = 0; n <= N; n++) {
			for (int i = 0; i <= n; i++) {
				dp[k][n] = (dp[k][n] + dp[k-1][n-i]) % LIMIT ;
			}
		}
	}

	cout << dp[K][N] << endl;

	return 0;
}
