#include <iostream>
#include <cstring>
using namespace std;

int main() {
	string a, b;
	int aSize, bSize;

	cin >> a >> b;
	
	a = "0" + a;
	b = "0" + b;

	aSize = a.length();
	bSize = b.length();

	int **dp = new int*[aSize];
	for (int i = 0 ; i < aSize; i++) {
		dp[i] = new int[bSize];
		for (int j = 0; j < bSize; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i < aSize; i++) {
		for (int j = 1; j < bSize; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
			}
		}
	}

	cout << dp[aSize-1][bSize-1] << endl;


	return 0;
}
