#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define PACK_KIND_SIZE 2
int pack_kind[PACK_KIND_SIZE] = {3, 5};

int main() {
	int N;
	scanf("%d", &N);
	vector<int> pack_num(N + 1, -1);

	pack_num[0] = 0;
	pack_num[3] = 1;
	pack_num[5] = 1;
	
	for (int n = 6; n <= N; n++) {
		if (pack_num[n - 3] != -1) {
			if (pack_num[n - 5] != -1) {
				pack_num[n] = min(pack_num[n - 3], pack_num[n - 5]) + 1;
			} else {
				pack_num[n] = pack_num[n - 3] + 1;
			}
		} else if (pack_num[n - 5] != -1) {
			pack_num[n] = pack_num[n - 5] + 1;
		}
	}

	printf("%d\n", pack_num[N]);
}