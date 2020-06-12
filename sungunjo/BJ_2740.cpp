#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int N, M, K;
	scanf("%d %d", &N, &M);
	vector<vector<int> > A(N, vector<int> (M));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			scanf("%d", &(A[n][m]));
		}
	}

	scanf("%d %d", &M, &K);
	vector<vector<int> > B(M, vector<int> (K));
	for (int m = 0; m < M; m++) {
		for (int k = 0; k < K; k++) {
			scanf("%d", &(B[m][k]));
		}
	}

	vector<vector<int> > AB(N, vector<int> (K, 0));

	for (int n = 0; n < N; n++) {
		for (int k = 0; k < K; k++) {
			for (int m = 0; m < M; m++) {
				AB[n][k] += (A[n][m] * B[m][k]);
			}
			cout << AB[n][k] << " ";
		}
		cout << "\n";
	}

	return 0;
}