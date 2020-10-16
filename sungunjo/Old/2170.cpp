#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<pair<int, int> > v(N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	sort(v.begin(), v.end());

	int len = 0;
	int start = v[0].first, end = v[0].second;

	for (int i = 1; i < N; i++) {
		if (end < v[i].first) {
			len += (end - start);
			start = v[i].first;
			end = v[i].second;
		} else {
			end = max(end, v[i].second);
		}
	}

	len += (end - start);

	printf("%d\n", len);

	return 0;
}
