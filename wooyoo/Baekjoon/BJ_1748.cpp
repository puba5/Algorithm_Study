#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

// 문제를 수학적으로 접근할 예정

int main()
{
    int n;

    cin >> n;

    //원래 입력받은 숫자
    int ori = n;
    //정답 기록
    long long ans = 0;
    //자리수 기록
    int cnt = 1;
    //자리수 실제 숫자로
    int num = 1;
    while (n > 0)
    {
        //만약 가장 높은 자리수가 아니라면 ans에 다 계산해서 저장
        if (n / 10 != 0)
        {
            ans += num * 9 * cnt;
        }
        else
        {
            ans += cnt * (ori - num + 1);
        }
        n /= 10;
        num *= 10;
        cnt++;
    }
    cout << ans;
    return 0;
}
