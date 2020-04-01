#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

// 백준 15663 N과 M (9)
// 경우의 수가 8! 밖에 안 나오므로 모든 경우의 수를 해보면 될 것 같다.
vector<vector<int>> answers;

void allCase(int m, vector<int> nums, vector<int> ans) {

    if (m == 0) {
        answers.push_back(ans);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != -1) {
            int tmp = nums[i];
            vector<int> tmpv = ans;
            tmpv.push_back(nums[i]);
            nums[i] = -1;
            allCase(m - 1, nums, tmpv);
            nums[i] = tmp;
        }
    }

}

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    sort(nums.begin(), nums.end());
    vector<int> ans;
    allCase(m, nums, ans);

    sort(answers.begin(), answers.end());

    for (int i = 0; i < answers.size(); i++) {
        if (i == 0 || answers[i] != answers[i - 1]) {
            for (int j = 0; j < answers[i].size(); j++) {

                cout << answers[i][j] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}
