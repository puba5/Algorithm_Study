#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 88888888

int N, M, X;
int road[1005][1005];
int ans = 0;

int main() {
	cin >> N >> M >> X;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j  <= N; j++) {
			if (i == j) {
				road[i][j] = 0;
			} else {
				road[i][j] = INF;
			}
		}
	}

	for (int m = 0; m < M; m++) {
		int start, end, t;
		cin >> start >> end >> t;
		road[start][end] = t;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		ans = max(ans, road[i][X] + road[X][i]);
	}

	cout << ans << endl;
	return 0;
}
