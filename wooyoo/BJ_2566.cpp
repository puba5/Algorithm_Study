#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>


using namespace std;
// 백준 2566번 최댓값


int main() {

    int x, y;
    int maxNum = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int tmp;
            cin >> tmp;
            if (maxNum < tmp) {
                maxNum = tmp;
                x = i;
                y = j;
            }
        }
    }
    cout << maxNum << endl << x+1 << ' ' << y+1;
    return 0;
}
