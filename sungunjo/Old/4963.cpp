#include <iostream>
#include <queue>
using namespace std;

void go(int x, int y) {
	vector<vector<int> > v(x, vector<int> (y, 0));
	int check = 1;
	int dx[8] = {-1, -1, 0, 1, 1,  1,  0, -1};
	int dy[8] = { 0,  1, 1, 1, 0, -1, -1, -1};

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			register int tmp;
			scanf("%d", &tmp);
			if (tmp) {
				v[i][j] = 1;
			}
		}
	}


	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (v[i][j] != 1) {
				continue;
			}

			queue<int> qx;
			queue<int> qy;
			v[i][j] = ++check;
			qx.push(i);
			qy.push(j);

			while(!qx.empty() && !qy.empty()) {
				int cx = qx.front(); qx.pop();
				int cy = qy.front(); qy.pop();

				for (int d = 0; d < 8; d++) {
					int nx = cx + dx[d];
					int ny = cy + dy[d];

					if ((nx < 0) || (ny < 0) || (x <= nx) || (y <= ny) || (v[nx][ny] != 1)) {
						continue;
					}

					v[nx][ny] = check;
					qx.push(nx);
					qy.push(ny);
				}
			}

		}
	}

	printf("%d\n", check - 1);
}

int main() {
	while(true) {
		int y, x;
		scanf("%d %d", &y, &x);
		if ((x != 0) && (y != 0)) {
			go(x, y);
		} else {
			break;
		}
	}
	return 0;
}
