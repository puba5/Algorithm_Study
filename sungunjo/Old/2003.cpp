#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N);

	for (int n = 0; n < N; n++) {
		cin >> A[n];
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += A[j];
			if (sum == M) {
				ans++;
				break;
			} else if (sum >= M) {
				break;
			}
		}
	}

	cout << ans << endl;
}
