#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define CHECK_AND_CONTINUE(cond) if (cond) { continue; }

bool isPossibleToAttack(int *row, bool *c_list, int r, int c, int N) {
	for (int i = 0; i < r; i++) {
		if ((row[i] == c) || ((r - i) == abs(c - row[i]))){
			return true;
		}
	}

	return false;
}

int nQueen(int *row, bool *c_list, int r, int N) {
	if (r == N) {
		return 1;
	}

	int sum = 0;

	for (int c = 0; c < N; c++) {
		CHECK_AND_CONTINUE((c_list[c] == true) || (isPossibleToAttack(row, c_list, r, c, N) == true))
		
		row[r] = c;
		c_list[c] = true;
		sum += nQueen(row, c_list, r + 1, N);
		c_list[c] = false;
	}

	return sum;
}

int main() {
	int N;
	scanf("%d", &N);

	int *row = new int[N];
	bool *c_list = new bool[N];

	printf("%d\n", nQueen(row, c_list, 0, N));

	return 0;
}