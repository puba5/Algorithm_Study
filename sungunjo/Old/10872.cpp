#include <iostream>
using namespace std;

int main() {
	int N;
	int result = 1;
	scanf("%d", &N);
	for (int n = N; n > 0; n--) {
		result *= n;
	}
	printf("%d\n", result);
	return 0;
}
