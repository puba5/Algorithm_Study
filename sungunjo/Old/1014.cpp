#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int C, N, M;
int matchL[55], matchR[55];
int visited[55];
int visitCnt = 0;
vector<int> adj[55];
int lChecked, rChecked;

int main() {
	cin >> C;

	for (int c = 0; c < C; c++) {
		for (int i = 0; i < 55; i++) {
			adj[i].clear();
		}
		memset(matchL, -1, sizeof(matchL));
		memset(matchR, -1, sizeof(matchR));
		
		cin >> N >> M;

		int lNum = 0, rNum = 0;

		int temp[15][15];
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> temp[n][m];
				if (temp[n][m] == '.') {
					if (m % 2 == 0) {
						temp[n][m] = lNum;
						lNum++;
					} else {
						temp[n][m] = rNum;
						rNum++;
					}
				}
			}
		}

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (temp[n][m] != 'x') {
					if (m % 2 == 0) {
						if (m + 1 < M) {
							for (int d = -1; d < 2; d++) {
								if ((n + d >= 0) && (n + d < N) && (temp[n+d][m+1] != 'x')) {
									adj[temp[n][m]].push_back(temp[n+d][m+1]);
								}
							}
						}
					} else {
						if (m + 1 < M) {
							for (int d = -1; d < 2; d++) {
								if ((n + d >= 0) && (n + d < N) && (temp[n+d][m+1] != 'x')) {
									adj[temp[n+d][m+1]].push_back(temp[n][m]);
								}
							}
						}	
					}
				}
			}
		}

		for (int l = 0; l < lNum; l++) {
			visitCnt++;
			dfs(l);
		}

		visitCnt = -1;
		for (int l = 0; l < lNum; l++) {
			check(l);
		}

		cout << (lNum + rNum) - ((lNum - lChecked) + rChecked);

	}
}
