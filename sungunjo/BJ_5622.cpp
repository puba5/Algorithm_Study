#include <iostream>

#define MAX_PHONE_NUM 15

int numStrToSec(char c) {
	switch(c) {
		case 'A': case 'B': case 'C':
			return 3; break;
		case 'D': case 'E': case 'F':
			return 4; break;
		case 'G': case 'H': case 'I':
			return 5; break;
		case 'J': case 'K': case 'L':
			return 6; break;
		case 'M': case 'N': case 'O':
			return 7; break;
		case 'P': case 'Q': case 'R': case 'S':
			return 8; break;
		case 'T': case 'U': case 'V':
			return 9; break;
		case 'W': case 'X': case 'Y': case 'Z':
			return 10; break;
	}

	return -1;
}

int main() {
	char phone_num_str[MAX_PHONE_NUM + 1];
	scanf("%s", phone_num_str);

	int sum = 0;
	for (int i = 0; phone_num_str[i] != '\0'; i++) {
		sum += numStrToSec(phone_num_str[i]);
	}

	printf("%d\n", sum);

	return 0;
}