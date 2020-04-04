#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>


using namespace std;
// 백준 1138번 한 줄로 서기
// 알파벳 개수 세서 개수의 차이만큼 계산하면 된다.

int main() {

    int n;
    int leftCnt[11];
    int ans[11];
    cin >> n;
    //왼쪽 몇명있는지 인원수 받는다.
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        ans[i] = 0;
        leftCnt[i] = tmp;
    }
    //첫번째 사람은 제일 작으므로 "왼쪽 사람 몇명 = 자기 위치"
    ans[leftCnt[0]] = 1;

    for (int i = 2; i <= n; i++) {
        int loc = leftCnt[i-1];
        for (int j = 0; j <= loc; j++) {
            if (ans[j] != 0 && ans[j] < i)
                loc++;
        }
        ans[loc] = i;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i]<< ' ';
    }

    return 0;
}
