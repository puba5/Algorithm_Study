#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ALPHABET_SIZE 26
#define STRING_MAX 1000000

int charToIndex(char c) {
	if (('a' <= c) && (c <= 'z')) {
		return ((int) (c - 'a'));
	} else if (('A' <= c) && (c <= 'Z')) {
		return ((int) (c - 'A'));
	} else {
		return -1;
	}
}

char indexToChar(int i) {
	return ((char) (i + (int) 'A'));
}

int main() {
	char str[STRING_MAX];
	vector<int> alphabet_use_cnt(ALPHABET_SIZE, 0);
	char most_used_alphabet;
	int most_used_cnt = 0;
	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; i++) {
		alphabet_use_cnt[charToIndex(str[i])] += 1;
		int now_index = charToIndex(str[i]);
		if (alphabet_use_cnt[now_index] > most_used_cnt) {
			most_used_cnt = alphabet_use_cnt[now_index];
			most_used_alphabet = indexToChar(now_index);
		} else if (alphabet_use_cnt[now_index] == most_used_cnt) {
			if (most_used_alphabet != indexToChar(now_index)) {
				most_used_alphabet = '?';
			}
		}
	}

	printf("%c\n", most_used_alphabet);

	return 0;

}