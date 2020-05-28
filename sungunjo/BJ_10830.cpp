#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define IOS_SETTING \
ios::sync_with_stdio(false); \
cin.tie(NULL); cout.tie(NULL);

#define ANS_LIMIT 1000


vector<vector<int> > matrixMult(const vector<vector<int> > &a, const vector<vector<int> > &b) {
	int N = a.size();
	int K = a[0].size();
	int M = b[0].size();
	vector<vector<int> > result(N, vector<int> (M, 0));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			for (int k = 0; k < K; k++) {
				result[n][m] = (result[n][m] + (a[n][k] * b[k][m]))  % ANS_LIMIT;
			}
		}
	}

	return result;
}

vector<vector<int> > go(const vector<vector<int> > &mat, int N, long long B) {
	if (B  == 1) {
		return mat;
	}

	vector<vector<int> > res = go(mat, N, B / 2);
	res = matrixMult(res, res);

	if (B % 2 != 0) {
		res = matrixMult(res, mat);
	}

	return res;
}

int main() {
	IOS_SETTING

	int N;
	long long B;
	cin >> N >> B;
	vector<vector<int> > mat(N, vector<int> (N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
			mat[i][j] %= ANS_LIMIT;
		}
	}
	vector<vector<int> > res = go(mat, N, B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}