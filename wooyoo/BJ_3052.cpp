#include <iostream>

using namespace std;


//백준 3052번 나머지
// 간단한 구현 문제
int arr[42];

int main() {


    for (int i = 0; i < 10; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp % 42]++;
    }


    int answer = 0;
    for (int i = 0; i < 42; i++) {
        if (arr[i] != 0)
            answer++;
    }
    cout << answer;
    return 0;

}
