#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define HORSE_MOV_CNT 8
#define MONKEY_MOV_CNT 4

pair<int, int> horse_mov[HORSE_MOV_CNT] = { make_pair(-1, -2), 
											make_pair(-2, -1), 
											make_pair(-2, 1), 
											make_pair(-1, 2), 
											make_pair(1, 2), 
											make_pair(2, 1), 
											make_pair(2, -1), 
											make_pair(1, -2)};
pair<int, int> monkey_mov[MONKEY_MOV_CNT] = { 	make_pair(-1, 0),
												make_pair(0, 1),
												make_pair(1, 0),
												make_pair(0, -1)};

int main() {
	int K, W, H;

	scanf("%d %d %d", &K, &W, &H);
	vector<vector<int> > map(H, vector<int>(W));
	vector<vector<int> > k_map(H, vector<int>(W));
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			scanf("%d", &(map[h][w]));
		}
	}

	int answer = -1;
	queue<pair<int, int> > pos;
	queue<int> k;
	queue<int> cnt;
	pos.push(make_pair(0, 0));
	k.push(K);
	cnt.push(0);
	map[0][0] = -1;
	k_map[0][0] = K;

	while ((pos.empty() == false)){
		pair<int, int> now_pos = pos.front(); pos.pop();
		int now_k = k.front(); k.pop();
		int now_cnt = cnt.front(); cnt.pop();
			
		if ((now_pos.first == H - 1) && (now_pos.second == W - 1)) {
			answer = now_cnt;
			break;
		}

		if (now_k > 0) {
			for (int d = 0; d < HORSE_MOV_CNT; d++) {
				pair<int, int> next_pos = make_pair(now_pos.first + horse_mov[d].first, 
													now_pos.second + horse_mov[d].second);

				if ((next_pos.first < 0) || (next_pos.second < 0) || 
					(next_pos.first >= H) || (next_pos.second >= W) ||
					(map[next_pos.first][next_pos.second] == 1)) {
					continue;
				}

				if ((map[next_pos.first][next_pos.second] == -1) &&
					(k_map[next_pos.first][next_pos.second] >= now_k - 1)) {
					continue;
				}
				
				pos.push(next_pos);
				k.push(now_k - 1);
				cnt.push(now_cnt + 1);
				map[next_pos.first][next_pos.second] = -1;
				k_map[next_pos.first][next_pos.second] = now_k - 1;
			}
		}

		for (int d = 0; d < MONKEY_MOV_CNT; d++) {
			pair<int, int> next_pos = make_pair(now_pos.first + monkey_mov[d].first, 
												now_pos.second + monkey_mov[d].second);

			if ((next_pos.first < 0) || (next_pos.second < 0) || 
				(next_pos.first >= H) || (next_pos.second >= W) ||
				(map[next_pos.first][next_pos.second] == 1)) {
				continue;
			}

			if ((map[next_pos.first][next_pos.second] == -1) &&
				(k_map[next_pos.first][next_pos.second] >= now_k)) {
				continue;
			}

			pos.push(next_pos);
			k.push(now_k);
			cnt.push(now_cnt + 1);
			map[next_pos.first][next_pos.second] = -1;
			k_map[next_pos.first][next_pos.second] = now_k;
		}
		
	}

	printf("%d\n", answer);
}