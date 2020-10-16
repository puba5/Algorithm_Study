#include <stdio.h>

int main() {
	int N, a = 1000001, b = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp < a) {
			a = tmp;
		}
		if (b < tmp) {
			b = tmp;
		}
	}

	printf("%d\n", a * b);
	return 0;
}
