#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

class Queue {
private:
	int *q;
	int head;
	int tail;

public:
	Queue() : q(NULL), head(-1), tail(-1) {};
	Queue(int size): q(new int[size]), head(0), tail(-1) {};
	void push(int n);
	int pop();
	int size();
	bool empty();
	int front();
	int back();
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;

	cin >> N;
	Queue q(2 * N);
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();
		q.push(q.pop());
	}

	cout << q.front() << "\n";

	return 0;
}

void Queue::push(int n) {
	tail += 1;
	(*this).q[tail] = n;
}

int Queue::pop() {
	int poped = (*this).front();
	if (poped != -1) {
		(*this).head += 1;
	}
	return poped;
}

int Queue::size() {
	return ((*this).tail - (*this).head + 1);
}

bool Queue::empty() {
	return !((bool) (*this).size());
}

int Queue::front() {
	return (((*this).empty() == true) ? (-1) : ((*this).q[head]));
}

int Queue::back() {
	return (((*this).empty() == true) ? (-1) : ((*this).q[tail]));
}