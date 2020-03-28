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
		
		int lego_limit = x / 2;
		int first = 0, second = -1;
		while ((first < lego.size()) && (lego[first] <= lego_limit)) {
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