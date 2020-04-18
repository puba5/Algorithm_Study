#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_N 10000

void sieve(vector<bool> &prime_num, int max_num) {
	prime_num[0] = prime_num[1] = false;

	int max_i = sqrt(max_num);

	for (int i = 2; i <= max_i; i++) {
		if (prime_num[i] == false) {
			continue;
		}

		for (int j = (i + i); j <= max_num; j += i) {
			prime_num[j] = false;
		}
	}
}

int main() {
	vector<bool> prime_num(MAX_N + 1, true);
	sieve(prime_num, MAX_N);

	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int n;
		scanf("%d", &n);

		for (int i = (n / 2); i < n; i++) {
			if (prime_num[i] == false) {
				continue;
			}

			int j = n - i;
			if (prime_num[j] == false) {
				continue;
			}

			printf("%d %d\n", j, i);
			break;
		}
	}

	return 0;
}