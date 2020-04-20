#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _point {
	int x;
	int y;

	_point() : x(0), y(0) {};
	_point(int _x, int _y) : x(_x), y(_y) {};
} Point;

bool ascend(Point a, Point b) {
	if (a.x < b.x) {
		return true;
	} else if (a.x > b.x) {
		return false;
	} else {
		if (a.y < b.y) {
			return true;
		} else {
			return false;
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);

	vector<Point> point_arr(N);

	for (int n = 0; n < N; n++) {
		scanf("%d %d", &(point_arr[n].x), &(point_arr[n].y));
	}

	sort(point_arr.begin(), point_arr.end(), ascend);

	for (int i = 0; i < point_arr.size(); i++) {
		printf("%d %d\n", point_arr[i].x, point_arr[i].y);
	}

	return 0;
}