#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//백준 2581번 소수
//에라토스테네스의 체를 이용하여 푼다.
int prime[10001];

int main() {
    // 1은 소수가 아니란다..
    prime[1] = 1;
    for (int i = 2; i <= 5000; i++) {
        for (int j = 2; j * i <= 10000; j++) {
            // cout << i*j << ' ';
            prime[i * j] = 1;
        }
    }
    int str, end;
    cin >> str >> end;

    int minVal = 0;
    long long ans = 0;

    for (int i = str; i <= end; i++) {

        if (prime[i] == 0) {
            ans += i;
            if (minVal == 0) {
                minVal = i;
            }
        }
    }
    if (minVal == 0) {
        cout << -1;
    } else {
        cout << ans << endl << minVal;
    }

    return 0;

}
