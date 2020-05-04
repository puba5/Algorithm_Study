#include <vector>
#include <queue>
#include <utility>
#include <stdlib.h>
#include <iostream>

// 프로그래머스 2017 카카오코드 예선 카카오 프렌즈 컬러링북

using namespace std;

int up[] = {0, 0, 1, -1};
int dn[] = {1, -1, 0, 0};
int pass[101][101];

int bfs(int m, int n, int x, int y, vector<vector<int>> picture) {

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    pass[x][y] = 1;
    int ground = 0;
    while (!q.empty()) {
        ground++;
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_x = now_x + up[i];
            int new_y = now_y + dn[i];
            if (new_x >= 0 && new_y >= 0 && new_x < m && new_y < n) {
                if (pass[new_x][new_y] == 0 && picture[now_x][now_y] == picture[new_x][new_y]) {
                    pass[new_x][new_y] = 1;
                    q.push(make_pair(new_x, new_y));
                }
            }
        }
    }
    return ground;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pass[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pass[i][j] == 0 && picture[i][j] != 0) {
                max_size_of_one_area = max(max_size_of_one_area, bfs(m, n, i, j, picture));
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}
