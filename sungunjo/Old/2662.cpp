#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int **p = new int*[M];
	int **dp = new int*[M];
	int ***log = new int**[M];
	for (int m = 0; m < M; m++) {
		p[m] = new int[N+1];
		dp[m] = new int[N+1];
		log[m] = new int*[N+1];
		p[m][0] = 0;
		dp[m][0] = 0;
		for (int n = 0; n <= N; n++) {
			log[m][n] = new int[M];
			for (int l = 0; l < M; l++) {
				log[m][n][l] = 0;
			}
		}
	}
	for (int n = 1; n <= N; n++) {
		int k;
		cin >> k;
		for (int m = 0; m < M; m++) {
			cin >> p[m][k];
		}
	}

	for (int m = 0; m < M; m++) {
		for (int n = 1; n <= N; n++) {
			int max = 0;
			int maxM = 0;
			int maxN = 0;
			for (int k = 0; k <= n; k++) {
				if (m == 0) {
					max = p[m][n];
					maxN = 0;
					break;
				} else {
					if (max < dp[m-1][k] + p[m][n-k]) {
						max = dp[m-1][k] + p[m][n-k];
						maxM = m-1;
						maxN = k;
					}
				}
			}
			dp[m][n] = max;
			for (int l = 0; l < m; l++) {
				log[m][n][l] = log[maxM][maxN][l];
			} 
			log[m][n][m] = n - maxN;
		}
	}
	cout << dp[M-1][N] << endl;
	for (int l = 0; l < M; l++) {
		cout << log[M-1][N][l] << " ";
	}
	cout << endl;
	return 0;
}
