#include <iostream>
using namespace std;

#define N 1001 

int d[N][N];
char a[N], b[N];

int dp(int i, int j) {
	if (d[i][j] == -1) {
		if (a[i+1] == '\0' && a[j+1] == '\0') {
			if (a[i] == b[j]) {
				d[i][j] = 1;
			} else {
				d[i][j] = 0;
			}
		} else if (a[i+1] == '\0') {
			if (a[i] == b[j]) {
				d[i][j] = 1;
			} else {
				d[i][j] = dp(i, j+1);
			}
		} else if (b[j+1] == '\0') {
			if (a[i] == b[j]) {
				d[i][j] = 1;
			} else {
				d[i][j] = dp(i+1, j);
			}
		} else {
			int p = (a[i] == b[j]) ? 1 : 0;
			int max = dp(i+1, j);
			
			if (max < dp(i, j+1)) {
				max = dp(i, j+1);
			}
			if (max < dp(i+1, j+1) + p) {
				max = dp(i+1, j+1) + p;
			}
			d[i][j] = max;
		}
	}
	return d[i][j];
}

int main() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			d[i][j] = -1;
		}
	}
	cin >> a >> b;

	cout << dp(0, 0) << endl;

	return 0;
}
