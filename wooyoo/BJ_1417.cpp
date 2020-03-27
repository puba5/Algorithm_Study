#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>


using namespace std;
// 백준 1417번 국회의원 선거
// 간단한 구현 문제이다.
// 배열의 크기가 1000이므로 1000*1000*1000해도 시간 2초 안넘어서 그냥 노가다로 한다.
// 국회의원 선호도를 위해 전역 배열 생성
int arr[1001];

int main() {
	
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++) {
		int tmp;
		cin >> arr[i+1];
	}
	int ans = 0;
	while (1) {
		int maxI = 1;
		for (int i = 1; i <= n; i++) {
			if (arr[i] >= arr[maxI]) {
				maxI = i;
			}
		}
		if (maxI == 1)
			break;
		else {
			arr[1]++;
			arr[maxI]--;
			ans++;
		}
	}
	cout << ans;

	return 0;
}
