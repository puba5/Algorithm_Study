#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>


using namespace std;
// 백준 4504번 배수찾기
// 그냥 구현

int main() {
	
	int n;
	cin >> n;
	while (1) {
		int tmp;
		cin >> tmp;
		if (tmp == 0)
			return 0;
		if (tmp%n == 0) {
			cout << tmp<<" is a multiple of "<<n<<"." << endl;
		}
		else {
			cout << tmp << " is NOT a multiple of " << n << "." << endl;
		}
	}

	return 0;
}
