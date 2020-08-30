// 백준 3020 개똥벌레

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int oddLength[500001];
int evenLength[500001];

int main(void)
{

    int N, H;
    cin >> N >> H;

    vector<int> oddStone;
    vector<int> evenStone;

    for (int i = 0; i < N; i++)
    {
        int stoneLength;
        cin >> stoneLength;
        if (i % 2 == 0)
        {
            oddStone.push_back(stoneLength);
        }
        else if (i % 2 == 1)
        {
            evenStone.push_back(stoneLength);
        }
    }

    // 정렬
    sort(oddStone.begin(), oddStone.end());
    sort(evenStone.begin(), evenStone.end());

    // 정렬 후 길이 측정
    for (auto i : oddStone)
    {
        oddLength[i]++;
    }
    for (auto i : evenStone)
    {
        evenLength[i]++;
    }
    for (int i = H - 1; i >= 1; i--)
    {
        oddLength[i] += oddLength[i + 1];
        evenLength[i] += evenLength[i + 1];
    }

    int minLength = N;
    for (int i = 1; i <= H; i++)
    {
        cout << i << " " << oddLength[i] << " " << evenLength[H - i + 1] << endl;
        if (oddLength[i] + evenLength[H - i + 1] < minLength)
        {
            minLength = oddLength[i] + evenLength[H - i + 1];
        }
    }

    int answer = 0;

    for (int i = 1; i <= H; i++)
    {
        if (oddLength[i] + evenLength[H - i + 1] == minLength)
        {
            answer++;
        }
    }
    cout << minLength << ' ' << answer;
    return 0;
}