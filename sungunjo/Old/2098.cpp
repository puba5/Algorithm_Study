#include <iostream>
#include <cmath>
using namespace std;

int N;
int W[16][16];
int dp[16][65535];
unsigned short e;

int tsp(int n, unsigned short v) {
	if (dp[n][v] == 0) {
		int temp = 0;
		if (v == e) {
			temp = W[n][0];

		} else {
			for (int i = 1; i < N; i++) {
				if (!(v & (1 << i))) {
					if ((temp == 0) || temp > tsp(i, v|(1<<i)) + W[n][i]) {
						temp = tsp(i, v|(1<<i)) + W[n][i];
					}
				}
			}
		}
		dp[n][v] = temp;
	}

	return dp[n][v];
}

int main() {
	cin >> N;
	e = (unsigned short)(pow(2, N) - 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
			if (W[i][j] == 0) {
				W[i][j] = 888888888;
			}
		}
	}
	cout << tsp(0, 1) << endl;

	return 0;
}
