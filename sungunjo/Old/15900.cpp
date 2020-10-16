#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int> > &arr, vector<bool> &visit, int index, int cnt) {
	if (visit[index] == false) {
		visit[index] = true;

		int len = arr[index].size();
		cout << "index = " << index << ", cnt = " << cnt << ", len = " << len << endl;
		if ((index != 1) && (len == 1)) {
			return cnt;
		} else {
			int sum = 0;
			for (int i = 0; i < len; i++) {
				sum += dfs(arr, visit, arr[index][i], cnt+1);
			}
			return sum;
		}
	} else {
		return 0;
	}

	return -1;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<vector<int> > arr(N+1);
	vector<bool> visit; visit.assign(N+1, false);
	for (int n = 0; n < N-1; n++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	if (dfs(arr, visit, 1, 0) % 2 == 0) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}

	return 0;
}
