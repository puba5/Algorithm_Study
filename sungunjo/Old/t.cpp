#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 1111111111

int init(vector<int> &arr, vector<int> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	} else {
		return tree[node] = min(init(arr, tree, node*2, start,(start+end)/2), init(arr, tree, node*2+1, (start_end)/2+1, end));
	}
}

int findMinNum(vector<int> tree, int node, int start, int end, int a, int b) {
	if ((a <= start) && (end <= b)) {
		return tree[node];
	} else if ((end < a) || (b < start)) {
		return INF;
	} else {
		return min(findMinNum(tree, node*2, start, (start+end)/2, a, b), findMinNum(tree, node*2+1, (start+end)/2+1, end, a, b));
	}

}

int main () {
	int N, M;
	scanf("%d %d", &N, &M);

	vector<int> arr; arr.assign(N+1, -1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	vector<int> tree;
	int tree_height = ceil(log2(N))+1;
	int tree_size = (1 << tree_height);
	tree.assign(tree_size, -1);
	init(arr, tree, 1, 1, N);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", findMinNum(tree, 1, 1, N, a, b));
	}
	return 0;
}
