#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 10000

void d(int n, vector<bool> &isSelfNum) {
	int self_num = n;
	while (n > 0) {
		self_num += n % 10;
		n /= 10;
	}

	if (self_num < isSelfNum.size()) {
		isSelfNum[self_num] = false;
	}
}

int main() {
	vector<bool> isSelfNum(MAX_N + 1, true);
	for (int n = 1; n <= MAX_N; n++) {
		if (isSelfNum[n] == true) {
			printf("%d\n", n);
		}
		d(n, isSelfNum);
	}

	return 0;
}