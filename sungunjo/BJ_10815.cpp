#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;

	scanf("%d", &N);
	vector<int> cards(N, 0);
	for (int n = 0; n < N; n++) {
		int tmp_input;
		scanf("%d", &tmp_input);
		cards[n] = tmp_input + 1E7;
	}

	sort(cards.begin(), cards.end());

	scanf("%d", &M);
	vector<int> numbers(M, 0);
	for (int m = 0; m < M; m++) {
		int tmp_input;
		scanf("%d", &tmp_input);
		numbers[m] = tmp_input + 1E7;
	}

	for (int m = 0; m < M; m++) {
		int answer = 0;
		int left = 0;
		int right = cards.size();
		while (left <= right) {
			int mid = (left + right) / 2;

			if (cards[mid] == numbers[m]) {
				answer = 1;
				break;
			} else if (cards[mid] > numbers[m]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}

		}
		printf("%d ", answer);
	}

	return 0;
}
