#include <iostream>
#include <vector>
using namespace std;

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	int ABC = A * B * C;
	vector<int> arr(10, 0);
	while(ABC > 0) {
		int tmp = ABC % 10;
		ABC /= 10;
		arr[tmp]++;
	}
	vector<int>::iterator iter;
	for (iter = arr.begin(); iter != arr.end(); iter++) {
		printf("%d\n", *iter);
	}

	return 0;
}
