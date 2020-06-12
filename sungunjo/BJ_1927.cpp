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
#define OUT_OF_BOUND 0;

#define POP 0

#define LEFT_CHILD(p) ((p) * (2))
#define RIGHT_CHILD(p) (((p) * (2)) + 1)
#define PARENT(c) ((c) / (2))

class MinHeap {
private:
	int *m_tree;
	int m_tree_size;
	int m_last_node;

public:


private:
	void init(int _tree_size) {
		m_tree_size = _tree_size + 1;
		m_tree = new int[m_tree_size];
		memset(m_tree, EMPTY, m_tree_size * sizeof(int));
		m_last_node = ROOT_NODE - 1;
	}

	bool isValid(int _idx) {
		if (((_idx < ROOT_NODE) || (m_last_node < _idx)) ||
			(m_tree[_idx] == EMPTY)) {
			return false;
		} else {
			return true;
		}
	};

	int idxOfSmallerOne(int _node_a, int _node_b) {
		if (m_tree[_node_a] < m_tree[_node_b]) {
			return _node_a;
		} else {
			return _node_b;
		}
	};

	int smallerChild(int _node_a, int _node_b) {
		bool node_a_valid = isValid(_node_a);
		bool node_b_valid = isValid(_node_b);

		if (node_a_valid == true) {
			if (node_b_valid == true) {
				return idxOfSmallerOne(_node_a, _node_b);
			} else {
				return _node_a;
			}
		} else {
			if (node_b_valid == true) {
				return _node_b;
			} else {
				return OUT_OF_BOUND;
			}
		}
	};

	void sortBottomUp() {
		int cur = m_last_node;
		int parent = PARENT(cur);

		while ((isValid(parent) == true) &&
				(m_tree[cur] < m_tree[parent])) {
			
			swap(m_tree[cur], m_tree[parent]);

			cur = parent;
			parent = PARENT(cur);
		}
	};

	void sortTopDown() {
		int cur = ROOT_NODE;
		int left_child = LEFT_CHILD(cur);
		int right_child = RIGHT_CHILD(cur);
		int small_child = smallerChild(left_child, right_child);

		while ((isValid(small_child) == true) &&
				(m_tree[cur] > m_tree[small_child])) {

			swap(m_tree[cur], m_tree[small_child]);

			cur = small_child;
			left_child = LEFT_CHILD(cur);
			right_child = RIGHT_CHILD(cur);
			small_child = smallerChild(left_child, right_child);
		}
	};

	void setRoot(int _n) {
		m_tree[ROOT_NODE] = _n;
	};

	int getRoot() {
		return m_tree[ROOT_NODE];
	};

	void setLast(int _n) {
		m_tree[m_last_node] = _n;
	};

	int getLast() {
		return m_tree[m_last_node];
	}

	void popLast() {
		setLast(EMPTY);
		if (m_last_node >= ROOT_NODE) {
			m_last_node -= 1;
		}
	};

	void pushBack(int _n) {
		m_last_node += 1;
		setLast(_n);
	};

public:
	MinHeap() {};

	MinHeap(int _tree_size) {
		init(_tree_size);
	};

	void push(int _n) {
		pushBack(_n);
		sortBottomUp();
	};

	int top() {
		int ret = getRoot();
		return ret;
	};

	void pop() {
		setRoot(getLast());
		popLast();
		sortTopDown();
	};
};

int main() {
	int N;
	scanf("%d", &N);

	MinHeap min_heap(N);

	for (int n = 0; n < N; n++) {
		int input;
		scanf("%d", &input);
		
		if (input == POP) {
			printf("%d\n", min_heap.top());
			min_heap.pop();
		} else {
			min_heap.push(input);
		}
	}

	return 0;
}