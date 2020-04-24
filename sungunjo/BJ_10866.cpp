#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define N_MAX 10000
#define DEQUEUE_SIZE (N_MAX * 2)
#define INITIAL_FRONT (DEQUEUE_SIZE / 2)
#define INITIAL_BACK ((DEQUEUE_SIZE / 2) - 1)

#define CMD_MAX 10

class Dequeue {
private:
	int m_front;
	int m_back;
	int m_deq[DEQUEUE_SIZE];
public:
	Dequeue() : m_front(INITIAL_FRONT), m_back(INITIAL_BACK) {};

	void pushFront(int num);
	void pushBack(int num);
	
	int popFront();
	int popBack();

	int size();
	bool empty();

	int front();
	int back();
};

int main() {
	int N;
	scanf("%d", &N);

	Dequeue deq;

	for (int n = 0; n < N; n++) {
		char cmd[CMD_MAX];
		scanf("%s", cmd);

		if (strncmp(cmd, "push_front", CMD_MAX) == 0) {
			int num;
			scanf("%d", &num);
			deq.pushFront(num);
		} else if (strncmp(cmd, "push_back", CMD_MAX) == 0) {
			int num;
			scanf("%d", &num);
			deq.pushBack(num);
		} else if (strncmp(cmd, "pop_front", CMD_MAX) == 0) {
			printf("%d\n", deq.popFront());
		} else if (strncmp(cmd, "pop_back", CMD_MAX) == 0) {
			printf("%d\n", deq.popBack());
		} else if (strncmp(cmd, "empty", CMD_MAX) == 0) {
			printf("%d\n", deq.empty());		
		} else if (strncmp(cmd, "size", CMD_MAX) == 0) {
			printf("%d\n", deq.size());			
		} else if (strncmp(cmd, "front", CMD_MAX) == 0) {
			printf("%d\n", deq.front());
		} else if (strncmp(cmd, "back", CMD_MAX) == 0) {
			printf("%d\n", deq.back());
		}
	}
	

	return 0;
}

void Dequeue::pushFront(int num) {
	this->m_front -= 1;
	this->m_deq[this->m_front] = num;
}

void Dequeue::pushBack(int num) {
	this->m_back += 1;
	this->m_deq[this->m_back] = num;
}

int Dequeue::popFront() {
	int poped = this->front();
	if (poped != -1) { this->m_front += 1; }
	return poped;
}

int Dequeue::popBack() {
	int poped = this->back();
	if (poped != -1) { this->m_back -= 1; }
	return poped;
}

int Dequeue::size() {
	return (this->m_back - this->m_front + 1);
}

bool Dequeue::empty() {
	return ((this->m_front > this->m_back) ? (true) : (false));
}

int Dequeue::front() {
	if (this->empty() == true) {
		return -1;
	} else {
		return this->m_deq[this->m_front];
	}
}

int Dequeue::back() {
	if (this->empty() == true) {
		return -1;
	} else {
		return this->m_deq[this->m_back];
	}
}