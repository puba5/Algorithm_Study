#include <iostream>

using namespace std;


//백준 10797번 10부제
// 간단한 구현 문제

int main(){

    int n;
    cin >> n;
    int ans = 0;

    for(int i=0;i<5;i++){
        int carNum;
        cin >> carNum;
        if(n==carNum)
            ans++;
    }
    cout << ans;


    return 0;

}
