#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if (B == C) {
		printf("-1\n");
	} else {
	    int x = A / (C - B)  + 1;
	    if (x < 0) {
		    printf("-1\n");
	    } else {
		    printf("%d\n", x);
	    }
    }
    
    return 0;
}
