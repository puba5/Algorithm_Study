#include <iostream>
using namespace std;

bool isNumOfDevil(int num) {
	int cnt = 0;
	while (num > 0) {
		int now = num % 10;

		if (now == 6) {
			cnt += 1;
			if (cnt == 3) {
				return true;
			}
		} else {
			cnt = 0;
		}
		num /= 10;
	}

	return false;
}

int main() {
	int N;
	scanf("%d", &N);

	int num = 666;
	int n = 1;
	while (n < N) {
		num += 1;
		if (isNumOfDevil(num) == true) {
			n += 1;
		}
	}

	printf("%d\n", num);

	return 0;
}