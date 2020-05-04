#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

// 프로그래머즈 2019 KAKAO BLIND RECRUITMENT 실패율

vector<int> solution(int N, vector<int> stages) {
    // 정답
    vector<int> answer;
    // 스테이지 실패자 수
    vector<int> cnt(N + 2);
    // 실패율
    vector<pair<float, int>> ans(N);
    int total_user = stages.size();

    for (int i = 0; i < stages.size(); i++) {
        cnt[stages[i]]++;
    }
    for (int i = 0; i < N; i++) {
        ans[i].second = i + 1;
    }
    for (int i = 0; i < N; i++) {
        // cout << cnt[i + 1] << ' ';
        if (total_user == 0) {
            ans[i].first = 0.0f;
        } else {
            ans[i].first = (-1) * (float(cnt[i + 1]) / float(total_user));
        }
        total_user -= cnt[i + 1];
    }
    sort(ans.begin(), ans.end());

    for (int i = 0; i < N; i++) {
        answer.push_back(ans[i].second);
    }
    return answer;
}
