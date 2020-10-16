#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int max_num = 0;
	int max_num_index = 0;
	for (int i = 0; i < 9; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (max_num < tmp) {
			max_num = tmp;
			max_num_index = i + 1;
		}
	}

	printf("%d\n%d", max_num, max_num_index);
}
