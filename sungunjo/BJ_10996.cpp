#include <iostream>

int main() {
	int N;
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		for (int i = 0; i < 2; i++) {
			for (int k = 0; k < N; k++) {
				if (k % 2 == i) {
					printf("*");
				} else {
					printf(" ");
				}
			}
			printf("\n");
		}
	}

	return 0;
}