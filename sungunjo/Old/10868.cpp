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
        int lc = node*2;
        int mid = (start + end) / 2;
		return tree[node] = min(init(arr, tree, lc, start, mid), init(arr, tree, lc+1, mid+1, end));
	}
}

int findMinNum(vector<int> &tree, int node, int start, int end, int a, int b) {                          // tree를 참조자로 받아야 속도 빠름
	if ((a <= start) && (end <= b)) {
		return tree[node];
	} else if ((end < a) || (b < start)) {
		return INF;
	} else {
        int lc = node*2;
        int mid = (start+end) /2;
		return min(findMinNum(tree, lc, start, mid, a, b), findMinNum(tree, lc+1, mid+1, end, a, b));
	}

}

int main () {
	int N, M;
	scanf("%d %d", &N, &M);

	vector<int> arr(N+1);
	int tree_height = ceil(log2(N))+1;
	int tree_size = (1 << tree_height);
	vector<int> tree(tree_size);
    
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
    
	init(arr, tree, 1, 1, N);
    
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", findMinNum(tree, 1, 1, N, a, b));
	}
    
	return 0;
}
