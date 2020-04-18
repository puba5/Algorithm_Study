#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct _point {
	int x;
	int y;

	_point() : x(0), y(0) {}
	_point(int _x, int _y) : x(_x), y(_y) {};
} Point;


int calcDist(Point p1, Point p2) {
	return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		Point p1, p2;
		int r1, r2;
		scanf("%d %d %d %d %d %d", &p1.x, &p1.y, &r1, &p2.x, &p2.y, &r2);
		if (r1 < r2) {
			swap(r1, r2);
		}

		int R = calcDist(p1, p2);
		int sum = pow(r1 + r2, 2);
		int diff = pow(r1 - r2, 2);

		if (R == 0) {
			if (diff == 0) {
				printf("-1\n");
			} else {
				printf("0\n");
			}
		} else if ((R == diff) || (R == sum)) {
			printf("1\n");
		} else if ((diff < R) && (R < sum)) {
			printf("2\n");
		} else {
			printf("0\n");
		}
	}

	return 0;
}