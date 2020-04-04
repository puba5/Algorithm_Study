#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>


using namespace std;
// 백준 6463번 팩트
// 0은 2와 5를 곱할 때만 생기므로, 이 때만 따로 계산한다.
// 다룬 수일 경우 곱한 후 10으로 나눈 몫만을 저장하여 수의 범위를 초과하지 않도록 한다.

int main() {

    int num;
    while (cin >> num) {
        int two = 0;
        int five = 0;
        int zari = 1;
        for (int i = 1; i <= num; i++) {
            int number = i;
            while (number % 2 == 0 || number % 5 == 0) {
                if (number % 2 == 0) {
                    two++;
                    number /= 2;
                }
                if (number % 5 == 0) {
                    five++;
                    number /= 5;
                }
            }
            number %= 10;
            zari *= number;
            zari %= 10;
        }
        if (two > five) {
            int gap = two - five;
            while (gap--) {
                zari *= 2;
                zari %= 10;
            }
        } else if (five < two) {
            int gap = five - two;
            zari = 5;
        }
        int n = num;
        if (num < 10000) {
            cout << ' ';
        } else {
            cout << n / 10000;
            n %= 10000;
        }
        if (num < 1000) {
            cout << ' ';
        } else {
            cout << n / 1000;
            n %= 1000;
        }
        if (num < 100) {
            cout << ' ';
        } else {
            cout << n / 100;
            n %= 100;
        }
        if (num < 10) {
            cout << ' ';
        } else {
            cout << n / 10;
            n %= 10;
        }
        cout << n << " -> ";
        cout << zari << endl;

    }

    return 0;
}
