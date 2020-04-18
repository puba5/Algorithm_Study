#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define MAX_N 123456

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
	vector<bool> prime_num((MAX_N * 2) + 1, true);
	sieve(prime_num, (MAX_N * 2));
	
	while (true) {
		int n;
		scanf("%d", &n);

		if (n == 0) {
			break;
		}

		int n_2 = n * 2;
		int cnt = 0;
		for (int i = (n + 1); i <= n_2; i++) {
			if (prime_num[i] == true) {
				cnt += 1;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}