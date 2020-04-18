#include <iostream>

int main() {
	int C;
	scanf("%d", &C);

	for (int c = 0; c < C; c++) {
		int N;
		scanf("%d", &N);
		int *scores = new int[N];
		int sum = 0;
		for (int n = 0; n < N; n++) {
			scanf("%d", &(scores[n]));
			sum += scores[n];
		}
		int avg = sum / N;
		int over_avg_cnt = 0;
		for (int n = 0; n < N; n++) {
			if (scores[n] > avg) {
				over_avg_cnt += 1;
			}
		}
		double over_avg_percentage = ((double) over_avg_cnt / N) * 100;
		printf("%.3f%%\n", over_avg_percentage);
	}
}