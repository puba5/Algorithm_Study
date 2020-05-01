#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b; b = tmp;
}

int gcd(int a, int b) {
	if (b > a) {
		swap(a, b);
	}

	while (b > 0) {
		int r = a % b;
		a = b; b = r;
	}

	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int *num = new int[N];

	for (int n = 0; n < N; n++) {
		cin >> num[n];
	}

	for (int n = 1; n < N; n++) {
		num[n - 1] = abs(num[n] - num[n - 1]);
	}

	int gcd_acc = num[0];
	for (int n = 1; n < (N - 1); n++) {
		gcd_acc = gcd(gcd_acc, num[n]);
	}

	int limit = ceil(sqrt(gcd_acc));
	stack<int> s;
	s.push(gcd_acc);
	for (int i = 2; i <= limit; i++) {
		if (gcd_acc % i == 0) {
			cout << i << "\n";
			int k = gcd_acc / i;
			if (k > limit) {
				s.push(k);
			}
		}
	}
	while (!s.empty()) {
		cout << s.top() << "\n";
		s.pop();
	}

	return 0;
}