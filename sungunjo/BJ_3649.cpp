#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int x, n;
	while (scanf("%d", &x) != EOF) {
		x *= 1E7;
		scanf("%d", &n);
		vector<int> lego(n, 0);
		for (int i = 0; i < n; i++) {
			scanf("%d", &(lego[i]));;
		}

		sort(lego.begin(), lego.end());
		
		// 가장 짧은 레고 부터 구멍 크기 절반 길이 레고까지 돌면서 나머지 한 조각 길이를 찾음
		int lego_limit = x / 2;
		int first = 0, second = -1;
		while ((first < lego.size()) && (lego[first] <= lego_limit)) {
			// 첫 번째 조각 다음 레고부터 마지막 레고까지만 확인하면 됨
			// 첫 번째 조각 이전 조각들은 이미 이전에 확인한것들이기 때문
			int left = first + 1, right = lego.size() - 1;
			int remain_len = x - lego[first];
			while (left <= right) {
				int mid = (left + right) / 2;
				
				if (lego[mid] > remain_len) {
					right = mid - 1;
				} else if (lego[mid] < remain_len) {
					left = mid + 1;
				} else {
					second = mid;
					break;
				}
			}
			
			if (second != -1) {
				break;
			} else {
				first += 1;
			}
		}
		if (second != -1) {
			printf("yes %d %d\n", lego[first], lego[second]);
		} else {
			printf("danger\n");
		}

	}

	return 0;
}