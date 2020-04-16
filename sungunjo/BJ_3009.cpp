#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s_x, s_y;

	for (int i = 0; i < 3; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		if (s_x.empty() == false) {
			if (s_x.top() == x) {
				s_x.pop();
			} else {
				s_x.push(x);
			}
		} else {
			s_x.push(x);
		}

		if (s_y.empty() == false) {
			if (s_y.top() == y) {
				s_y.pop();
			} else {
				s_y.push(y);
			}
		} else {
			s_y.push(y);
		}
	}

	if (s_x.size() == 3) {
		s_x.pop();
	}

	if (s_y.size() == 3) {
		s_y.pop();
	}

	printf("%d %d\n", s_x.top(), s_y.top());
	return 0;
}