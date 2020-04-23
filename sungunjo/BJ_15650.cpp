#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define CHECK_AND_CONTINUE(a) if (a) { continue; }

void print(const vector<int> &num) {
    for (int i = 0; i < num.size(); i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}

void go(vector<int> &picked, vector<bool> &check, int index, int start, int N, int M) {
    if (index == M) {
        print(picked);
        return;
    }

    for (int i = start; i <= N; i++) {
        CHECK_AND_CONTINUE(check[i] == true)

        check[i] = true;
        picked[index] = i;
        go(picked, check, index + 1, i + 1, N, M);
        check[i] = false;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> picked(M);
    vector<bool> check(N + 1, false);

    go(picked, check, 0, 1, N, M);

    return 0;
}