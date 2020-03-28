#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//1 2 4 8 9
bool settingRouters(const vector<int> &houses, int remain_router, int min_dist) {
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