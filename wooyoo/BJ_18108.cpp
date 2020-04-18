#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>


using namespace std;
// 백준 18108번 1998년생인 내가 태국에서는 2541년생?!
//

int main() {

    int n;
    cin >> n;
    int gap = 2541 - 1998;
    cout << n - gap;
    return 0;
}
