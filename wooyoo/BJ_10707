#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

//간단한 구현 문제이다.

int main() {

	// X사 요금
	int a;
	// Y사 기본 요금
	int b;
	// Y사 기본 요금 상한량
	int c;
	// Y가 추가 요금
	int d;
	// JOI군 한달 수도 사용량
	int p;

	cin >> a >> b >> c >> d >> p;

	int Apay;
	Apay = a * p;
	int Bpay;
	if (p > c) {
		Bpay = b + (p - c)*d;
	}
	else {
		Bpay = b;
	}

	if (Apay > Bpay) {
		cout << Bpay;
	}
	else {
		cout << Apay;
	}

	return 0;
}
