#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int t = 1;
    for (int i = s.size() - 1; i > 0; i--) {
        answer += ((s[i] - '0') * t);
        t *= 10;
    }
    if (s[0] == '-') {
        answer *= (-1);
    } else if (s[0] != '+') {
        answer += ((s[0] - '0') * t);
    }
    return answer;
}