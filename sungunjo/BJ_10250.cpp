#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int H, W, M;
		scanf("%d %d %d", &H, &W, &M);

		int room_num_lower = ((M - 1) / H) + 1;
		int room_num_upper = ((M - 1) % H) + 1;

		printf("%d\n", room_num_upper * 100 + room_num_lower);
	}

}