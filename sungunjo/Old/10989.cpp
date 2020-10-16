#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> v(10001, 0);
	for (int n = 0; n < N; n++) {
		int tmp;
		scanf("%d", &tmp);
		v[tmp]++;
	}

	int v_size = v.size();
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < v[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}
