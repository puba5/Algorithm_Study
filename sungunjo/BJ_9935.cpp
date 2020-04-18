#include <iostream>
#include <stack>
using namespace std;

#define STR_MAX 1000005
#define BOMB_MAX 1000005

typedef struct _bombState {
	char bomb_char;
	int bomb_index;

	_bombState(char _bomb_char, int _bomb_index): bomb_char(_bomb_char), bomb_index(_bomb_index) {};
} BombState;

void stackToStr(char *str, stack<BombState> &s, int &str_index) {
	int stack_str_len = s.size();
	while (!s.empty()) {
		str[str_index + s.size() - 1] = s.top().bomb_char; 
		s.pop();
	}

	str_index += stack_str_len;
}

int main() {
	char *input_str = new char[STR_MAX];
	char *bomb_str = new char[BOMB_MAX];
	char *ans_str = new char[STR_MAX];

	scanf("%s %s", input_str, bomb_str);

	stack<BombState> s;

	int input_index = 0;
	int bomb_index = 0;
	int ans_index = 0;
	while (input_str[input_index] != '\0') {
		if (input_str[input_index] == bomb_str[0]) {
			bomb_index = 1;
			s.push(BombState(input_str[input_index], bomb_index));
		} else if (input_str[input_index] == bomb_str[bomb_index]) {
			bomb_index += 1;
			s.push(BombState(input_str[input_index], bomb_index));
		} else {
			bomb_index = 0;
			stackToStr(ans_str, s, ans_index);
			ans_str[ans_index] = input_str[input_index];
			ans_index += 1;
		}

		if (bomb_str[bomb_index] == '\0') {
			for (; bomb_index > 0; bomb_index--) {
				s.pop();
			}
			if (!s.empty()) {
				bomb_index = s.top().bomb_index;
			}
		}
		input_index += 1;
	}

	stackToStr(ans_str, s, ans_index);

	if (ans_index == 0) {
		printf("FRULA\n");
	} else {
		printf("%s\n", ans_str);
	}

	return 0;
}