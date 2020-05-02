#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int bino(int n, int c) {
	int numer = 1, deno = 1;

	for (int i = n; i > (n - c); i--) {
		numer *= i;
	}

	for (int i = c; i > 0; i--) {
		deno *= i;
	}

	return (numer / deno);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	cout << bino(N, K) << "\n";

	return 0;
}