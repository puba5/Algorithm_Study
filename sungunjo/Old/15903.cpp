#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, temp;
	long long ans = 0;
	vector<int> a;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		sort(a.begin(), a.end());
		temp = a[0] + a[1];
		a[0] = a[1] = temp;
	}

	for (int i = 0; i < n; i++) {
		ans += a[i];
	}

	cout << ans << endl;
}
