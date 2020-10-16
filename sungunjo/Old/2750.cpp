#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &v, int a) {
	for (int i = 0; i < v.size(); i++) {
		if (a < v[i]) {
			v.insert(v.begin() + i, a);
			return;
		}
	}

	v.push_back(a);
}

int main() {
	vector<int> v;
	int N;
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		int tmp;
		scanf("%d", &tmp);
		insert(v, tmp);
	}

	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}

	return 0;
}
