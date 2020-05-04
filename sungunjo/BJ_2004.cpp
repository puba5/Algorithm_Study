#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;


// 1~n 범위에서 c 의 배수들의 배수가 각각 몇개씩 존재하는지 카운트
unsigned long long count(int n, int c) {
	unsigned long long cnt = 0;

	for (unsigned long long i = c; i <= (unsigned long long) n; i *= (unsigned long long) c) {
		// n 보다 작거나 같은 i 의 배수 몇개인지 구해서 더해줌
		cnt += (unsigned long long) ((unsigned long long) n / i);
	}
	return cnt;
}

unsigned long long solution(int n, int m) {
	// n! 의 2 개수 - (n-m)! 의 2 개수 - m! 의 2 개수
	unsigned long long two = count(n, 2) - count(n - m, 2) - count(m, 2);
	unsigned long long five = count(n, 5) - count(n - m, 5) - count(m, 5);

	return min(two, five);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	cout << solution(n, m) << "\n";

	return 0;
}