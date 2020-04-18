#include <iostream>
#include <queue>
#include <utility>
#include <limits.h>
using namespace std;

void dijkstra(const vector<vector<pair<int, int> > > &adj, vector<int> &dist, int start) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	// 시작은 start->start->? 경로 탐색부터
	// start 를 경유지로 해서 start 로 부터의 인접 노드들까지 경로 갱신
	dist[start] = 0;
	pq.push(make_pair(0, start));

	// priority queue 안에는 현재 S 집합에 속하는 경유지들 통해서 갈 수 있는 경로들이 모두 들어있음
	// 즉 이 큐가 비었다는건 더이상 갈 수 있는 곳 없다는 뜻
	while (pq.empty() != true) {
		int s = pq.top().second;
		int dist_to_s = pq.top().first;
		pq.pop();

		// 방금 꺼낸 경로가 push 된 이후 s 까지 가는 더 짧은 경로가 찾아져서 dist[s] 가 갱신되었을 수 있다.
		// 따라서 dist[s] 가 dist_to_s 보다 짧으면 방금 꺼낸 경로 안봐도 됨
		if (dist[s] < dist_to_s) {
			continue;
		}

		for (int i = 0; i < adj[s].size(); i++) {
			int u = adj[s][i].second;
			int dist_to_u = dist_to_s + adj[s][i].first;

			if (dist[u] > dist_to_u) {
				dist[u] = dist_to_u;
				pq.push(make_pair(dist_to_u, u));
			}
		}
	}
}

int main() {
	int V, E, K;
	scanf("%d %d %d", &V, &E, &K);
	vector<vector<pair<int, int> > > adj(V);
	vector<int> dist(V, INT_MAX);

	for (int e = 0; e < E; e++) {
		int v, u, w;
		scanf("%d %d %d", &v, &u, &w);
		// pair 대소 비교시 first 부터 비교하기 때문에 거리를 기준으로 min heap 정렬 원하면 first 에 거리를 넣어야 함
		adj[v - 1].push_back(make_pair(w, u - 1));
	}

	dijkstra(adj, dist, K - 1);

	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] < INT_MAX) {
			printf("%d\n", dist[i]);
		} else {
			printf("INF\n");
		}
	}

	return 0;
}