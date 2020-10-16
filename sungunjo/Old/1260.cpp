#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

void dfs(vector<set<int> > &map, vector<bool> &check, vector<int> &dfs_result, int V) {
	check[V] = true;
	dfs_result.push_back(V);
	set<int>::iterator iter;
	for (iter = map[V].begin(); iter != map[V].end(); iter++) {
		if (check[*iter] == false) {
			dfs(map, check, dfs_result, *iter);
		}
	}
}

void bfs(vector<set<int> > &map, vector<bool> & check, vector<int> &bfs_result, int V) {
	queue<int> q;
	check[V] = true;
	q.push(V);
	bfs_result.push_back(V);

	while (!q.empty()) {
		int now = q.front(); q.pop();
		set<int>::iterator iter;
		for (iter = map[now].begin(); iter != map[now].end(); iter++) {
			if (check[*iter] == false) {
				check[*iter] = true;
				q.push(*iter);
				bfs_result.push_back(*iter);
			}
		}
	}
}

int main() {
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	vector<set<int> > map(N + 1);
	for (int m = 0; m < M; m++) {
		int u, v;
		scanf("%d %d", &u, &v);

		map[u].insert(v);
		map[v].insert(u);
	}

	vector<int> dfs_result, bfs_result;
	vector<bool> dfs_check(N + 1, false), bfs_check(N + 1, false);

	dfs(map, dfs_check, dfs_result, V);
	bfs(map, bfs_check, bfs_result, V);

	vector<int>::iterator iter;
	for (iter = dfs_result.begin(); iter != dfs_result.end(); iter++) {
		printf("%d ", *iter);
	}
	printf("\n");
	for (iter = bfs_result.begin(); iter != bfs_result.end(); iter++) {
		printf("%d ", *iter);
	}
}
