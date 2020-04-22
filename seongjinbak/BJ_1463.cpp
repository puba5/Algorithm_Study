#include<iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <array>
#include <set>
#define ll long long

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;

	// 1 2 3 4 5 6 7 8

	vector<int> dp(n + 1);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		if (i % 3 == 0) {
			int t = dp[i / 3] + 1;
			if (i % 2 == 0) {
				t = min(t, dp[i / 2] + 1);
			}
			t = min(t, dp[i - 1] + 1);
			dp[i] = t;
		}
		else if (i % 2 == 0) {
			//dp[i] = dp[i / 2] + 1;
			int t = dp[i / 2] + 1;
			if (i % 3 == 0) {
				t = min(t, dp[i / 3] + 1);
			}
			t = min(t, dp[i - 1] + 1);
			dp[i] = t;
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
		//cout << "dp " << i << ' ' << dp[i] << '\n';
	}
	cout << dp[n] << '\n';

}

