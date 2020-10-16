#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int R, C;
char map[51][51];
int water[51][51];
int go[51][51];

pair<int, int> g;
pair<int, int> delta[4];

queue<pair<int, int> > q;

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			water[i][j] = -1;
			go[i][j] = -1;
			if (map[i][j] == '*') {
				water[i][j] = 0;
				q.push(make_pair(i, j));
				
			} else if (map[i][j] == 'S') {
				go[i][j] = 0;
				g = make_pair(i, j);
			}
		}
	}
	delta[0] = make_pair(1, 0);
	delta[1] = make_pair(-1, 0);
	delta[2] = make_pair(0, 1);
	delta[3] = make_pair(0, -1);

	
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int nextTime = water[p.first][p.second] + 1;
		for (int k = 0; k < 4; k++) {
			pair<int, int> near = make_pair(p.first+delta[k].first, p.second+delta[k].second);
			if (near.first < 0 || near.first >= R || near.second < 0 || near.second >= C) {
				continue;
			}

			if (map[near.first][near.second] == '.' && water[near.first][near.second] == -1) {
				water[near.first][near.second] = nextTime;
				q.push(make_pair(near.first, near.second));
			}
		}
	}

	go[g.first][g.second] = 0;
	q.push(g);

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int nextTime = go[p.first][p.second] + 1;
		for (int k = 0; k < 4; k++) {
			pair<int, int> near = make_pair(p.first+delta[k].first, p.second+delta[k].second);
			if (near.first < 0 || near.first >= R || near.second < 0 || near.second >= C) {
				continue;
			}

			if (map[near.first][near.second] == '.' && go[near.first][near.second] == -1 && (nextTime < water[near.first][near.second] || water[near.first][near.second] == -1)) {
				go[near.first][near.second] = nextTime;
				q.push(make_pair(near.first, near.second));
			} else if (map[near.first][near.second] == 'D') {
				cout << nextTime << endl;
				return 0;
			}
		}
	}

	cout << "KAKTUS" << endl;
	return 0;

}
