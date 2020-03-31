#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct _node {
	int subin;
	int time;
	
	_node(int _subin, int _time = 0) : subin(_subin), time(_time) {};
} Node;

int d[2] = {-1, 1};

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	vector<bool> visited(200000, false);

	queue<Node> q;
	q.push(Node(N));
	visited[N] = true;
	while (q.empty() == false) {
		Node now = q.front(); q.pop();

		if (now.subin == K) {
			printf("%d\n", now.time);
			return 0;
		}

		for (int i = 0; i < 1; i++) {
			Node next(now.subin * 2, now.time + 1);

			if ((next.subin >= 0) && (next.subin < visited.size()) && (visited[next.subin] == false)) {
				q.push(next);
				visited[next.subin] = true;
			}
		}

		for (int i = 0; i < 2; i++) {
			Node next(now.subin + d[i], now.time + 1);

			if ((next.subin >= 0) && (next.subin < visited.size()) && (visited[next.subin] == false)) {
				q.push(next);
				visited[next.subin] = true;
			}
		}
	}
 
	return -1;
}