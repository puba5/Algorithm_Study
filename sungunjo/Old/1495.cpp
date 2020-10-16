#include <iostream>
using namespace std;

int main() {
	int N, S, M;
	cin >> N >> S >> M;

	int *v = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	bool *dp = new bool[M+1];
	bool *cache = new bool[M+1];

	for (int i = 0; i <= M; i++) {
		if (i == S) {
			dp[i] = true;
		} else {
			dp[i] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			if ((j - v[i] >= 0 && dp[j-v[i]] == true) || (j + v[i] <= M && dp[j+v[i]] == true)) {
				cache[j] = true;
			} else {
				cache[j] = false;
			}
		}
		for (int j = 0; j <= M; j++) {
			dp[j] = cache[j];
		}
	}

	for (int i = M; i >=0; i--) {
		if (dp[i] == true) {
			cout << i << endl;
			break;
		} else if (i == 0) {
			cout << "-1" << endl;
		}
	}
		

	return 0;
}
