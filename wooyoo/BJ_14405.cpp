#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <string>

using namespace std;


// 백준 14405번 피카츄
// 쉬운 구현 문제
// 생각하기 귀찮아서 하드코딩함;;ㅋㅋ

int main(void) {

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if(s[i]=='p'){
			if (i + 1 < s.size() && s[i + 1] == 'i') {
				i += 1;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
		else if (s[i] == 'k') {
			if (i + 1 < s.size() && s[i + 1] == 'a') {
				i += 1;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
		else if (s[i]=='c') {
			if (i + 1 < s.size() && s[i + 1] == 'h'&&i + 2 < s.size() && s[i + 2] == 'u') {
				i += 2;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}
