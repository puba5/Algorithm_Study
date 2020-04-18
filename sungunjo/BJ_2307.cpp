#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	int N, M;

	scanf("%d %d", &N, &M);
	vector<vector<pair<int, int> > > adj(N);
	for (int m = 0; m < M; m++) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		a -= 1; b -= 1;
		adj[a].push_back(make_pair(t, b));
		adj[b].push_back(make_pair(t, a));
	}

	
}