#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>


using namespace std;
// 백준 1919번 애너그램 만들기
// 알파벳 개수 세서 개수의 차이만큼 계산하면 된다.

int main() {
	
	int alpha[26];
	
	for (int i = 0; i < 26; i++) {
		alpha[i] = 0;
	}

	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.length(); i++) {
		int tmp = a[i] - 'a';
		alpha[tmp]++;
	}

	for (int i = 0; i < b.length(); i++) {
		int tmp = b[i] - 'a';
		alpha[tmp]--;
	}

	int ans = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] < 0) {
			ans -= alpha[i];
		}
		else if (alpha[i] > 0) {
			ans += alpha[i];
		}
	}
	
	cout << ans;
	
	return 0;
}
