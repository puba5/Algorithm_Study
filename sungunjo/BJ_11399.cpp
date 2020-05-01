#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> P(N);

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	sort(P.begin(), P.end());

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += (P[i] * (N - i));
	}

	cout << ans << "\n";
	return 0;
}