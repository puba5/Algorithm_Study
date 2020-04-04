#include <iostream>
using namespace std;

int getNumLen(int num) {
	int len = 0;
	while (num > 0) {
		num /= 10;
		len++;
	}

	return len;
}

int calcBunhaeHap(int num) {
	int sum = num;
	while (num > 0) {
		sum += (num % 10);
		num /= 10;
	}

	return sum;
}

int main() {
	int n;
	scanf("%d", &n);
	int num_len = getNumLen(n);
	int min_constructor = 0;

	for (int candidate = n - (num_len  * 9); candidate < n; candidate++) {
		if (calcBunhaeHap(candidate) == n) {
			min_constructor = candidate;
			break;
		}
	}

	printf("%d\n", min_constructor);
	return 0;
}