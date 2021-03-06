#include <iostream>

int main() {
	int answer = 1;
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);

	// 굳이 이분탐색으로 하지 않아도 풀이 가능
	// 마지막날을 제외하면 자는 동안 B 만큼 떨어지는 것을 감안해야 하고, 
	// 또한 꼭대기에 도달하는 것은 무조건 낮일것이기 때문에
	// 마지막 날 낮에 꼭대기 이상 간다고 가정하여
	// 높이 V 에서 A 를 빼고 
	// 남은 값을 하루 동안 결과적으로 올라가게 되는 높이인 (A-B) 로 나눈 값을 올림하면 마지막 날 제외한 날들이 나온다.
	// 올림해야 하는 이유는 딱 맞춰서 정상에 올라가지 않는 경우 감안한것
	if (V > A) {
		V -= A;
		int mok = V / (A - B);
		if (V % (A - B) > 0) {
			mok += 1;
		}
		answer += mok;
	}

	printf("%d\n", answer);
}
