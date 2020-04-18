#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

double julsa(const vector<double> &scores, int N, int K) {
	double sum = 0;
	for (int i = K; i < scores.size() - K; i++) {
		sum += scores[i];
	}

	return sum / (double) (scores.size() - (2 * K));
}

double bojung(const vector<double> &scores, int N, int K) {
	double sum = (scores[K] * K) + (scores[scores.size() - (K + 1)] * K);
	for (int i = K; i < scores.size() - K; i++) {
		sum += scores[i];
	}
	return sum / (double) scores.size();
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	vector<double> scores(N, 0);

	for (int n = 0; n < N; n++) {
		scanf("%lf", &(scores[n]));
	}

	sort(scores.begin(), scores.end());

	printf("%.2lf\n", julsa(scores, N, K) + 1e-9);
	printf("%.2lf\n", bojung(scores, N, K) + 1e-9);
}
