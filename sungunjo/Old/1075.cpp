#include <iostream>
using namespace std;

int main() {
	int N, F;
	scanf("%d %d", &N, &F);
	N = (N / 100) * 100;
	for (int i = 0; i < 100; i++) {
		if ((N + i) % F == 0) {
			printf("%02d\n", i);
			break;
		}
	}
	return 0;
}
