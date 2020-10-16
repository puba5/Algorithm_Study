#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v(N);
	for (int n = 0; n < N; n++) {
		cin >> v[n];
	}
	sort(v.begin(), v.end());

	int ans = 0;
 	for (int i = 0; i < N; i++ ) {
		for (int j = i + 1; j < N; j++) {
			int ij = v[i] + v[j];
			for (int k = j + 1; k < N; k++) {
				int ijk = ij + v[k];
				if (ijk == M) {
					ans = ijk;
					break;
				} else if (ijk < M) {
					ans = max(ans, ijk);
				} else {
					break;
				}
			}
		}
	}

	cout << ans << "\n";
}
