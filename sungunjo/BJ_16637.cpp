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
cin.tie(NULL); \
cout.tie(NULL);

int calc(int a, char op, int b) {
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
	}
	return 0;
}

int sum(deque<int> num, deque<char> op, const vector<bool> &calc_first) {
	/* 괄호 쳐진것부터 계산 */
	for (int i = 0; i < calc_first.size(); i++) {
		if (calc_first[i] == true) {
			int a = num.front(); num.pop_front();
			int b = num.front(); num.pop_front();
			num.push_front(calc(a, op.front(), b));
			op.pop_front();
		} else {
			num.push_back(num.front()); num.pop_front();
			op.push_back(op.front()); op.pop_front();
		}
	}
	num.push_back(num.front()); num.pop_front();
	/* 나머지 계산 */
	while (!op.empty()) {
		int a = num.front(); num.pop_front();
		int b = num.front(); num.pop_front();
		num.push_front(calc(a, op.front(), b));
		op.pop_front();
	}
	return num.front();
}

int go(const deque<int> &num, const deque<char> &op, vector<bool> &calc_first, int idx) {
	if (idx >= calc_first.size()) {
		return sum(num, op, calc_first);
	}
	calc_first[idx] = true;
	int max_sum = go(num, op, calc_first, idx + 2);
	calc_first[idx] = false;
	max_sum = max(max_sum, go(num, op, calc_first, idx + 1));
	return max_sum;
}

int main() {
	IOS_SETTING

	int N;
	cin >> N;

	int N_half = N / 2;
	deque<int> num(N_half + 1);
	deque<char> op(N_half);
	vector<bool> calc_first(N_half, false);

	for (int i = 0; i < N_half; i++) {
		cin >> num[i] >> op[i];
	}
	cin >> num[N_half];

	cout << go(num, op, calc_first, 0);

	return 0;
}