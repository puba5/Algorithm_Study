#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

#define SMALL_GWALHO 0
#define MIDDLE_GWALHO 1
#define BIG_GWALHO 2

bool solution(const string &line) {
	int line_size = line.size();
	stack<char> gwalho;

	for (int i = 0; i < line_size; i++) {
		if ((line[i] == '(') || (line[i] == '{') || (line[i] == '[')) {
			gwalho.push(line[i]);
		} else if (line[i] == ')') {
			if ((!gwalho.empty()) && (gwalho.top() == '(')) {
				gwalho.pop();
			} else {
				return false;
			}
		} else if (line[i] == '}') {
			if ((!gwalho.empty()) && (gwalho.top() == '{')) {
				gwalho.pop();
			} else {
				return false;
			}
		} else if (line[i] == ']') {
			if ((!gwalho.empty()) && (gwalho.top() == '[')) {
				gwalho.pop();
			} else {
				return false;
			}
		}
	}

	if (!gwalho.empty()) {
		return false;
	} else {
		return true;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	string line;
	while (true) {
		getline(cin, line);

		if (line == ".") {
			break;
		}

		if (solution(line) == true) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}

	return 0;
}