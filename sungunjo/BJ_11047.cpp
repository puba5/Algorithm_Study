#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int *coin = new int[N];

	for (int i = N - 1; i >= 0; i--) {
		cin >> coin[i];
	}

	int ans = 0;
	for (int i = 0; ((i < N) && (K > 0)); i++) {
		if (coin[i] <= K) {
			ans += (K / coin[i]);
			K %= coin[i];
		}
	}

	cout << ans << "\n";

	return 0;
}