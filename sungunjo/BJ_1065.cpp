#include <iostream>
using namespace std;

bool checkHansu(int num) {
	int prev = num % 10; num /= 10;
	int now = num % 10; num /= 10;
	int d = now - prev;
	while (num > 0) {
		prev = now;
		now = num % 10; num /= 10;
		if (d != (now - prev)) {
			return false;
		}
	}

	return true;
}

int main() {
	int N;
	scanf("%d", &N);
	
	int hansu_cnt = 0;
	for (int n = 1; n <= N; n++) {
		if (checkHansu(n) == true) {
			hansu_cnt += 1;
		}
	}

	printf("%d\n", hansu_cnt);

	return 0;
}