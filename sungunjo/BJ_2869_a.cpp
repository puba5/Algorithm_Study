#include <iostream>

using namespace std;

int main() {
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);

	// 바이너리 서치로 꼭대기에 도달 가능한 가장 빠른 날을 찾는다.
	// 최소 V / A 일, 최대 V / (A-B) + 1 일(최소값은 버림, 최대값은 올림) 걸린다고 가정하고 이분탐색 
	
	int left = V / A;
	int right = V / (A - B) + 1;
	int answer = -1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if ((mid - 1) * (A - B) + A >= V) {
			answer = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	printf("%d\n", answer);
}
