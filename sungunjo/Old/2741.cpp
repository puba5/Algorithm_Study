#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    if (N % 2 == 0) {
        for (int n = 1; n <= N; n += 2) {
            printf("%d\n%d\n", n, n + 1);
        }
    } else {
        for (int n = 1; n <= N; n++) {
            printf("%d\n", n);
        }
    }
    return 0;
}
