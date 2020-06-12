#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	priority_queue<int, vector<int>, less<int> > max_heap;
	priority_queue<int, vector<int>, greater<int> > min_heap;

	for (int n = 0; n < N; n++) {
		int input;
		scanf("%d", &input);

		if (max_heap.size() <= min_heap.size()) {
			max_heap.push(input);
		} else {
			min_heap.push(input);
		}

		if ((min_heap.empty() != true) && (max_heap.top() > min_heap.top())) {
			int a = max_heap.top(); max_heap.pop();
			int b = min_heap.top(); min_heap.pop();

			max_heap.push(b);
			min_heap.push(a);
		}

		printf("%d\n", max_heap.top());
	}

	return 0;
}