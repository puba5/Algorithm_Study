#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<int> num(N);

	for (int n = 0; n < N; n++) {
		scanf("%d", &(num[n]));
	}

	sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); i++) {
		if ((i > 0) && (num[i] == num[i - 1])) {
			continue;
		}

		printf("%d ", num[i]);
	}

	return 0;
}