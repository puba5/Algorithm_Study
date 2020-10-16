#include <iostream>
using namespace std;
#define N 100

int main() {
	int caseNum = 0;
	cin >> caseNum;

	int a[N+1][N][2];
	int *n = new int[caseNum];
	int *k = new int[caseNum];

	a[1][0][0] = 1;
	a[1][0][1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= N-1; j++) {
			a[i][j][0] = a[i-1][j][0] + a[i-1][j][1];
			if (j > 0) a[i][j][1] = a[i-1][j][0] + a[i-1][j-1][1];
			else a[i][j][1] = a[i-1][j][0];
		}
	}

	for (int i = 0; i < caseNum; i++) cin >> n[i] >> k[i];

	for (int i = 0; i < caseNum; i++) cout << a[n[i]][k[i]][0] + a[n[i]][k[i]][1] << endl;
	return 0;
}
