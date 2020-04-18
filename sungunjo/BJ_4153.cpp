#include <iostream>

#define MAX(a, b, c) ((a) > (b) ? ((a) > (c) ? (a) : (b)) : ((b) > (c) ? (b) : (c)))
using namespace std;

int square(int a) {
	return a * a;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	while (true) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if ((a == 0) && (b == 0) && (c == 0)) {
			break;
		}

		if (a < b) {
			swap(a, b);
		}

		if (a < c) {
			swap(a, c);
		}

		if (square(a) == (square(b) + square(c))) {
			printf("right\n");
		} else {
			printf("wrong\n");
		}

	}

	return 0;
}