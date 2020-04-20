#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 88888888

int main() {
	int N;
	scanf("%d", &N);
	vector<int> num_array(N);

	for (int n = 0; n < N; n++) {
		scanf("%d", &(num_array[n]));
	}

	sort(num_array.begin(), num_array.end());


	int sum = 0;
	int freq_num_candidate[2] = {INF, INF};
	int max_freq_cnt = 0;
	int freq_cnt = 0;
	int prev_num = num_array[0];

	for (int i = 0; i < N; i++) {
		sum += num_array[i];
		if (prev_num == num_array[i]) {
			freq_cnt += 1;
		} else {
			freq_cnt = 1;
		}

		if (freq_num_candidate[0] == num_array[i]) {
			max_freq_cnt += 1;
		} else if (freq_cnt > max_freq_cnt) {
			max_freq_cnt = freq_cnt;
			freq_num_candidate[0] = num_array[i];
			freq_num_candidate[1] = INF;
		} else if ((freq_cnt == max_freq_cnt) && (freq_num_candidate[1] == INF)) {
			freq_num_candidate[1] = num_array[i];
		}

		prev_num = num_array[i];
	}

	int arthi_mean = round((double) sum / N);
	int middle_num = num_array[N / 2];
	int freq_num = ((freq_num_candidate[1] == INF) ? freq_num_candidate[0] : freq_num_candidate[1]);
	int range = num_array[N - 1] - num_array[0];
	
	printf("%d\n%d\n%d\n%d\n", arthi_mean, middle_num, freq_num, range);

	return 0;
}