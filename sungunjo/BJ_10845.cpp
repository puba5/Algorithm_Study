#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_N 10001
#define MAX_CMD 6

class Queue {
private:
	int m_front;
	int m_back;
	int m_q[MAX_N];
public:
	Queue() : m_front(0), m_back(-1) {};

	void push(int i);
	int pop();
	int size();
	bool empty();
	int front();
	int back();
};

int main() {
	int N;
	scanf("%d", &N);

	Queue queue;

	for (int n = 0; n < N; n++) {
		char cmd[MAX_CMD];
		scanf("%s", cmd);

		if (strncmp(cmd, "push", MAX_CMD) == 0) {
			int num;
			scanf("%d", &num);
			queue.push(num);
		} else if (strncmp(cmd, "pop", MAX_CMD) == 0) {
			printf("%d\n", queue.pop());
		} else if (strncmp(cmd, "size", MAX_CMD) == 0) {
			printf("%d\n", queue.size());
		} else if (strncmp(cmd, "empty", MAX_CMD) == 0) {
			printf("%d\n", queue.empty());
		} else if (strncmp(cmd, "front", MAX_CMD) == 0) {
			printf("%d\n", queue.front());
		} else if (strncmp(cmd, "back", MAX_CMD) == 0) {
			printf("%d\n", queue.back());
		}
	}

	return 0;
}


void Queue::push(int i) {
	this->m_back += 1;
	this->m_q[this->m_back] = i;
}

int Queue::pop() {
	if (this->empty() == true) {
		return -1;
	} else {
		int poped = this->m_q[this->m_front];
		this->m_front += 1;
		return poped;
	}
}

int Queue::size() {
	return (this->m_back - this->m_front + 1);
}

bool Queue::empty() {
	return ((this->m_back < this->m_front) ? (true) : (false));
}

int Queue::front() {
	return ((this->empty() == true) ? (-1) : (this->m_q[this->m_front]));
}

int Queue::back() {
	return ((this->empty() == true) ? (-1) : (this->m_q[this->m_back]));
}