#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int K, N;
	int answer = -1;
	// 랜선의 길이는 최대 2^31-1 이므로 integer 로 표현 가능하지만, 
	// mid 값을 계산하기 위해서는 left + right 연산을 해야하고, 이 때 오버플로우가 발생할 수 있다.
	// 따라서 long long 을 사용함
	long long left = 1, right = 1;

	scanf("%d %d", &K, &N);
	vector<int> cables(K, 0);
	for (int k = 0; k < K; k++) {
		scanf("%d", &(cables[k]));
		if (right < cables[k]) {
			right = cables[k];
		}
	}

	while (left <= right) {
		long long mid = (left + right) / 2;

		long long cable_count = 0;
		for (int i = 0; i < cables.size(); i++) {
			printf("%d / %lld + %lld = %lld\n", cables[i], mid, cable_count, cable_count + (cables[i] / mid));
			cable_count = cable_count + (cables[i] / mid); 
			if (cable_count >= N) {
				break;
			}
		}

		if (cable_count >= N) {
			answer = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	printf("%d\n", answer);

	return 0;
}