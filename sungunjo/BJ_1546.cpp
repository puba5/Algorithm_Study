#include <iostream>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int N;
	scanf("%d", &N);
	int *arr = new int[N];
	int max_score = 0;
	for (int n = 0; n < N; n++) {
		scanf("%d", &(arr[n]));
		max_score = MAX(max_score, arr[n]);
	}

	double sum = 0;
	for (int n = 0; n < N; n++) {
		sum += (((double) arr[n] / max_score) * 100);
	}

	printf("%f", sum / N);

	return 0;
}