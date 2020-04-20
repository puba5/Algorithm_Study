#include<iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define ll long long

using namespace std;	


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	else if (n == 2) {
		cout << 1 << endl;
		return 0;
	}

	vector<ll> dp(93);
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[n];



	return 0;
}