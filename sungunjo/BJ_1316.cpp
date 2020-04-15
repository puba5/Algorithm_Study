#include <iostream>
#include <unordered_set>
using namespace std;

#define MAX_WORD_SIZE 100

int main() {
	int N;
	int cnt = 0;

	scanf("%d", &N); 

	for (int n = 0; n < N; n++) {
		char word[MAX_WORD_SIZE + 1];
		unordered_set<char> s;
		char prev_char;
		bool isGroupWord = true;

		scanf("%s", word);

		prev_char = word[0];
		for (int i = 1; word[i] != '\0'; i++) {
			if (prev_char != word[i]) {
				if (s.find(word[i]) != s.end()) {
					isGroupWord = false;
					break;
				}
				s.insert(prev_char);
				prev_char = word[i];
			}
		}

		if (isGroupWord == true) {
			cnt += 1;
		}
	}

	printf("%d\n", cnt);

	return 0;
}