#include <iostream>
using namespace std;

#define MAX_N 1000000000

int main() {
	int N;
	scanf("%d", &N);

	int line_start = 1;
	int line_last = 1;
	int line = 1;
	
	while (line_last <= MAX_N) {
		if ((line_start <= N) &&
			(N <= line_last)) {
			break;
		}

		line_start = line_last + 1;
		line_last += (6 * line);
		line += 1;
	}

	printf("%d\n", line);

	return 0;
}