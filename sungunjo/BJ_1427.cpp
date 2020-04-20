#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<int> num_arr;

	while (N > 0) {
		num_arr.push_back(N % 10);
		N /= 10;
	}

	sort(num_arr.begin(), num_arr.end(), greater<int>());

	for (int i = 0; i < num_arr.size(); i++) {
		printf("%d", num_arr[i]);
	}
	printf("\n");

	return 0;
}