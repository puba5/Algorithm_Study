#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	string a, b, c;

	cin >> a >> b >> c;
	a = "0" + a;
	b = "0" + b;
	c = "0" + c;

	int dp[101][101][101];

	for (int i = 1; i < a.length(); i++) {
		for (int j = 1; j < b.length(); j++) {
			for (int k = 1; k < c.length(); k++) {
				if (a[i] == b[j] && b[j] == c[k]) {
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				} else {
					int temp = max(dp[i-1][j][k], dp[i][j-1][k]);
					dp[i][j][k] = max(temp, dp[i][j][k-1]);
				}
			}
		}
	}
	
	cout << dp[a.length()-1][b.length()-1][c.length()-1] << endl;

	return 0;
}
