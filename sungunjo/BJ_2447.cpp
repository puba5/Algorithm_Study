#include <iostream>
#include <vector>
using namespace std;

void recordPattern(vector<vector<char> > &map, int n, int x = 0, int y = 0) {
	int next_n = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((i == 1) && (j == 1)) {
				continue;
			} else if (n == 3) {
				map[x + i][y + j] = '*';
			} else {
				recordPattern(map, next_n, (x + (next_n * i)), (y + (next_n * j)));
			}
		}
	}
}

void printPattern(const vector<vector<char> > &map, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int N;
	scanf("%d", &N);

	vector<vector<char> > map(N, vector<char> (N, ' '));

	recordPattern(map, N);
	printPattern(map, N);

	return 0;
}