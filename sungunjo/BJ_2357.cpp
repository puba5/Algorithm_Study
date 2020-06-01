#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define IOS_SETTING \
ios::sync_with_stdio(false); \
cin.tie(NULL); cout.tie(NULL)

#define N_MAX 100000
#define DATA_MIN 0
#define DATA_MAX 1000000000

#define POWER(a, n) ((a) << (n))

typedef struct _data_set {
	int min;
	int max;

	_data_set(): min(0), max(0) {};
	_data_set(int _min, int _max): min(_min), max(_max) {};
} DataSet;

class SegTree {
/* value */
private:
	DataSet *tree;
	int tree_size;
	int data_size;

public:

/* method */
private:
	void initialize(int);

	void setNode(int, DataSet);
	DataSet getNode(int);

	int getLeftChild(int);
	int getRightChild(int);
	int getMid(int, int);

	int getMin(int, int, int, int, int = 1);
	int getMax(int, int, int, int, int = 1);
public:
	SegTree();
	SegTree(int);
	SegTree(int*, int);

	DataSet initTree(int *, int, int, int = 1);

	int getMin(int, int);
	int getMax(int, int);
};

int main() {
	IOS_SETTING;
	int N, M;
	cin >> N >> M;

	int *data = new int[N];

	for (int n = 0; n < N; n++) {
		cin >> data[n];
	}

	SegTree seg_tree(data, N);

	for (int m = 0; m < M; m++) {
		int start, end;
		cin >> start >> end;
		start -= 1;
		end -= 1;
		cout << seg_tree.getMin(start, end) << " " << seg_tree.getMax(start, end) << "\n";
	}

	return 0;
}


/* public method */
SegTree::SegTree() {
	initialize(N_MAX);
}

SegTree::SegTree(int data_size) {
	initialize(data_size);
}

SegTree::SegTree(int *data, int data_size) {
	initialize(data_size);
	initTree(data, 0, data_size - 1);
}

DataSet SegTree::initTree(int *data, int start, int end, int node) {
	DataSet data_set;

	if (start == end) {
		data_set.min = data[start];
		data_set.max = data[end];
	} else {
		int mid = getMid(start, end);
		DataSet left_child_data = initTree(data, start, mid, getLeftChild(node));
		DataSet right_child_data = initTree(data, mid + 1, end, getRightChild(node));
		data_set.min = min(left_child_data.min, right_child_data.min);
		data_set.max = max(left_child_data.max, right_child_data.max);
	}

	setNode(node, data_set);
	return getNode(node);
}

int SegTree::getMin(int left, int right) {
	return getMin(left, right, 0, (*this).data_size - 1);
}

int SegTree::getMax(int left, int right) {
	return getMax(left, right, 0, (*this).data_size - 1);
}



/* private method */
void SegTree::initialize(int data_size) {
	int tree_height = ceil(log2(data_size));
	(*this).tree_size = POWER(2, tree_height + 1);
	(*this).tree = new DataSet[(*this).tree_size];
	(*this).data_size = data_size;
}

void SegTree::setNode(int node, DataSet data_set) {
	(*this).tree[node].min = data_set.min;
	(*this).tree[node].max = data_set.max;
}

DataSet SegTree::getNode(int node) {
	return (*this).tree[node];
}

int SegTree::getLeftChild(int parent) {
	return (parent * 2);
}

int SegTree::getRightChild(int parent) {
	return ((parent * 2) + 1);
}

int SegTree::getMid(int start, int end) {
	return ((start + end) / 2);
}

int SegTree::getMin(int left, int right, int start, int end, int node) {
	int min_data;
	if ((right < start) || (end < left)) {
		min_data = DATA_MAX;
	} else if ((left <= start) && (end <= right)) {
		min_data = getNode(node).min;
	} else {
		int mid = getMid(start, end);
		int left_child_data_min = getMin(left, right, start, mid, getLeftChild(node));
		int right_child_data_min = getMin(left, right, mid + 1, end, getRightChild(node));
		min_data = min(left_child_data_min, right_child_data_min);
	}

	return min_data;
}

int SegTree::getMax(int left, int right, int start, int end, int node) {
	int max_data;
	if ((right < start) || (end < left)) {
		max_data = DATA_MIN;
	} else if ((left <= start) && (end <= right)) {
		max_data = getNode(node).max;
	} else {
		int mid = getMid(start, end);
		int left_child_data_max = getMax(left, right, start, mid, getLeftChild(node));
		int right_child_data_max = getMax(left, right, mid + 1, end, getRightChild(node));
		max_data = max(left_child_data_max, right_child_data_max);
	}

	return max_data;
}