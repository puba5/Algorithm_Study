#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;


//백준 1049번 기타줄

int main() {


    int n, m;
    cin >> n >> m;

    int minSetVal = 1000;
    int minSingleVal = 1000;
    for (int i = 0; i < m; i++) {
        int setVal, singleVal;
        cin >> setVal >> singleVal;
        minSetVal = min(minSetVal, setVal);
        minSingleVal = min(minSingleVal, singleVal);
    }

    if (minSingleVal * 6 < minSetVal) {
        cout << n * minSingleVal;
    } else if ((n % 6) * minSingleVal > minSetVal) {
        int answer = (n / 6) * minSetVal;
        if (n % 6 != 0) {
            answer += minSetVal;
        }
        cout << answer;
    } else {
        cout << (n / 6) * minSetVal + (n % 6) * minSingleVal;
    }
    return 0;

}
