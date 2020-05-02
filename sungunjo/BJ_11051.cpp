#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define ANS_LIMIT 10007

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	
	int **pascal = new int*[N + 1];
	for (int i = 0; i <= N; i++) {
		pascal[i] = new int[N + 1];
	}

	pascal[0][0] = 0;
	pascal[1][0] = 1; pascal[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		pascal[i][0] = 1; pascal[i][i] = 1;
		for (int j = 1; j < i; j++) {
			pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % ANS_LIMIT;
		}
	}

	cout << pascal[N][K] << "\n";

	return 0;
}