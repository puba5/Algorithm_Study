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
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	stack<int> s;
	char *ans = new char[2 * N];
	int ans_idx = 0;
	int num = 1;
	for (int n = 0; n < N; n++) {
		int input;
		cin >> input;

		if ((!s.empty()) && (s.top() > input)) {
			cout << "NO\n";
			return 0;
		}

		while ((s.empty()) || (s.top() != input)) {
			s.push(num);
			num += 1;
			ans[ans_idx] = '+';
			ans_idx += 1;
		}
		s.pop();
		ans[ans_idx] = '-';
		ans_idx += 1;
	}

	for (int i = 0; i < ans_idx; i++) {
		cout << ans[i] << "\n";
	}


	return 0;
}