#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 프로그래머즈 2019 카카오 개발자 겨울 인턴십 크레인 인형뽑기 게임
// 간단한 구현 문제


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int arr_size = board.size();

    stack<int> bucket;

    for (int i = 0; i < moves.size(); i++) {

        int column = moves[i] - 1;

        for (int j = 0; j < arr_size; j++) {

            int doll = board[j][column];


            if (doll != 0) {
                cout << doll << endl;
                if (!bucket.empty() && bucket.top() == doll) {
                    bucket.pop();
                    answer++;
                } else {
                    bucket.push(doll);
                }

                board[j][column] = 0;
                break;
            }
        }

    }


    return answer * 2;
}
