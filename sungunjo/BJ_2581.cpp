#include <iostream>
#include <vector>
using namespace std;

vector<bool> getPrimeNumList(int max_num) {
	vector<bool> prime_num_list(max_num + 1, true);
	prime_num_list[0] = prime_num_list[1] = false;

	for (int i = 2; i <= (max_num / 2); i++) {
		int ij;
		for (int j = i; (ij = i * j) <= max_num; j++) {
			prime_num_list[ij] = false;
		}
	}

	return prime_num_list;
}

int main() {
	int M, N;
	scanf("%d %d", &M, &N);

	vector<bool> prime_num_list = getPrimeNumList(N);

	int sum = 0;
	int min_prime = -1;
	
	for (int i = M; i <= N; i++) {
		if (prime_num_list[i] == true) {
			sum += i;
			if (min_prime == -1) {
				min_prime = i;
			}
		}
	}

	if (sum == 0) {
		printf("-1\n");
	} else {
		printf("%d\n%d\n", sum, min_prime);
	}

	return 0;
}