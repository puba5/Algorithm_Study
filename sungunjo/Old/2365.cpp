#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int N;
	cin >> N;
	int ans[50][50];
	int max[50][50];
	int ans_row[50];
	int ans_col[50];
	for (int i = 0; i < N; i++) {
		cin >> ans_row[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> ans_col[i];
	}

	pair<int, int> max_pair = make_pair(0, 0);
	int max_value = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp_min = min(ans_row[i], ans_row[j]);
			if (max_value < temp_min) {
				max_value = temp_min;
				max_pair = make_pair(i, j);
			}
		}
	}



	return 0;
}
