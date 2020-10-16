#include <iostream>
using namespace std;

int N, S;
int arr[25];

int dfs(int index, bool select, int sum, int count) {
	int ret = 0;

	if (select) {
		sum += arr[index];
		count++;
	}

	if (index == N - 1) {
		if (sum == S && count > 0) {
			ret = 1;
		} else {
			ret = 0;
		}
	} else {
		ret = dfs(index+1, true, sum, count) + dfs(index+1, false, sum, count);
	}

	return ret;
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int ans = dfs(0, true, 0, 0) + dfs(0, false, 0, 0);

	cout << ans << endl;
}
