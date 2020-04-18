#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000008

typedef struct _question {
	int k;
	int v;

	_question(int _k, int _v) : k(_k), v(_v) {};
} Question;

void dijkstra(vector<vector<int> > &map, int start) {
	vector<int> exclude_s;
	for (int i = 0; i < map.size(); i++) {
		if (i == start) {
			continue;
		}
		exclude_s.push_back(i);
	}
	
	while (exclude_s.empty() != true) {
		int next_s = start;
		vector<int>::iterator iter;
		vector<int>::iterator next_s_iter;
		for (iter = exclude_s.begin(); iter != exclude_s.end(); iter++) {
			if (map[start][*iter] < map[start][next_s]) {
				next_s = *iter;
				next_s_iter = iter;
			}
		}
		exclude_s.erase(next_s_iter);

		for (iter = exclude_s.begin(); iter != exclude_s.end(); iter++) {
			if (map[next_s][*iter] < INF) {
				map[start][*iter] = min(map[start][next_s], map[next_s][*iter]);
				map[*iter][start] = map[start][*iter];
			}
		}
	}

}


int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<vector<int> > map(N, vector<int> (N, INF));
	vector<Question> question; 
	for (int n = 0; n < N - 1; n++) {
		int p, q, r;
		scanf("%d %d %d", &p, &q, &r);
		map[p - 1][q - 1] = r;
		map[q - 1][p - 1] = r;
	}

	for (int q = 0; q < Q; q++) {
		int k, v;
		scanf("%d %d", &k, &v);
		question.push_back(Question(k, v - 1));
	}
	
	for (int n = 0; n < N; n++) {
		dijkstra(map, n);
	}

	for (int q = 0; q < Q; q++) {
		int recommend_video = 0;
		for (int i = 0; i < N; i++) {
			if ((map[question[q].v][i] < INF) &&
				(map[question[q].v][i] >= question[q].k)) {
				recommend_video += 1;
			}
		}
		printf("%d\n", recommend_video);
	}

	return 0;
}