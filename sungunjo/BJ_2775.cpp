#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int K, N;
		scanf("%d %d", &K, &N);

		vector<vector<int> > building(K + 1, vector<int> (N, 0));

		for (int n = 0; n < N; n++) {
			building[0][n] = n + 1;
		}

		for (int k = 1; k <= K; k++) {
			for (int n = 0; n < N; n++) {
				if (n > 0) {
					building[k][n] = building[k][n - 1];
				}
				building[k][n] += building[k - 1][n];
			}
		}

		printf("%d\n", building[K][N - 1]);


	}
}