#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

#define MAX_N 100
#define MAX_K 100000

typedef struct _obj_info {
	int w;
	int v;
} ObjInfo;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	ObjInfo *obj = new ObjInfo[N];
	int **dp = new int*[N];
	for (int i = 0; i < N; i++) {
		dp[i] = new int[K + 1];
	}

	for (int i = 0; i < N; i++) {
		cin >> obj[i].w >> obj[i].v;
	}

	for (int i = 1; i <= K; i++) {
		if (obj[0].w <= i) {
			dp[0][i] = obj[0].v;
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = dp[i - 1][j];
			if (obj[i].w <= j) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - obj[i].w] + obj[i].v);
			}
		}
	}

	cout << dp[N - 1][K] << "\n";

	return 0;
}