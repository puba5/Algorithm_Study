#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<vector>


using namespace std;
// 백준 1655번 가운데를 말해요
// 이분 탐색을 이용하여 가운데 값을 찾고 계속 값을 벡터에 넣는 문제이다.
// 입출력 처리 안해주면 시간 초과나서 짜증나는 문제

vector<int> nums;

int finding(int num) {
	int str = 0;
	int end = nums.size()-1;
	int mid = (str+end)/2;

	while (str <= end) {
		mid = (str + end)/2;
		if (nums[mid] < num) {
			str = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	if (nums[mid] < num)
		mid++;
	return mid;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	//외친 수들을 저장할 vector
	nums.reserve(n+1);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		if (i == 0) {
			nums.push_back(tmp);
		}
		else {
			int wit = finding(tmp);
			nums.insert(nums.begin() + wit, tmp);
		}
		cout << nums[(nums.size()-1)/2] << '\n';
	}


	return 0;
}
