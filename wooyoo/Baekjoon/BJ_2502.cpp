#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <string>

using namespace std;


// 백준 2502번 떡 먹는 호랑이
// 피보나치의 규칙을 생각하면 된다.
// 1일 a 2일 b라고 할때 3일은 a+b, 4일은 2a+3b, 5일은 3a+5b처럼 a,b의 계수도 피보나치로 올라간다.

int fibo[31];

int main(void) {


	int d, k;
	cin >> d >> k;

	fibo[0] = 1;
	fibo[1] = 1;
	fibo[2] = 1;
	
	for (int i = 3; i <= 30; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
//		cout << fibo[i] << endl;
	}


	int A = fibo[d - 2];
	int B = fibo[d - 1];
	for (int i = 1; i*A <= k; i++) {
		for (int j = 1; i*A + j * B <= k; j++) {
			if (i*A + j * B == k) {
				cout << i << endl << j;
				return 0;
			}
		}
	}
	return 0;
}
