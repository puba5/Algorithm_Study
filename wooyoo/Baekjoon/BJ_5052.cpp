#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

// 백준 5052 전화번호 목록

// Trie 자료구조를 사용

#define TrieNode 10

using namespace std;

class Trie {
private:
    bool finish;
    bool nextChild;
    Trie *next[TrieNode];

public:
    // trie 생성자
    Trie() {
        for (int i = 0; i < TrieNode; i++) {
            next[i] = nullptr;
        }
        finish = false;
        nextChild = false;
        //fill(next, next + TrieNode, nullptr);
    }

    ~Trie() {
        for (int i = 0; i < TrieNode; i++)
            if (next[i])
                delete next[i];
    }

    bool insert(const char *key) {
        // 문자열의 끝이라면
        if (*key == '\0') {
            finish = true;
            // 문자열이 종료되었는데 그 이후도 존재하면 일관성 X
            return !nextChild;
        }

        int nextKey = *key - '0';

        // 다음으로 가는 트라이가 없다면
        if (!next[nextKey])
            next[nextKey] = new Trie;

        nextChild = true;

        bool next_right = next[nextKey]->insert(key + 1);
        return !finish && next_right;
    }
};

int main() {

    // 테스트케이스 개수
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        // trie 생성
        Trie *A = new Trie;
        // 일관성
        bool constant = true;

        for (int i = 0; i < n; i++) {
            // 문자열을 trie에 넣으면서 일관성 확인
            char s[11];
            cin >> s;
            if (!(A->insert(s))) {
                constant = false;
            }
        }
        if (constant)
            cout << "YES\n";
        else
            cout << "NO\n";
        delete (A);
    }

    return 0;
}
