#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define LIMIT 888888888

int N, M;
vector<pair<int, int> > h, c, c_alive;

int go(int i, bool alive) {
	int ret = 0;
	if (alive) {
		c_alive.push_back(c[i]);
	}

	if (c_alive.size() == M) {
		for (int i = 0; i < h.size(); i++) {
			int dist = LIMIT;
			for (int j = 0; j < M; j++) {
				dist = min(dist, abs(h[i].first-c_alive[j].first)+abs(h[i].second-c_alive[j].second));
			}
			ret += dist;
		}
	} else if (i == c.size() - 1) {
		ret = LIMIT;
	} else {
		ret = min(go(i+1, true), go(i+1, false));
	}
	if (alive) {
		c_alive.pop_back();
	}
	return ret;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				h.push_back(make_pair(i,j));
			} else if (temp == 2) {
				c.push_back(make_pair(i, j));
			}
		}
	}

	int ret = min(go(0, true), go(0, false));

	cout << ret << endl;


	return 0;
}
