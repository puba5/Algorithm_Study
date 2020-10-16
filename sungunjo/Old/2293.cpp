#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int *costs = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> costs[i];
	}

	int *total = new int[k+1];
	total[0] = 1;
	for (int i = 1; i <= k; i++) {
		total[i] = 0;
	}

	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= k; i++) {
			if (i >= costs[j]) {
				total[i] += total[i-costs[j]];
			}
		}
	}
	cout << total[k] << endl;
	return 0;
}
