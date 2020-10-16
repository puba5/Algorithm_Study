#include <iostream>
using namespace std;

#define LIMIT 100000007

int T, K, N;
int dpb[15], dpe[15];

int main() {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> K >> N;

		dpb[0] = 1; dpe[0] = 0;
		for (int i = 1; i <= N; i++) {
			dpb[(i) % (K+2)] = dpb[(i-1) % (K+2)]; dpe[(i) % (K+2)] = (dpb[(i) % (K+2)] + dpe[(i-1) % (K+2)]) % LIMIT;

			if (i - K >= 0) {
				dpb[(i) % (K+2)] = (dpb[(i-K) % (K+2)] + dpe[(i-K) % (K+2)]) % LIMIT;
			}

			dpe[(i) % (K+2)] = ((2 * dpb[(i-1) % (K+2)] % LIMIT - dpb[(i) % (K+2)] % LIMIT + LIMIT) % LIMIT + dpe[(i-1) % (K+2)]) % LIMIT;
		}

		cout << dpb[(N) % (K+2)] << endl;
	}
}
