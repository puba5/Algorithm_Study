#include<iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <array>
#include <set>
#define ll long long

using namespace std;	

enum LightDirection{Up, Down, Right, Left};

int dirX[4]{ -1,1,0,0 };
int dirY[4]{ 0,0,1,-1 };

bool LaunchLight(int x, int y, LightDirection dir, vector<vector<char>> &v) {
	if (x >= v.size() || y >= v[0].size() || x < 0 || y < 0) {
		return false;
	}

	if (v[x][y] == 'O') {
		return true;
	}

	if (v[x][y] == '/') {
		switch (dir) {
		case LightDirection::Down:
			dir = LightDirection::Left;
			break;
		case LightDirection::Up:
			dir = LightDirection::Right;
			break;
		case LightDirection::Right:
			dir = LightDirection::Up;
			break;
		case LightDirection::Left:
			dir = LightDirection::Down;
			break;
		}
	}
	else if (v[x][y] == '\\')
	{
		switch (dir) {
		case LightDirection::Down:
			dir = LightDirection::Right;
			break;
		case LightDirection::Up:
			dir = LightDirection::Left;
			break;
		case LightDirection::Right:
			dir = LightDirection::Down;
			break;
		case LightDirection::Left:
			dir = LightDirection::Up;
			break;
		}
	}
	return LaunchLight(x + dirX[dir], y + dirY[dir], dir, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int w, h;
	cin >> w >> h;

	vector< vector<char> > v(h, vector<char>(w));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> v[i][j];
		}
	}

	vector<pair<char, int> > possiblities;

	for (int lightLaunchCount = 0; lightLaunchCount < 4; lightLaunchCount++) {
		// 위에서 부터 쏘는 경우
		if (lightLaunchCount == 0) {
			LightDirection dir;
			dir = LightDirection::Down;
			for (int i = 0; i < w; i++) {
				if (LaunchLight(0, i, dir, v)) {
					possiblities.push_back({ 'U',i });
				}
			}
		}
		// 아래에서 위로 쏘는 경우
		else if (lightLaunchCount == 1) {
			LightDirection dir;
			dir = LightDirection::Up;
			for (int i = 0; i < w; i++) {
				if (LaunchLight(h - 1, i, dir, v)) {
					possiblities.push_back({ 'D',i });
				}
			}
		}
		// 왼쪽에서 오른쪽으로 쏘는 경우
		else if (lightLaunchCount == 2) {
			LightDirection dir;
			dir = LightDirection::Right;
			for (int i = 0; i < h; i++) {
				if (LaunchLight(i, 0, dir, v)) {
					possiblities.push_back({ 'L',i });
				}
			}
		}
		// 오른쪽에서 왼쪽으로 쏘는 경우
		else if (lightLaunchCount == 3) {
			LightDirection dir;
			dir = LightDirection::Left;
			for (int i = 0; i < h; i++) {
				if (LaunchLight(i, w - 1, dir, v)) {
					possiblities.push_back({ 'R',i });
				}
			}
		}
	}

	// 모든 답 출력. 실제로는 위의 lightLaunchCount 반복문에서 답이 1개라도 나왔으면 바로 반복문 탈출한 후 답 출력하는게 맞음.
	for (auto i = 0; i < possiblities.size(); i++) {
		cout << possiblities[i].first << ' ' << possiblities[i].second << '\n';
	}

	// 1개 출력(정답은 무조건 존재)
	//cout << possiblities[0].first << ' ' << possiblities[0].second << '\n';

}

