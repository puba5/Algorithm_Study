#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int match_A[105], match_B[105];
vector<int> adj[105];
int visited[105];
int visitCnt = 0;

bool dfs(int a) {
	if (visited[a] == visitCnt) {
		return false;
	} else {
		visited[a] = visitCnt;
	}

	for (vector<int>::iterator b = adj[a].begin(); b != adj[a].end(); b++) {
		if (match_B[*b] == -1 || dfs(match_B[*b])) {
			match_A[a] = *b;
			match_B[*b] = a;
			return true;
		}
	}

	return false;
}

int main() {
	cin >> N >> M;

	for (int m = 0; m < M; m++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
	}

	memset(match_A, -1, sizeof(match_A));
	memset(match_B, -1, sizeof(match_B));

	int ret = 0;
	for (int a = 1; a <= N; a++) {
		visitCnt++;
		if (dfs(a)) {
			ret++;
		}
	}

	cout << ret;

}
