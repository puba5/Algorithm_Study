#include <stdio.h>

int main() {
	int N;
	char pattern[55];
	scanf("%d %s", &N, pattern);
	for (int i = 1; i < N; i++) {
		char tmp_str[55];
		scanf("%s", tmp_str);

		int k = 0;
		while (pattern[k] != '\0') {
			if ((pattern[k] != tmp_str[k]) && (pattern[k] != '?')){
				pattern[k] = '?';
			}
			k++;
		}
	}

	printf("%s\n", pattern);

	return 0;
}
