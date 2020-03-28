#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 라우터 설치 시뮬레이션 해보는 함수
// 최소 거리 이상으로 설치했을 때 라우터 전부 다 설치 가능한지를 확인
bool settingRouters(const vector<int> &houses, int remain_router, int min_dist) {
	// 첫 번째 라우터는 무조건 첫 집에 설치해야함
	// 만약 두 번째 집부터 설치했을 때도 전부 설치 가능하다면 두 번째 집에 설치한 걸 첫 번째 집으로 옮겼을 때에는
	// 최소 인접 거리 더 늘어날 수 있음
	int prev_set_pos = 0;
	remain_router -= 1;
	for (int h = 1; h < houses.size(); h++) {
		if (houses[h] - houses[prev_set_pos] >= min_dist) {
			prev_set_pos = h;
			remain_router -= 1;
			if (remain_router == 0) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	int N, C;
	int answer = -1;

	scanf("%d %d", &N, &C);
	vector<int> houses(N, 0);
	for (int n = 0; n < N; n++) {
		scanf("%d", &(houses[n]));
	}

	sort(houses.begin(), houses.end());

	int left = 1, right = houses[houses.size() - 1] - houses[0];
	while (left <= right) {
		int mid = (left + right) / 2;
		
		int setting_result = settingRouters(houses, C, mid);
		
		if (setting_result == true) {
			if (answer < mid) {
				answer = mid;
			}
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	printf("%d\n", answer);
}