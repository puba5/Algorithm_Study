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
#define EMPTY_NODE 0
#define OUT_OF_BOUND -2
#define POP 0

#define LEFT_CHILD(parent) ((parent) * (2))
#define RIGHT_CHILD(parent) (((parent) * (2)) + (1))
#define PARENT(child) ((child) / (2))

class MaxHeap {
private:
	int *tree;
	int tree_size;
	int last_node;

public:

private:
	int biggerNode(int node_a, int node_b) {
		if (((node_a < ROOT_NODE) || ((*this).tree_size < node_a)) &&
			((ROOT_NODE <= node_b) && (node_b < (*this).tree_size))) {
			return node_b;
		} else if (((node_b < ROOT_NODE) || ((*this).tree_size < node_b)) &&
			((ROOT_NODE <= node_a) && (node_a < (*this).tree_size))) {
			return node_a;
		} else if (((node_a < ROOT_NODE) || ((*this).tree_size < node_a)) &&
					((node_b < ROOT_NODE) || ((*this).tree_size < node_b))) {
			return OUT_OF_BOUND;
		}

		if ((*this).tree[node_a] < (*this).tree[node_b]) {
			return node_b;
		} else {
			return node_a;
		}
	}

	void bottomUp() {
		int current = (*this).last_node;
		int parent = PARENT(current);

		while ((parent >= ROOT_NODE) && 
				(*this).tree[parent] < (*this).tree[current]) {
			swap((*this).tree[parent], (*this).tree[current]);
			current = parent;
			parent = PARENT(current);
		}
	}

	void topDown() {
		int current = ROOT_NODE;
		int left_child = LEFT_CHILD(current);
		int right_child = RIGHT_CHILD(current);
		int bigger_child = biggerNode(left_child, right_child);

		while ((bigger_child != OUT_OF_BOUND) &&
				((*this).tree[bigger_child] != EMPTY_NODE) &&
				((*this).tree[current] < (*this).tree[bigger_child])) {

			swap((*this).tree[current], (*this).tree[bigger_child]);

			current = bigger_child;
			left_child = LEFT_CHILD(current);
			right_child = RIGHT_CHILD(current);
			bigger_child = biggerNode(left_child, right_child);
		}
	}

	void pushFront(int _n) {
		(*this).tree[ROOT_NODE] = _n;
	}

	void pushBack(int _n) {
		(*this).last_node += 1;
		(*this).tree[(*this).last_node] = _n;
	}
public:
	MaxHeap() {};

	MaxHeap(int _tree_size) {
		(*this).tree_size = _tree_size + 1;
		(*this).tree = new int[(*this).tree_size];
		memset(tree, EMPTY_NODE, (*this).tree_size * sizeof(int));
		(*this).last_node = 0;
	};

	void push(int _n) {
		pushBack(_n);
		bottomUp();
	}

	int top() {
		return (*this).tree[ROOT_NODE];
	}

	int pop() {
		int ret = top();
		pushFront((*this).tree[(*this).last_node]);
		(*this).tree[(*this).last_node] = EMPTY_NODE;


		if ((*this).last_node >= ROOT_NODE) {
			(*this).last_node -= 1;
		}

		topDown();

		return ret;
	}
};

int main() {
	int N;
	scanf("%d", &N);

	MaxHeap max_heap(N);

	for (int n = 0; n < N; n++) {
		int input;
		scanf("%d", &input);
		if (input == POP) {
			printf("%d\n", max_heap.pop());
		} else {
			max_heap.push(input);
		}
	}

	return 0;
}