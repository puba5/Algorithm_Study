#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<vector>


using namespace std;
// 백준 2512번 예산
// 이분 탐색을 이용하여 예산을 찾는 문제이다.


int main() {

	long long n;
	cin >> n;

	vector<long long> budgets;

	long long totalBuget;
	long long end = 0;
	for (long long i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		budgets.push_back(tmp);
		end = max(end, tmp);
	}
	
	cin >> totalBuget;

	long long str = 0;
	long long mid;
	long long ans = 0;
	long long Bsum;

	while (str <= end) {
		Bsum = 0;
		mid = (str + end) / 2;
		for (long long i : budgets) {
			if (i >= mid) {
				Bsum += mid;
			}
			else {
				Bsum += i;
			}
		}
		if (Bsum <= totalBuget) {
			ans = max(ans, mid);
			str = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << ans;

	return 0;
}
