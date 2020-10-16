#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int *c = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	
	int *dp = new int[n];
	dp[0] = c[0];
	dp[1] = dp[0] + c[1];
	
	for (int i = 2; i < n; i++) {
		int max = dp[i-2];
		if (i >= 3) {
			if (dp[i-3] + c[i-1] > max) {
				max = dp[i-3] + c[i-1];
			}
		} else {
			if (c[i-1] > max) {
				max = c[i-1];
			}
		}
		if (i >= 4) {
			if (dp[i-4] + c[i-1] > max) {
				max = dp[i-4] + c[i-1];
			}
		}

		dp[i] = max + c[i];
	}

	if (dp[n-1] > dp[n-2]) {
		cout << dp[n-1] << endl;
	} else {
		cout << dp[n-2] << endl;
	}

	return 0;
}
