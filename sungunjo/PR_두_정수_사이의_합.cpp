#include <string>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

long long solution(int a, int b) {
    long long answer = 0;
    
    if (a > b) {
        swap(a, b);
    }
    
    for (int i = a; i <= b; i++) {
        answer += i;
    }
    
    return answer;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%lld\n", solution(a, b));
}