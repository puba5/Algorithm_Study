#include <iostream>
#include <vector>

using namespace std;

int calcBudgetSum(const vector<int> &budgets, int limit, int M, int &answer) {
	int sum = 0;
	int max = 0;
	for (int i = 0; i < budgets.size(); i++) {
		if (budgets[i] > limit) {
			sum += limit;
			max = limit;
		} else {
			sum += budgets[i];
			if (max < budgets[i]) {
				max = budgets[i];
			}
		}

		if (sum > M) {
			// 전체 예산 초과시 예산 상한 좌측으로 옮겨야함
			// 더이상 계산해볼 필요도 없으므로 바로 -1 리턴
			// 예산 할당 실패했으므로 answer 값 변경할 필요 없음
			return -1;
		}
	}

	if (answer < max) {
		answer = max;
	}

	if (sum < M) {
			// 전체 예산보다 적을 경우 지금보다 더 많이 배정할 수 있는지 확인해봐야하므로 
			// 예산 상한 우측으로 옮겨야함
			// 이게 최선일 수도 있으므로 answer 값에 현재 최대 지방 예산 할당량 넣어줌
			return 1;
		} else {
			// 전체 예산과 일치할 경우 최적의 답
			return 0;
		}
	return sum;
}

int main() {
	int N, M;
	int answer = -1;
	
	scanf("%d", &N);
	vector<int> local_budget(N, 0);
	int left = 1, right = 1;
	for (int n = 0; n < N; n++) {
		scanf("%d", &(local_budget[n]));
		if (right < local_budget[n]) {
			right = local_budget[n];
		}
	}

	scanf("%d", &M);
	while (left <= right) {
		int mid = (left + right) / 2;

		int result = calcBudgetSum(local_budget, mid, M, answer);
		if (result > 0) {
			left = mid + 1;
		} else if (result < 0) {
			right = mid - 1;
		} else {
			break;
		}
	}

	printf("%d\n", answer);
}