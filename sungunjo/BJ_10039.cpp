#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int score;
		scanf("%d", &score);
		sum += MAX(40, score);
	}

	printf("%d\n", sum / 5);
}