#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;


// 2019_카카오_개발자_겨울_인턴십_호텔_방_배정
// 시간 문제 해결을 위해 유니온 파인드 쓰면 될 것 같다.
// 공간 문제 해결을 위해서는 맵 사용

using namespace std;

//vector<long long> parent;
map<long long, long long> parent;

long long find(long long room_number) {
    if (parent[room_number] == 0) {
        parent[room_number] = room_number + 1;
        return room_number;
    } else {
        long long empty_room = find(parent[room_number]);
        parent[room_number] = empty_room + 1;
        return empty_room;
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    
    for (auto i:room_number) {
        answer.push_back(find(i));
    }
    return answer;
}
