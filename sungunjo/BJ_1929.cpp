#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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
	int M, N;
	scanf("%d %d", &M, &N);

	vector<bool> prime_num(N + 1, true);
	sieve(prime_num, N);

	for (int i = M; i <= N; i++) {
		if (prime_num[i] == true) {
			printf("%d\n", i);
		}
	}

	return 0;
}