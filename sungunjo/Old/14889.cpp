#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 88888888

int N;
int S[25][25];
int team_size;

int dfs(int player, int team, vector<int> entry0, vector<int>entry1) {
	int team_stat[2] = {0, 0};
	int ret = INF;

	if (team == 0) {
		entry0.push_back(player);
	} else {
		entry1.push_back(player);
	}
	if (player < N-1) {
		if (entry0.size() < team_size) {
			team_stat[0] = dfs(player+1, 0, entry0, entry1);
		} else {
			team_stat[0] = INF;
		}
		if (entry1.size() < team_size) {
			team_stat[1] = dfs(player+1, 1, entry0, entry1);
		} else {
			team_stat[1] = INF;
		}
		ret = min(team_stat[0], team_stat[1]);
	} else if (player == N-1) {
		for (int i = 0; i < team_size; i++) {
			for (int j = 0; j < team_size; j++) {
				team_stat[0] += S[entry0[i]][entry0[j]];
				team_stat[1] += S[entry1[i]][entry1[j]];
			}
		}

		ret = abs(team_stat[0] - team_stat[1]);
	}

	return ret;
}

int main() {
	cin >> N;
	team_size = N / 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}

	vector<int> entry0, entry1;

	int ans = min(dfs(0, 0, entry0, entry1), dfs(0, 1, entry0, entry1));

	cout << ans << endl;

	return 0;
}
