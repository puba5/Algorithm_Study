#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 1000

void sieve(vector<bool> &prime_num, int max_n) {
	prime_num[0] = prime_num[1] = false;
	for (int i = 2; i <= max_n / 2; i++) {
		int not_prime;
		for (int j = i; (not_prime = i * j) <= max_n; j++) {
			prime_num[not_prime] = false;
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);

	int max_n = 0;
	vector<int> num(N, 0);
	for (int n = 0; n < N; n++) {
		scanf("%d", &(num[n]));

		max_n = max(max_n, num[n]);
	}

	vector<bool> prime_num(max_n + 1, true);
	sieve(prime_num, max_n);

	int cnt = 0;
	for (int i = 0; i < num.size(); i++) {
		if (prime_num[num[i]] == true) {
			cnt += 1;
		}
	}

	printf("%d\n", cnt);

	return 0;
}