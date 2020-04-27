#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

#define MOD 1000000007

using namespace std;


// 백준 4458번 첫 글자를 대문자로
// DP문제
// 뒤에 3개가 나올 경우 그것을 문자로 바꿨을때의 경우를 더한다.

int dp[1001];

int main() {

    string s;
    cin >> s;

    for (int i = s.size(); i >= 0; i--) {
        int alpha[26] = {0};
        dp[i] = 1;
        for (int j = i; j < s.size(); j++) {
            alpha[s[j] - 'a']++;
            if (alpha[s[j] - 'a'] == 3) {
                dp[i] += dp[j + 1];
                dp[i] %= MOD;
            }
        }
    }
    cout << (dp[0] - 1) % MOD;

    return 0;

}
