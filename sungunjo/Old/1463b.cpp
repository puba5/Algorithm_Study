#include <iostream>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main() {
	int N;
	cin >> N;

	int *dp = new int[N+1];
	dp[N] = 0;

	for (int i = N-1; i > 0; i--) {
		int min = dp[i+1];
		
		if (i * 3 <= N) {
			min = MIN(min, dp[i*3]);
		}
		if (i * 2 <= N) {
			min = MIN(min, dp[i*2]);
		}

		dp[i] = min + 1;
	}

	cout << dp[1] << endl;

	return 0;
}
