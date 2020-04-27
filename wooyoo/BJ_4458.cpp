#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;


//백준 4458번 첫 글자를 대문자로

int main() {

    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        if (s[0] >= 'a' && s[0] <= 'z') {
            s[0] += 'A' - 'a';
        }
        cout << s << endl;
    }
    return 0;

}