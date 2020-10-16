#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int *costs = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> costs[i];
	}

	int *dp = new int[k+1];
	dp[0] = 0;
	for (int i = 1; i <= k; i++) {
		dp[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if ((j >= costs[i]) && (dp[j-costs[i]] >= 0)) {
				if ((dp[j] == -1) || (dp[j] > dp[j-costs[i]] + 1)) {
					dp[j] = dp[j-costs[i]] + 1;
				}
				
			}
		}
	}

	cout << dp[k] << endl;

	return 0;
}
