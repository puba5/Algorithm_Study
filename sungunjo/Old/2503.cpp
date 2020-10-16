#include <iostream>
using namespace std;

typedef struct _qestion {
	int x;
	int y;
	int z;

	int s;
	int b;
} Qestion;

Qestion q[100];
int cnt = 0;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num >> q[i].s >> q[i].b;
		q[i].z = num % 10;
		q[i].y = (num / 10) % 10;
		q[i].x = (num / 100);
	}

	for (int x = 1; x < 10; x++) {
		for (int y = 1; y < 10; y++) {
			if (y == x) {
				continue;
			}

			for (int z = 1; z < 10; z++) {
				if (z == x || z == y) {
					continue;
				}

				bool possible = true;

				for (int i = 0; i < N; i++) {
					int s = 0;
					int b = 0;

					if (x == q[i].x) {
						s++;
					}
					if (y == q[i].y) {
						s++;
					}
					if (z == q[i].z) {
						s++;
					}
					if (s != q[i].s) {
						possible = false;
						break;
					}

					if (x == q[i].y || x == q[i].z) {
						b++;
					}
					if (y == q[i].x || y == q[i].z) {
						b++;
					}
					if (z == q[i].x || z == q[i].y) {
						b++;
					}
					if (b != q[i].b) {
						possible = false;
						break;
					}
				}

				if (possible) {
cout << x << y << z << endl;
					cnt++;
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
