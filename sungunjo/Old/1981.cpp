#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int n;
int map[100][100];
int check[100][100];
pair<int, int> d[4];

bool bfs() {
	queue<pair<int, int> > q;

	if (check[0][0] == 0) {
		check[0][0] = 1;
		q.push(make_pair(0, 0));
	} else {
		return false;
	}

	while (!q.empty()) {
		pair<int, int> c = q.front(); q.pop();
		pair<int, int> next;

		if (c.first == n-1 && c.second == n-1) {
			return true;
		}
		for (int i = 0; i < 4; i++) {
			next.first = c.first + d[i].first;
			next.second = c.second + d[i].second;

			if (check[next.first][next.second] != 0 || next.first < 0 || next.second < 0 || next.first >= n || next.second >= n) {
				continue;
			}

			check[next.first][next.second] = 1;
			q.push(next);
		}
	}

	return false;
}

int main() {
	int low = 8888, high = 0;

	d[0] = make_pair(1, 0);
	d[1] = make_pair(0, -1);
	d[2] = make_pair(-1, 0);
	d[3] = make_pair(0, 1);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			low = min(low, map[i][j]);
			high = max(high, map[i][j]);
		}
	}

	int start = 0; int end = high - low;
	int ret = 8888;
	while (start <= end) {
		int diff = (start + end) / 2;
cout << start << ", " << diff << ", " << end << endl;
		bool exist = false;
		for (int i = low; i <= high - diff; i++) {
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					check[x][y] = -1;
				}
			}
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					if (i <= map[x][y] && map[x][y] <= i + diff) {
						check[x][y] = 0;
					}
cout << check[x][y] << " ";
				}
cout << endl;
			}
cout << endl;
			if (bfs()) {
				ret = min(ret, diff);
				exist = true;
				break;
			}
		}
		if (exist) {
cout << "exist" << endl;
			end = diff - 1;
		} else {
cout << "not found" << endl;
			start = diff + 1;
		}
	}

	cout << ret << endl;

	return 0;
}
