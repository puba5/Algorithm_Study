#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[3] = {-1, 0, 1};

bool bm(vector<int> &adj, int &match) {
	if (match == -1) {
		match = 
	}
}

int main () {
	int C;
	cin >> C;
	for (int c = 0; c < C; c++) {
		int N, M;
		cin >> N >> M;

		char map[15][15];
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> map[n][m];
			}
		}

		bool visit_l[55], visit_r[55];
		vector<int> adj_l[55], adj_r[55];

		for (int i = 0; i < 55; i++) {
			visit_l[i] = visit_r[i] = false;
		}

		int total_chair = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (map[n][m] == 'x') {
					continue;
				}

				total_chair++;
				for (int i = 0; i < 3; i++) {
					if ((0 <= n+d[i]) && (n+d[i] < N) && (map[n+d[i]][m+1] == '.')) {
						if (m % 2 == 0) {
							if (n+m/2*N >= 30) {
								cout << "sbial" << endl;
							}
							adj_l[n+m/2*N].push_back((n+d[i])+(m+1)/2*N);
							adj_r[(n+d[i])+(m+1)/2*N].push_back(n+m/2*N);
						} else {
							adj_r[n+m/2*N].push_back((n+d[i])+(m+1)/2*N);
							adj_l[(n+d[i])+(m+1)/2*N].push_back(n+m/2*N);
						}
					}
				}
			}
		}


	}
}
