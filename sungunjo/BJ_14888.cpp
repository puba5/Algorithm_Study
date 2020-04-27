#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define PLUS 0
#define MINUS 1
#define MULT 2
#define DIV 3
#define OP_SIZE 4

#define MAX_SUM_LIMIT 1000000000
#define MIN_SUM_LIMIT -1000000000

void go(int &min_sum, int &max_sum, const vector<int> &num, int index, int sum, int op_cnt[OP_SIZE]) {
	if (index == num.size()) {
		min_sum = min(min_sum, sum);
		max_sum = max(max_sum, sum);
		return;
	}

	if (op_cnt[PLUS] > 0) {
		op_cnt[PLUS] -= 1;
		go(min_sum, max_sum, num, index + 1, sum + num[index], op_cnt);
		op_cnt[PLUS] += 1;
	}

	if (op_cnt[MINUS] > 0) {
		op_cnt[MINUS] -= 1;
		go(min_sum, max_sum, num, index + 1, sum - num[index], op_cnt);
		op_cnt[MINUS] += 1;
	}

	if (op_cnt[MULT] > 0) {
		op_cnt[MULT] -= 1;
		go(min_sum, max_sum, num, index + 1, sum * num[index], op_cnt);
		op_cnt[MULT] += 1;
	}

	if (op_cnt[DIV] > 0) {
		op_cnt[DIV] -= 1;
		go(min_sum, max_sum, num, index + 1, sum / num[index], op_cnt);
		op_cnt[DIV] += 1;
	}
}

int main() {
	int N;
	scanf("%d", &N);

	vector<int> num(N);
	for (int n = 0; n < N; n++) {
		scanf("%d", &(num[n]));
	}

	int op_cnt[OP_SIZE];
	for (int i = 0; i < OP_SIZE; i++) {
		scanf("%d", &(op_cnt[i]));
	}

	int min_sum = MAX_SUM_LIMIT, max_sum = MIN_SUM_LIMIT;
	go(min_sum, max_sum, num, 1, num[0], op_cnt);

	printf("%d\n%d\n", max_sum, min_sum);

	return 0;
}