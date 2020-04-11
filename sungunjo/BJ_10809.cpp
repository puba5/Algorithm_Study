#include <iostream>
#include <vector>
using namespace std;

#define STR_MAX 100
#define ALPHABET_SIZE 26

int charToInt(char c) {
	return ((int) c - 'a');
}

int main() {
	char str[STR_MAX + 1];
	vector<int> alp_fst_pos(ALPHABET_SIZE, -1);
	
	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; i++) {
		int alpha_int = charToInt(str[i]);
		if (alp_fst_pos[alpha_int] != -1) {
			continue;
		}

		alp_fst_pos[alpha_int] = i;
	}

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		printf("%d ", alp_fst_pos[i]);
	}

	return 0;
}