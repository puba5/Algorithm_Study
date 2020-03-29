#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define HORSE_MOV_CNT 8
#define MONKEY_MOV_CNT 4
#define INF 888888888

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
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			int input;
			scanf("%d", &input);
			// 장애물은 INF, 길은 -1
			// k 기록할 맵 따로 안만들어주기 위해서 장애물은 INF 로 해서 k 가 얼마던지 절대 방문 안하도록 함
			// k 가 0일 경우에도 방문은 해야되니까 길은 -1 로 해서 이후 예외처리에서 걸려 continue 되지 않도록 조치
			if (input == 1) {
				map[h][w] = INF;
			} else {
				map[h][w] = -1;
			}
		}
	}

	int answer = -1;
	queue<pair<int, int> > pos;
	queue<int> k;
	queue<int> cnt;
	pos.push(make_pair(0, 0));
	k.push(K);
	cnt.push(0);
	map[0][0] = K;

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
				int next_k = now_k - 1;

				// 범위 초과인 경우 제외
				// 또한 이전에 해당 위치 방문했을 때 k 가 다음 방문시 k 보다 크거나 같은 경우도 제외시킴
				// k 많이 남은 상태로 온 적이 더 먼저 검사되었다면 k도 적고 행동수도 더 같거나 많은 다음 방문을 검사할 필요 없음
				// k 더 일찍 소모해서 더 일찍 도착할 수 있다면 queue 에 먼저 들어가서 먼저 나오고, 먼저 도착했을것
				if ((next_pos.first < 0) || (next_pos.second < 0) || 
					(next_pos.first >= H) || (next_pos.second >= W) ||
					(map[next_pos.first][next_pos.second] >= next_k)) {
					continue;
				}
				
				pos.push(next_pos);
				k.push(next_k);
				cnt.push(now_cnt + 1);
				map[next_pos.first][next_pos.second] = next_k;
			}
		}

		for (int d = 0; d < MONKEY_MOV_CNT; d++) {
			pair<int, int> next_pos = make_pair(now_pos.first + monkey_mov[d].first, 
												now_pos.second + monkey_mov[d].second);
			int next_k = now_k;

			if ((next_pos.first < 0) || (next_pos.second < 0) || 
				(next_pos.first >= H) || (next_pos.second >= W) ||
				(map[next_pos.first][next_pos.second] >= next_k)) {
				continue;
			}

			pos.push(next_pos);
			k.push(next_k);
			cnt.push(now_cnt + 1);
			map[next_pos.first][next_pos.second] = next_k;
		}
		
	}

	printf("%d\n", answer);
}