#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;


// 2019_카카오_개발자_겨울_인턴십_징검다리_건너기
// 시간을 위해 이분 탐색 사용

int gidung[1001][1001];
int bo[1001][1001];


// 얘가 정상적으로 존재하는지 확인
bool check(int x, int y, int type) {
    if (x < 0 || y < 0 || x >= 1000 || y >= 1000) {
        return true;
    }
    if (type == 0) {
        if (gidung[x][y] == 0)
            return true;
        // 기둥일때
        if (y == 0) {
            return true;
        }
        if (gidung[x][y - 1] == 1) {
            return true;
        }
        if (bo[x][y] == 1) {
            return true;
        }
        if (bo[x - 1][y] == 1 && x - 1 >= 0) {
            return true;
        }
    } else if (type == 1) {
        if (bo[x][y] == 0) {
            return true;
        }
        // 보일때
        if (gidung[x][y - 1] == 1 && y - 1 >= 0) {
            return true;
        }
        if (gidung[x + 1][y - 1] == 1 && y - 1 >= 0) {
            return true;
        }
        if (bo[x - 1][y] == 1 && bo[x + 1][y] == 1 && x - 1 >= 0 && x + 1 <= 1000) {
            return true;
        }
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        //추가
        if (b == 1) {
            //기둥일때
            if (a == 0) {
                if (y == 0) {
                    gidung[x][y] = 1;
                } else if (gidung[x][y - 1] == 1) {
                    gidung[x][y] = 1;
                } else if (x - 1 >= 0 && bo[x - 1][y] == 1) {
                    gidung[x][y] = 1;
                } else if (bo[x][y] == 1) {
                    gidung[x][y] = 1;
                }
            } else { // 보일때
                if ((y - 1 >= 0 && gidung[x][y - 1] == 1) || (y - 1 >= 0 && gidung[x + 1][y - 1] == 1)) {
                    bo[x][y] = 1;
                } else if (x - 1 >= 0 && bo[x - 1][y] == 1 && x + 1 <= 1000 && bo[x + 1][y] == 1) {
                    bo[x][y] = 1;
                }
            }
        } else {//삭제
            // 기둥일때
            if (a == 0) {
                if (gidung[x][y + 1] == 1) {
                    if (bo[x][y + 1] == 1 && x - 1 > 0 && bo[x - 1][y + 1] == 1) {
                        gidung[x][y] = 0;
                    }
                } else if (bo[x][y + 1] == 1 && gidung[x + 1][y] != 1) {
                    if (bo[x + 1][y + 1] == 1 && x - 1 > 0 && bo[x - 1][y + 1] == 1) {
                        gidung[x][y] = 0;
                    }
                } else if (x - 1 >= 0 && bo[x - 1][y + 1] && gidung[x - 1][y] != 1) {
                    if (x - 2 >= 0 && bo[x - 2][y + 1] == 1 && bo[x][y + 1] == 1) {
                        gidung[x][y] = 0;
                    }
                } else {
                    gidung[x][y] = 0;
                }
            } else {//보일때
                if (gidung[x][y] == 1 && bo[x - 1][y] == 0 && gidung[x][y - 1] == 0) {

                } else if (gidung[x + 1][y] == 1 && bo[x + 1][y] == 0 && gidung[x + 1][y - 1] == 0) {

                } else if (bo[x + 1][y] == 1 && gidung[x + 1][y - 1] == 0 && gidung[x + 2][y - 1] == 0) {

                } else if (bo[x - 1][y] == 1 && gidung[x][y - 1] == 0 && gidung[x - 1][y - 1] == 0) {

                } else {
                    bo[x][y] = 0;
                }
            }
            // 새로운 방법
//            if (a == 0) {
//                bool is_okay = true;
//                gidung[x][y] = 0;
//                is_okay = check(x, y + 1, 0);
//                if (!is_okay) {
//                    gidung[x][y] = 1;
//                }
//                is_okay = check(x, y + 1, 1);
//                if (!is_okay) {
//                    gidung[x][y] = 1;
//                }
//                is_okay = check(x - 1, y + 1, 1);
//                if (!is_okay) {
//                    gidung[x][y] = 1;
//                }
//            } else {
//                bool is_okay = true;
//                bo[x][y] = 0;
//                is_okay = check(x, y, 0);
//                if (!is_okay) {
//                    gidung[x][y] = 1;
//                }
//                is_okay = check(x + 1, y, 0);
//                if (!is_okay) {
//                    gidung[x][y] = 1;
//                }
//                is_okay = check(x - 1, y, 1);
//                if (!is_okay) {
//                    gidung[x][y] = 1;
//                }
//                is_okay = check(x + 1, y, 1);
//                if (!is_okay) {
//                    bo[x][y] = 1;
//                }
//            }
        }
    }
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (gidung[i][j] == 1) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(0);
                answer.push_back(tmp);
            }
            if (bo[i][j] == 1) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(1);
                answer.push_back(tmp);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
