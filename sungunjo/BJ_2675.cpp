#include <iostream>
using namespace std;

#define STR_MAX 20

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int R;
		char S[STR_MAX + 1];
		scanf("%d %s", &R, S);

		for (int i = 0; S[i] != '\0'; i++) {
			for (int r = 0; r < R; r++) {
				printf("%c", S[i]);
			}
		}

		printf("\n");
	}
}