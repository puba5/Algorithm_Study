#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
	} else {
		tree[node] = init(arr, tree, node*2, start, (start+end)/2) + init(arr, tree, node*2+1, (start+end)/2+1, end);
	}

	return tree[node];
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
	long long ret;
	if ((right < start) || (left > end)) {
		ret = 0;
	} else if ((left <= start) && (right >= end)) {
		ret = tree[node];
	} else {
		ret = sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
	}

	return ret;
}

void change(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if ((index >= start) && (index <= end)) {
		tree[node] += diff;
		if (start != end) {
			change(tree, node*2, start, (start+end)/2, index, diff);
			change(tree, node*2+1, (start+end)/2+1, end, index, diff);
		}
	}
}

int main() {
	int N, M, K;

	scanf("%d %d %d", &N, &M, &K);

	vector<long long> arr(N+1);

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h+1));
	vector<long long> tree(tree_size);

	for (int n = 1; n <= N; n++) {
		scanf("%lld", &arr[n]);
	}

	init(arr, tree, 1, 1, N);

	int MK = M+K;
	for (int i = 0; i < MK; i++) {
        int a;
        scanf("%d", &a);
		if (a == 1) {
            int b;
            long long c;
            scanf("%d %lld", &b, &c);
			long long diff = c - sum(tree, 1, 1, N, b, b);
			change(tree, 1, 1, N, b, diff);
		} else {
            int b, c;
            scanf("%d %d", &b, &c);
			printf("%lld\n", sum(tree, 1, 1, N, b, c));
		}
	}

	return 0;
}
