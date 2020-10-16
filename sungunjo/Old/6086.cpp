#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 888888888

int N;
int c[55][55];
int f[55][55];
vector<int> adj[55];

int node(char c) {
	int ret = -1;
	if (c <= 'Z') {
		ret = c - 'A';
	} else {
		ret = c - 'a' + 26;
	}

	return ret;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		char u, v;
		int cap, nodeU, nodeV;
		cin >> u >> v >> cap;
		nodeU = node(u); nodeV = node(v);
		c[nodeU][nodeV] += cap;
		c[nodeV][nodeU] += cap;
		adj[nodeU].push_back(nodeV);
		adj[nodeV].push_back(nodeU);
	}

	int total = 0; 
	int S = node('A'); 
	int T = node('Z');

	while(1) {
		int prev[55];
		memset(prev, -1, sizeof(int) * 55);

		queue<int> q;
		q.push(S);

		while (!q.empty()) {
			int current = q.front(); q.pop();

			for (vector<int>::iterator next = adj[current].begin(); next != adj[current].end(); next++) {
				if ((c[current][*next] - f[current][*next] > 0) && (prev[*next] == -1)) {
					prev[*next] = current;
					q.push(*next);
					if (*next == T) {
						break;
					}
				}
			}
		}

		if (prev[T] == -1) {
			break;
		}

		int min_flow = INF;
		for (int p = T; p != S; p = prev[p]) {
			min_flow = min(min_flow, c[prev[p]][p] - f[prev[p]][p]);
		}

		for (int p = T; p != S; p = prev[p]) {
			f[prev[p]][p] += min_flow;
			f[p][prev[p]] -= min_flow;
		}

		total += min_flow;

	}

	cout << total << endl;
	
}
