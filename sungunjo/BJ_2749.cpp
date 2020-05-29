#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define M 1000000
#define P_LIMIT 1000000000000

int main() {
	unsigned long long n;
	cin >> n;

	unsigned long long p = 0;

	vector<int> fibo(2);
	fibo[0] = 0; fibo[1] = 1;
	for (unsigned long long i = 2; i <= P_LIMIT; i++) {
		fibo.push_back((fibo[i - 1] + fibo[i - 2]) % M);
		if ((fibo[i - 1] == 0) && (fibo[i] == 1)) {
			p = i - 1;
			break;
		}
	}

	cout << fibo[n % p];

	return 0;
}