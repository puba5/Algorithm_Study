#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define IOS_OPTIMIZE \
ios::sync_with_stdio(false); \
cin.tie(NULL); cout.tie(NULL)

#define TWO_POWER_OF(n) \
((1) << (n))

#define LEFT_CHILD_NODE(p) \
((p) * (2))

#define RIGHT_CHILD_NODE(p) \
(((p) * (2)) + (1))

#define MID(a, b) \
(((a) + (b)) / 2)


#define MAX_N 1000000
#define MAX_HEIGHT 1000000000

#define ROOT_NODE 1
#define INVALID_IDX -1


class SegTree {
/* variable */
private:
	int *tree;
	int tree_size;

	int *height_list;
	int height_list_size;

public:

/* method */
private:
	int initTree(int _start, int _end, int _node = 1) {
		if (_start == _end) {
			setIdxAtNode(_node, _start);
		} else {
			int mid = MID(_start, _end);
			int left_child_node = LEFT_CHILD_NODE(_node);
			int right_child_node = RIGHT_CHILD_NODE(_node);

			int left_idx = initTree(_start, mid, left_child_node);
			int right_idx = initTree(mid + 1, _end, right_child_node);

			if (getHeightAtIdx(left_idx) > getHeightAtIdx(right_idx)) {
				setIdxAtNode(_node, right_idx);
			} else {
				setIdxAtNode(_node, left_idx);
			}
		}

		return getIdxAtNode(_node);
	};


	void setIdxAtNode(int _node, int _idx) {
		(*this).tree[_node] = _idx;
	};
	
	int getIdxAtNode(int _node) {
		return (*this).tree[_node];
	};

	int getHeightAtIdx(int _idx) {
		if ((_idx < 0) || ((*this).height_list_size <= _idx)) {
			return MAX_HEIGHT + 1;
		} else {
			return (*this).height_list[_idx];
		}
	};

	int getIdxOfMinHeightInRange(int _left, int _right) {
		return getIdxOfMinHeightInRange(_left, _right, 0, (*this).height_list_size - 1, ROOT_NODE);
	}

	int getIdxOfMinHeightInRange(int _left, int _right, int _start, int _end, int _node) {
		if ((_right < _start) || (_end < _left)) {
			return (*this).height_list_size;
		} else if ((_left <= _start) && (_end <= _right)) {
			return getIdxAtNode(_node);
		} else {
			int mid = MID(_start, _end);
			int left_child_node = LEFT_CHILD_NODE(_node);
			int right_child_node = RIGHT_CHILD_NODE(_node);

			int left_idx = getIdxOfMinHeightInRange(_left, _right, _start, mid, left_child_node);
			int right_idx = getIdxOfMinHeightInRange(_left, _right, mid + 1, _end, right_child_node);

			if (getHeightAtIdx(left_idx) > getHeightAtIdx(right_idx)) {
				return right_idx;
			} else {
				return left_idx;
			}
		}
	}

	unsigned long long getMaxSquareSizeInRange(int _left, int _right) {
		int idx_of_min_height = getIdxOfMinHeightInRange(_left, _right);

		if ((idx_of_min_height < 0) || ((*this).height_list_size <= idx_of_min_height)) {
			return 0;
		}

		int min_height = getHeightAtIdx(idx_of_min_height);
		int len = (_right - _left) + 1;
		unsigned long long size = min_height * (unsigned long long) len;
		
		int left_idx_of_min_height = idx_of_min_height - 1;
		int right_idx_of_min_height = idx_of_min_height + 1;
		if (left_idx_of_min_height >= _left) {
			unsigned long long left_size = getMaxSquareSizeInRange(_left, left_idx_of_min_height);
			size = max(size, left_size);
		}

		if (right_idx_of_min_height <= _right) {
			unsigned long long right_size = getMaxSquareSizeInRange(right_idx_of_min_height, _right);
			size = max(size, right_size);
		}

		return size;
	};

public:
	SegTree() {};
	SegTree(int *_height_list, int _height_list_size) {
		(*this).height_list_size = _height_list_size;
		(*this).height_list = _height_list;

		int h = ceil(log2((*this).height_list_size)) + 1;
		(*this).tree_size = TWO_POWER_OF(h);
		(*this).tree = new int[(*this).tree_size];

		initTree(0, (*this).height_list_size - 1);
	};

	unsigned long long getMaxSquareSize() {
		return getMaxSquareSizeInRange(0, (*this).height_list_size - 1);
	};
};

int main() {
	IOS_OPTIMIZE;

	while (true) {
		int N;
		cin >> N;

		if (N == 0) {
			break;
		}

		int *height_list = new int[N];

		for (int n = 0; n < N; n++) {
			cin >> height_list[n];
		}

		SegTree seg_tree(height_list, N);

		cout << seg_tree.getMaxSquareSize() << "\n";
	}

	return 0;
}