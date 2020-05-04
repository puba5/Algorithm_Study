#include <iostream>

using namespace std;


//백준 14681번 사분면 고르
// 간단한 구현 문제

int main() {

    int x, y;
    cin >> x >> y;

    int answer;
    if (x >= 0) {
        if (y >= 0) {
            answer = 1;
        } else {
            answer = 4;
        }
    } else {
        if (y < 0) {
            answer = 3;
        } else {
            answer = 2;
        }
    }
    cout << answer;


    return 0;

}
