#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>


using namespace std;

//가장 큰 부분 배열 문제이다.

int main() {

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		int arr[1000];
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			arr[i] = tmp;
		}
		int ans = arr[0];
		for (int i = 1; i < n; i++) {
			//전의 부분 값을 가져갈 것인지 아닌지 크기로 비교한다.
			if (arr[i - 1] + arr[i] > arr[i]) {
				arr[i] += arr[i - 1];
			}
			ans = max(arr[i], ans);
		}
		cout << ans << '\n';
	}
	return 0;
}
