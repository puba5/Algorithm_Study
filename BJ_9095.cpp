#include <iostream>
#include <vector>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int T;
	scanf("%d", &T);
	int max_num = 0;
	vector<int> input(T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &(input[t]));

		max_num = MAX(max_num, input[t]);
	}
	vector<vector<int> > num(max_num + 1, vector<int> (3, 0));
	num[1][0] = 1;
	num[2][1] = 1;
	num[3][2] = 1;
	for (int i = 2; i <= max_num; i++) {
		for (int c = 0; c < 3; c++) {
			if (i > c + 1) {
				for (int d = 0; d < 3; d++) {
					num[i][c] += (num[i - c - 1][d]);
				}
			}
		}
	}

	for (int i = 0; i < input.size(); i++) {
		int sum = 0;
		for (int c = 0; c < 3; c++) {
			sum += num[input[i]][c];
		}
		printf("%d\n", sum);
	}

	return 0;
}