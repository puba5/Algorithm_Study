#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	// 루트 N 이상인 N 의 소인수는 하나밖에 있을 수 없다.
	// 만약 두개 이상 있다면, (루트 N + a) * (루트 N + b) * ... 이 될텐데
	// 이 경우 N 보다 커져버림
	int limit = ceil(sqrt(N));
	for (int i = 2; i <= limit; i++) {
		while (N % i == 0) {
			cout << i << "\n";
			N /= i;
		}
	}

	if (N != 1) {
		cout << N << "\n";
	}

	return 0;
}