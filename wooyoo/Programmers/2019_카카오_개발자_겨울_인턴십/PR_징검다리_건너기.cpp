#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;


// 2019_카카오_개발자_겨울_인턴십_징검다리_건너기
// 시간을 위해 이분 탐색 사용

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 200000000;
    int str = 0;
    int end = 200000000;

    while (str <= end) {
        int mid = (str + end) / 2;
        // 없는 돌의 연속된 개수 
        int gap = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] < mid) {
                gap++;
                // mid 번째 친구가 돌다리를 건널 때
                // mid-1 번째 친구까지 다 건너서 없는 연속된 돌 개수를 세준다.
                // 그 차이가 k이상이면 mid번째 친구는 못 건너고, 이분 탐색은 그 아래 값으로 수정 
                if (gap >= k) {
                    end = mid - 1;
                    break;
                }
            } else {
                gap = 0;
            }
        }
        // 만약 모두가 잘 건널 수 있다면 
        if (end != mid - 1) {
            answer =  mid;
            str = mid + 1;
        }
    }

    return answer;
}
