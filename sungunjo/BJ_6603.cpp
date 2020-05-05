#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define ANS_SIZE 6

void print(int *ans) {
	for (int i = 0; i < ANS_SIZE; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

void go(int *S, int S_idx, int S_size, int *ans, int ans_idx) {
	if (ans_idx == ANS_SIZE) {
		print(ans);
	} else if ((S_size - S_idx) < (ANS_SIZE - ans_idx)) {
		return;
	}

	for (int i = S_idx; i < S_size; i++) {
		ans[ans_idx] = S[i];
		go(S, i + 1, S_size, ans, ans_idx + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int K;
	while (true) {
		cin >> K;
		if (K == 0) {
			break;
		}

		int *S = new int[K];
		for (int k = 0; k < K; k++) {
			cin >> S[k];
		}
		int ans[ANS_SIZE];
		go(S, 0, K, ans, 0);
		cout << "\n";
	}

	return 0;
}