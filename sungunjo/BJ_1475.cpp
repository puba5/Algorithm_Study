#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int plastic_num[10] = {0,};

	do {
		plastic_num[N % 10] += 1;
	} while (N /= 10);

	int six_nine = plastic_num[6] + plastic_num[9];
	int six = six_nine / 2;
	int nine = six_nine - six;
	plastic_num[6] = six;
	plastic_num[9] = nine;

	int answer = 0;
	for (int i = 0; i < 10; i++) {
		answer = max(answer, plastic_num[i]);
	}

	printf("%d\n", answer);
}