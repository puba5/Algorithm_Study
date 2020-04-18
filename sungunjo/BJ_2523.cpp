#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	char *star = new char[N + 1];

	int i;
	for (i = 0; i < N; i++) {
		star[i] = '*';
		star[i + 1] = '\0';
		printf("%s\n", star);
	}
	for (i = N - 1; i >= 0; i--) {
		star[i] = '\0';
		printf("%s\n", star);
	}
	

	return 0;
}