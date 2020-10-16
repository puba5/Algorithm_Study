#include <iostream>
using namespace std;

int main() {
	int x, y, w, h, result;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	if (x > w / 2) {
		x = w - x;
	}
	if (y > h / 2) {
		y = h - y;
	}
	(x > y) ? printf("%d\n", y) : printf("%d\n", x);

	return 0;
}
