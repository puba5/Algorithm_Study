#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int comp(pair<int, int> a, pair<int, int> b) {
	if ((a.first < b.first) && (a.second < b.second)) {
		return -1;
	} else if ((a.first > b.first) && (a.second > b.second)) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int N;
	scanf("%d", &N);
	vector<pair<int, int> > v(N);
	vector<int> rank(N, 1);
	for (int n = 0; n < N; n++) {
		scanf("%d %d", &v[n].first, &v[n].second);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (comp(v[i], v[j]) < 0) {
				rank[i]++;
			} else if (comp(v[i], v[j]) > 0) {
				rank[j]++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", rank[i]);
	}
	printf("\n");
	return 0;
}
