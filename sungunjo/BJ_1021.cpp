#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

int moveLeftToFind(deque<int> &dq, int target_num) {
	int cnt = 0;
	while (dq.front() != target_num) {
		dq.push_back(dq.front());
		dq.pop_front();
		cnt += 1;
	}
	dq.pop_front();
	return cnt;
}

int moveRightToFind(deque<int> &dq, int target_num) {
	int cnt = 0;
	while (dq.front() != target_num) {
		dq.push_front(dq.back());
		dq.pop_back();
		cnt += 1;
	}
	dq.pop_front();
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;

	cin >> N >> M;

	deque<int> dq(N);
	for (int n = 0; n < N; n++) {
		dq[n] = n + 1;
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		int target_num;
		cin >> target_num;
		deque<int> tmp_dq_left(dq);
		deque<int> tmp_dq_right(dq);
		int cnt_left = moveLeftToFind(tmp_dq_left, target_num);
		int cnt_right = moveRightToFind(tmp_dq_right, target_num);
		
		if (cnt_left < cnt_right) {
			ans += cnt_left;
			dq.swap(tmp_dq_left);
		} else {
			ans += cnt_right;
			dq.swap(tmp_dq_right);
		}
	}

	cout << ans << "\n";

	return 0;
}