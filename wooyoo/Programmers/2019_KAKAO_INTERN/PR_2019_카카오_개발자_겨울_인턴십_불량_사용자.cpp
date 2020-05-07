#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// 2019_카카오_개발자_겨울_인턴십_불량_사용자
// 그냥 브루트 포스로 모든 경우의 수 때려박았다.
// 어차피 크기가 8..

vector<vector<string>> answer_list;

void bruteforce(vector<string> user_id, vector<string> banned_id, int ban_str, vector<int> checked,
                vector<string> ban_list) {

    // cout << ban_str << endl;

    if (ban_list.size() == banned_id.size()) {
        sort(ban_list.begin(), ban_list.end());
        answer_list.push_back(ban_list);
        return;
    }
    //cout << 1;
    if (ban_str >= banned_id.size()) {
        return;
    }
    //cout << 2;
    string ban_check = banned_id[ban_str];
    //cout << 3;
    for (int i = 0; i < user_id.size(); i++) {
        if (ban_check.size() == user_id[i].size() && checked[i] == 0) {
            //cout << 4;
            bool same = true;
            for (int j = 0; j < ban_check.size(); j++) {
                if (ban_check[j] != '*' && ban_check[j] != user_id[i][j]) {
                    same = false;
                    break;
                }
            }
            //cout << 5;
            if (same) {
                //  cout << 6;
                checked[i] = 1;
                vector<string> tmp = ban_list;
                tmp.push_back(user_id[i]);
                bruteforce(user_id, banned_id, ban_str + 1, checked, tmp);
                checked[i] = 0;
            }
        }
    }

}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<int> checked(user_id.size());
    vector<string> ban_list;
    bruteforce((user_id), banned_id, 0, checked, ban_list);
    answer = answer_list.size();
//    for(auto i:answer_list){
//        for(auto j:i){
//            cout << j << ' ';
//        }
//        cout << endl;
//    }
    sort(answer_list.begin(),answer_list.end());
    for (int i = 0; i < answer_list.size() - 1; i++) {
        if (answer_list[i] == answer_list[i + 1])
            answer--;
    }
    return answer;
}
