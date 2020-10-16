#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> A(N), B(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += A[i] * B[i];
	}

	printf("%d\n", ret);

}
