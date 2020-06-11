#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define ROOT_NODE 1
#define EMPTY 0
#define OUT_OF_BOUND 0
#define POP 0

#define LEFT_CHILD(p) ((p) * (2))
#define RIGHT_CHILD(p) (((p) * (2)) + (1))
#define PARENT(c) ((c) / (2))

class AbsMinHeap {
private:
	int *m_tree;
	int m_tree_size;
	int m_last_node;

public:

private:
	void init(int _tree_size) {
		m_tree_size = _tree_size + 1;
		m_last_node = ROOT_NODE - 1;
		m_tree = new int[m_tree_size];
		memset(m_tree, EMPTY, m_tree_size * sizeof(int));
	};

	bool isValid(int _node) {
		if (((_node < ROOT_NODE) || (m_last_node < _node)) ||
			(m_tree[_node] == EMPTY)) {
			return false;
		} else {
			return true;
		}
	};

	int idxOfSmallerNode(int _a, int _b) {
		int abs_a = abs(m_tree[_a]), abs_b = abs(m_tree[_b]);
		if (abs_a < abs_b) {
			return _a;
		} else if (abs_b < abs_a) {
			return _b;
		} else {
			if (m_tree[_a] < m_tree[_b]) {
				return _a;
			} else {
				return _b;
			}
		}
	};

	int smallChild(int cur) {
		int l_child = LEFT_CHILD(cur);
		int r_child = RIGHT_CHILD(cur);

		if (isValid(l_child) == true) {
			if (isValid(r_child) == true) {
				return idxOfSmallerNode(l_child, r_child);
			} else {
				return l_child;
			}
		} else {
			if (isValid(r_child) == true) {
				return r_child;
			} else {
				return OUT_OF_BOUND;
			}
		}
	};

	void bottomUp() {
		int cur = m_last_node;
		int par = PARENT(cur);

		while ((isValid(par) == true) &&
				(idxOfSmallerNode(cur, par) == cur)) {

			swap(m_tree[cur], m_tree[par]);

			cur = par;
			par = PARENT(cur);
		}
	};

	void topDown() {
		int cur = ROOT_NODE;
		int child = smallChild(cur);

		while ((isValid(child) == true) &&
		(idxOfSmallerNode(cur, child) == child)) {

			swap(m_tree[cur], m_tree[child]);

			cur = child;
			child = smallChild(cur);
		}
	};

public:
	AbsMinHeap() {};

	AbsMinHeap(int _tree_size) {
		init(_tree_size);
	};

	void push(int _n) {
		m_last_node += 1;
		m_tree[m_last_node] = _n;

		bottomUp();
	};

	int pop() {
		int ret = m_tree[ROOT_NODE];
		m_tree[ROOT_NODE] = m_tree[m_last_node];
		m_tree[m_last_node] = EMPTY;

		if (m_last_node >= ROOT_NODE) {
			m_last_node -= 1;
		}

		topDown();

		return ret;
	};
};

int main() {
	int N;
	scanf("%d", &N);

	AbsMinHeap abs_min_heap(N);

	for (int n = 0; n < N; n++) {
		int input;
		scanf("%d", &input);

		if (input == POP) {
			printf("%d\n", abs_min_heap.pop());
		} else {
			abs_min_heap.push(input);
		}
	}	

	return 0;
}