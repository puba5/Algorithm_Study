#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void copy(vector<int> &src, vector<int> &dest, int start, int len) {
    for (int i = start; i < start + len; i++) {
        dest[i - start] = src[i];
    }
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++) {
        int start = commands[i][0] - 1;
        int len = commands[i][1] - start;
        vector<int> tmp(len);
        
        copy(array, tmp, start, len);
        
        sort(tmp.begin(), tmp.end());
        
        answer.push_back(tmp[commands[i][2] - 1]);
    }
    return answer;
}