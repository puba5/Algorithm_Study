#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, M, K;
	vector<int> arr;
	cin >> N >> M >> K;

	if (M == 1) {
		if (K != N) {
			cout << -1 << endl;
		} else {
			for (int i = N; i > 0; i--) {
				cout << i << " ";
			}
		}
		return 0;
	}
	if (K == 1) {
		if (M != N) {
			cout << -1 << endl;
		} else {
			for (int i = 1; i <= N; i++) {
				cout << i << " ";
			}
		}
		return 0;
	}

	for (int i = K; i > 0; i--) {
		arr.push_back(i);
	}

	int group_size = (N-K) / (M-1);
	int remain_size = (N-K) % (M-1);

	if ((group_size > K) || (remain_size > 0 && group_size + 1 > K) || (group_size == 0)) {
		cout << -1 << endl;
		return 0;
	}

	int pos = K;
	for (int m = 0; m < M-1; m++) {
		int d = group_size;
		if (remain_size > 0) {
			d++;
			remain_size--;
		}
		for (int i = pos + d; i > pos; i--) {
			arr.push_back(i);
		}
		pos += d;
	}

	int len = arr.size();
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
}
