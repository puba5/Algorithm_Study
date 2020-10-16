#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int step[305];
	int dp[305];
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> step[n];
	}

	dp[0] = step[0];
	dp[1] = step[0] + step[1];
	dp[2] = max(step[1], dp[0]) + step[2];
	for (int i = 3; i < N; i++) {
		dp[i] = max(step[i-1] + dp[i-3], dp[i-2]) + step[i];
	}

	cout << dp[N-1] << "\n";

	return 0;
}
