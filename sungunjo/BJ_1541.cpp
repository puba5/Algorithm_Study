#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

typedef enum _op {
	OP_PLUS = -2,
	OP_MINUS = -1
} Op;

void calcPlus(stack<int> &s) {
	while (s.size() >= 3) {
		int a = s.top(); s.pop();
		if (s.top() == OP_PLUS) {
			s.pop();
			int b = s.top(); s.pop();
			s.push(a + b);
		} else {
			s.push(a);
			return;
		}
	}
}

int calcMinus(stack<int> &s) {
	int sum = 0;
	while (s.size() >= 3) {
		sum += s.top(); s.pop(); s.pop();
	}
	
	return s.top() - sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string exp;
	cin >> exp;
	
	stack<int> s;
	int num = 0;
	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == '+') {
			s.push(num);
			s.push(OP_PLUS);
			num = 0;
		} else if (exp[i] == '-') {
			s.push(num);
			calcPlus(s);
			s.push(OP_MINUS);
			num = 0;
		} else {
			num = (num * 10) + exp[i] - '0';
		}
	}
	s.push(num);
	calcPlus(s);
	cout << calcMinus(s) << "\n";

	return 0;
}