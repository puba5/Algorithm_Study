#include <string>
#include <iostream>
using namespace std;

int countP(const string &str) {
    int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if ((str[i] == 'p') ||
            (str[i] == 'P')) {
            cnt += 1;
        }
    }
    
    return cnt;
}

int countY(const string &str) {
    int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if ((str[i] == 'y') ||
            (str[i] == 'Y')) {
            cnt += 1;
        }
    }
    
    return cnt;
}

bool solution(string s)
{
    bool answer = true;

    if (countP(s) != countY(s)) {
        answer = false;
    }

    return answer;
}