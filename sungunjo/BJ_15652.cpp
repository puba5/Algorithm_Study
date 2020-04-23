#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define CHECK_AND_CONTINUE(cod) if (cond) { contiue; }

void print(const vector<int> &num) {
	for (int i = 0; i < num.size(); i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
}

void go(vector<int> &picked, int index, int start, int N, int M) {
	if (index == M) {
		print(picked);
		return;
	}

	for (int i = start; i <= N; i++) {
		picked[index] = i;
		go(picked, index + 1, i, N, M);
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	vector<int> picked(M);

	go(picked, 0, 1, N, M);

	return 0;
}