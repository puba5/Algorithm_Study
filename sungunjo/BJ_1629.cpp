#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

long long go(long long a, long long b, long long c) {
	if (b == 0) {
		return 1;
	}

	long long res = go(a, b / 2, c);
	res = (res * res) % c;

	if (b % 2 != 0) {
		res = (res * a) % c;
	}

	return res;
}

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n", (int) go(A, B, C));

	return 0;
}