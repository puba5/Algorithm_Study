#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

int check(int n, int k) {
	int ret = 0;
	while (n % k == 0) {
		ret += 1;
		n /= k;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	int two = 0, five = 0;
	for (int i = N; i > 0; i--) {
		two += check(i, 2);
		five += check(i, 5);
	}

	int ten = min(two, five);

	cout << ten << "\n";

	return 0;
}