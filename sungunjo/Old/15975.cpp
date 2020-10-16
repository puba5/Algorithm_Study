#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> point[100001];

int main() {
	long long count = 0;
	cin >> N;


	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		point[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		sort(point[i].begin(), point[i].end());

		for (int j = 0; j < point[i].size(); j++) {
			long long temp = 8888888888;
			if (point[i].size() == 1) {
				temp = 0;
			} else {
				if (0 < j) {
					temp = min(temp, (long long)abs(point[i][j-1]-point[i][j]));
				}
				if (j < point[i].size() - 1) {
					temp = min(temp, (long long)abs(point[i][j+1]-point[i][j]));
				}
			}

			count += temp;
		}
	}

	cout << count << endl;

	return 0;
}
