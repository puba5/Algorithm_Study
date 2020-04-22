#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;


//백준 1755번 숫자놀이

int main() {


    int str, end;
    cin >> str >> end;
    vector<pair<string, int>> v;
    for (int i = str; i <= end; i++) {
        string tmp = "";
        if (i / 10 != 0) {
            int num = i / 10;
            switch (num) {
                case 1:
                    tmp += "one";
                case 2:
                    tmp += "two";
                case 3:
                    tmp += "three";
                case 4:
                    tmp += "four";
                case 5:
                    tmp += "five";
                case 6:
                    tmp += "six";
                case 7:
                    tmp += "seven";
                case 8:
                    tmp += "eight";
                case 9:
                    tmp += "nine";
                case 0:
                    tmp += "zero";
                default:
                    tmp += "";
            }
            tmp += " ";
        }
        int num = i % 10;
        switch (num) {
            case 1:
                tmp += "one";
            case 2:
                tmp += "two";
            case 3:
                tmp += "three";
            case 4:
                tmp += "four";
            case 5:
                tmp += "five";
            case 6:
                tmp += "six";
            case 7:
                tmp += "seven";
            case 8:
                tmp += "eight";
            case 9:
                tmp += "nine";
            case 0:
                tmp += "zero";

        }
        //cout << tmp << endl;
        v.push_back(make_pair(tmp, i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].second;
        if (i % 10 == 9) {
            cout << '\n';
        } else {
            cout << ' ';
        }
    }
    return 0;

}
