#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;

	scanf("%d", &N);
	vector<int> cards(2E7 + 1, 0);
	for (int n = 0; n < N; n++) {
		int input;
		scanf("%d", &input);
		cards[input + 1E7] += 1;
	}

	scanf("%d", &M);
	vector<int> numbers(M, 0);
	for (int m = 0; m < M; m++) {
		int input;
		scanf("%d", &input);
		numbers[m] = input + 1E7;
	}

	for (int m = 0; m < M; m++) {
		printf("%d ", cards[numbers[m]]);
	}

}