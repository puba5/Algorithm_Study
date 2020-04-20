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

int dp[301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	dp[1] = v[1];
	if (n >= 2)
		dp[2] = max(v[1] + v[2], v[2]);
	if(n>=3)
		dp[3] = max(v[1] + v[3], v[2] + v[3]);
	
	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
	}
	
	cout << dp[n];
	return 0;
}