#include <iostream>

using namespace std;


//백준 2798번 블랙잭
// 간단한 브루트포스 문제
int arr[100];
int answer = 0;

void check(int sum, int cnt, int index, int n, int m) {
    if (cnt == 0) {
        if (sum <= m) {
            answer = max(answer, sum);
        }
        return;
    }
    for (int i = index + 1; i < n; i++) {
        check(arr[i] + sum, cnt - 1, i, n, m);
    }

}


int main() {

    int n, m;
    cin >> n >> m;

    // 입력을 받는다
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    //
    for (int i = 0; i < n; i++) {
        check(arr[i], 2, i, n, m);
    }

    cout << answer;
    return 0;

}