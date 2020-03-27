#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	int N, M;

	scanf("%d", &N);
	unordered_map<int, int> cards;
	for (int n = 0; n < N; n++) {
		int input;
		scanf("%d", &input);
		input += 1E7;
		unordered_map<int, int>::iterator iter = cards.find(input);
		if (iter != cards.end()) {
			iter->second += 1;
		} else {
			cards.insert(make_pair(input, 1));
		}
	}

	scanf("%d", &M);
	int *numbers = new int[M];
	for (int m = 0; m < M; m++) {
		int input;
		scanf("%d", &input);
		numbers[m] = input + 1E7;
	}

	for (int m = 0; m < M; m++) {
		unordered_map<int, int>::iterator iter = cards.find(numbers[m]);
		if (iter != cards.end()) {
			printf("%d ", iter->second);
		} else {
			printf("0 ");
		}
	}

}