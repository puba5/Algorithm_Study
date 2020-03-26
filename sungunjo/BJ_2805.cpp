#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, answer = -1;
	scanf("%d %d", &N, &M);
	vector<int> trees(N, 0);

	int left = 0, right = 0;

	// 가장 큰 나무를 최대값, 0을 최소값으로 하여 이분탐색
	for (int n = 0; n < N; n++) {
		scanf("%d", &(trees[n]));
		if (trees[n] > right) {
			right = trees[n];
		}
	}

	while (left <= right) {
		int mid = (left + right) / 2;

		long long H = 0;
		for (int i = 0; i < trees.size(); i++) {
			// mid 값을 높이로 하여 나무들을 베었을 때 나오는 목재 길이 합이 M 보다 크거나 같은지 확인
			// 크거나 같을 경우 높이 더 올려서 베어도 되는지 확인하기 위해 left 를 mid + 1 로 바꿔서 반복
			int h = trees[i] - mid;
			if (h > 0) {
				H += h;
			}

			if (H >= M) {
				break;
			}
		}

		if (H >= M) {
			answer = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	printf("%d\n", answer);
}
