#include <iostream>
using namespace std;

#define MAX_WORD_SIZE 100

int main() {
	char word[MAX_WORD_SIZE + 1];
	int cnt = 0;

	scanf("%s", word);

	for (int i = 0; word[i] != '\0'; i++) {
		if (word[i] == 'c') {
			if ((i < MAX_WORD_SIZE) && 
				((word[i + 1] == '-') || (word[i + 1] == '='))) {
				i += 1;
			}
		} else if (word[i] == 'd') {
			if ((i < MAX_WORD_SIZE - 1) &&
				((word[i + 1] == 'z') && (word[i + 2] == '='))) {
				i += 2;
			} else if ((i < MAX_WORD_SIZE) && 
				(word[i + 1] == '-')){
				i += 1;
			}
		} else if (word[i] == 'l') {
			if ((i < MAX_WORD_SIZE) && 
				(word[i + 1] == 'j')) {
				i += 1;
			}
		} else if (word[i] == 'n') {
			if ((i < MAX_WORD_SIZE) && 
				(word[i + 1] == 'j')) {
				i += 1;
			}
		} else if (word[i] == 's') {
			if ((i < MAX_WORD_SIZE) && 
				(word[i + 1] == '=')) {
				i += 1;
			}
		} else if (word[i] == 'z') {
			if ((i < MAX_WORD_SIZE) && 
				(word[i + 1] == '=')) {
				i += 1;
			}
		}
		
		cnt += 1;
	}

	printf("%d\n", cnt);

	return 0;
}