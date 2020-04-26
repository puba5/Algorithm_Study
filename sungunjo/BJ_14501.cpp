#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

typedef struct _node {
	int t;
	int p;

	_node() : t(0), p(0) {};
	_node(int _t, int _p) : t(_t), p(_p) {};
} Node;

int go(const vector<Node> &list, int index, int total_p) {
	if (index == list.size()) { 
		return total_p; 
	}
	
	return max(((index + list[index].t <= list.size()) ? go(list, index + list[index].t, total_p + list[index].p) : (total_p)), 
				((index + 1 <= list.size()) ? go(list, index + 1, total_p) : (total_p)));
}

int main() {
	int N;
	scanf("%d", &N);

	vector<Node> list(N);

	for (int n = 0; n < N; n++) {
		scanf("%d %d", &(list[n].t), &(list[n].p));
	}

	printf("%d\n", go(list, 0, 0));
	

	return 0;
}