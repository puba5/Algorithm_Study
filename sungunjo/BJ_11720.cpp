#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int sum = 0;
	for (int n = 0; n < N; n++) {
		int input;
		scanf("%1d", &input);
		sum += input;
	}

	printf("%d\n", sum);

	return 0;
}