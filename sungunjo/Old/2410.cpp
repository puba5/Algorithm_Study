#include <iostream>
using namespace std;

#define MAX 1000000000
int dp[MAX];

int main() {
	int N;
	cin >> N;

	dp[0] = 1;
	
	for (int k = 0; (1 << k) <= N; k++) {
		for (int i = 1; i <= N; i++) {
			if (i >= (1 << k)) {
				dp[i] = (dp[i] + dp[i-(1<<k)]) % MAX;
			}
		}
	}

	cout << dp[N] << endl;

	return 0;
}
