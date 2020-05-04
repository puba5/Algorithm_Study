#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;


// Trie 자료구조를 사용
// 프로그래머즈_2020_KAKAO_BLIND_RECRUITMENT_가사_검색

// 이 문제 시간 효율성이 좀 빡빡해서
// 인자를 insert나 check를 string 전체로 잡았는데 시간 초과
// 저장하기 위해 배열을 사용했는데 시간 초과
// 2020때 아쉽게 못 풀었다고 생각했는데 아쉽게가 아니라 절대 못풀었을듯...ㅋㅋㅋ..ㅠㅠ 

using namespace std;

#define ALPHA 26

// Trie 생성
class Trie {
private:
    bool is_word;
    Trie *next_alpha[ALPHA];
    map<int, int> child_len;
public:
    //unordered_map<int, int> child_len;
    // child_len을 사용하면 문제가 발생한다.
    //int child_len[10001];

    Trie() {
        is_word = false;
        fill(next_alpha, next_alpha + ALPHA, nullptr);
//        for (int i = 0; i < ALPHA; i++) {
//            next_alpha[i] = nullptr;
//        }
    }

    ~Trie() {
        for (int i = 0; i < ALPHA; i++) {
            if (next_alpha[i]) {
                delete (next_alpha[i]);
            }
        }
    }

    // Trie에 단어 추가
    void insert(const char *s, int str_len) {
        if (str_len == 0) {
            is_word = true;
            return;
        }
        child_len[str_len]++;

        int word_num = s[0] - 'a';
        if (!next_alpha[word_num]) {
            next_alpha[word_num] = new Trie();
        }
        next_alpha[word_num]->insert(s + 1, str_len - 1);
    }

    // Trie에서 단어 체크
    // 함수의 인자를 string과 시작하는 string index로 했었는데 시간초과가 난다..
    int check(const char *s, int str_len) {
        if (str_len == 0) {
            return is_word;
        }
        int sum = 0;
        if (s[0] == '?') {
            sum = child_len[str_len];
        } else {
            int word_num = s[0] - 'a';
            if (next_alpha[word_num]) {
                sum = next_alpha[word_num]->check(s + 1, str_len - 1);
            }
        }
        return sum;
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie *root = new Trie;
    Trie *r_root = new Trie;
    for (auto i:words) {
        root->insert(&i[0], i.size());
        reverse(i.begin(), i.end());
        r_root->insert(&i[0], i.size());
    }
    for (auto i:queries) {
        if (i[0] != '?') {
            answer.push_back(root->check(&i[0], i.size()));
        } else {
            reverse(i.begin(), i.end());
            answer.push_back(r_root->check(&i[0], i.size()));
        }
    }
    return answer;
}
