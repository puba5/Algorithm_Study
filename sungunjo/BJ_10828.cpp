#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define N_MAX 10001
#define CMD_MAX 6

class Stack {
private:
	int m_top;
	int *m_s;
public:
	Stack() : m_top(-1) { this->m_s = new int[N_MAX]; };
	Stack(int s_size) : m_top(-1) { this->m_s = new int[s_size + 1]; };

	void push(int num);
	int pop();
	int size();
	bool empty();
	int top();
};

int main() {
	int N;
	scanf("%d", &N);

	Stack stack(N);

	for (int n = 0; n < N; n++) {
		char cmd[CMD_MAX];
		scanf("%s", cmd);

		if (strncmp(cmd, "push", CMD_MAX) == 0) {
			int num;
			scanf("%d", &num);

			stack.push(num);
		} else if (strncmp(cmd, "pop", CMD_MAX) == 0) {
			printf("%d\n", stack.pop());
		} else if (strncmp(cmd, "size", CMD_MAX) == 0) {
			printf("%d\n", stack.size());
		} else if (strncmp(cmd, "empty", CMD_MAX) == 0) {
			printf("%d\n", stack.empty());
		} else if (strncmp(cmd, "top", CMD_MAX) == 0) {
			printf("%d\n", stack.top());
		}

	}

	return 0;
}

void Stack::push(int num) {
	this->m_top += 1;
	this->m_s[this->m_top] = num;
}

int Stack::pop() {
	if (this->empty() == true) {
		return -1;
	} else {
		int poped = this->m_s[this->m_top];
		this->m_top -= 1;
		return poped;
	}
}

int Stack::size() {
	return (this->m_top + 1);
}

bool Stack::empty() {
	return ((this->m_top < 0) ? (true) : (false));
}

int Stack::top() {
	if (this->empty() == true) {
		return -1;
	} else {
		return this->m_s[this->m_top];
	}
}