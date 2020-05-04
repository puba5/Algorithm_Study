#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		unordered_map<string, int> m;
		for (int i = 0; i < n; i++) {
			string cloth, category;
			cin >> cloth >> category;
			if (m.find(category) == m.end()) {
				m.insert(make_pair(category, 1));
			} else {
				m[category] += 1;
			}
		}

		int ans = 1;
		unordered_map<string, int>::iterator iter = m.begin();
		for (iter; iter != m.end(); iter++) {
			ans *= ((*iter).second + 1);
		}
		ans -= 1;

		cout << ans << "\n";

	}
	return 0;
}