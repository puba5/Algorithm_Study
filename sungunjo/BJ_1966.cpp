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
	Queue() : q(new int[100000000]), head(0), tail(-1) {};
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

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		Queue print_q_pri((N * (N + 1)) / 2);
		Queue print_q_id((N * (N + 1) / 2));
		vector<int> priority_heap(N);
		int wanted_id;
		for (int n = 0; n < N; n++) {
			int priority;
			cin >> priority;
			if (n == M) {
				wanted_id = n;
			}
			print_q_id.push(n);
			print_q_pri.push(priority);
			priority_heap[n] = priority;
		}
		sort(priority_heap.begin(), priority_heap.end(), greater<int> ());
		int heap_idx = 0;
		int cnt = 0;
		int printed_id = -1;
		do {
			if (print_q_pri.front() == priority_heap[heap_idx]) {
				printed_id = print_q_id.pop();
				print_q_pri.pop();
				heap_idx += 1;
				cnt += 1;
				
			} else {
				print_q_id.push(print_q_id.pop());
				print_q_pri.push(print_q_pri.pop());
			}
		} while (printed_id != wanted_id);

		cout << cnt << "\n";
	}

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