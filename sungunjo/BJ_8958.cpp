#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		char str[85];
		scanf("%s", str);
		
		int sum = 0;
		int acc_score = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == 'O') {
				acc_score += 1;
			} else {
				acc_score = 0;
			}
			sum += acc_score;
		}

		printf("%d\n", sum);
	}

	return 0;
}