#include <iostream>
using namespace std;

#define MAX_LINE 10000000

int main() {
	int X;
	scanf("%d", &X);

	int molecular = -1;
	int denominator = -1;

	int start = 0;
	int end = 0;

	for (int line = 1; end <= MAX_LINE; line++) {
		start = end + 1;
		end += line;

		if ((X < start) || (end < X)) {
			continue;
		}

		if (line % 2 == 0) {
			molecular = (X - start) + 1;
			denominator = (line - molecular) + 1;
			break;
		} else {
			molecular = (end - X) + 1;
			denominator = (line - molecular) + 1;
			break;
		}
	}

	printf("%d/%d\n", molecular, denominator);

	return 0;
}