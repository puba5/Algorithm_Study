#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	for (int t = 0; t < 10; t++) {
		int N;
		cin >> N;

		vector<int> apt(N);
		for (int n = 0; n < N; n++) {
			cin >> apt[n];
		}

		int sum = 0;
		for (int i = 2; i < N - 2; i++) {
				int max_h = max(apt[i-2], apt[i-1]);
				max_h = max(max_h, apt[i+1]);
				max_h = max(max_h, apt[i+2]);
		
				int view = apt[i] - max_h;
				if (view > 0) {
					sum += view;
				}
		}

		cout << "#" << t << " " << sum << endl;
	}

	return 0;
}
