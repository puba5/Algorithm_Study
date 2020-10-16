#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	long long dp[90][2];
	dp[0][0] = 0;
	dp[0][1] = 1;

	for (int i = 1; i < N; i++) {
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}

	cout << dp[N-1][0] + dp[N-1][1] << endl;
	
	
	return 0;
}
