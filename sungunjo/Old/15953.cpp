#include <iostream>
using namespace std;

int main() {
	int T;
	int ret[1000];
	int a, b;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		
		ret[i] = 0;

		if (1 <= a && a < 2) {
			ret[i] = 5000000; 
		} else if (2 <= a && a < 4) {
			ret[i] = 3000000;
		} else if (4 <= a && a < 7) {
			ret[i] = 2000000;
		} else if (7 <= a && a < 11) {
			ret[i] = 500000;
		} else if (11 <= a && a < 16) {
			ret[i] = 300000;
		} else if (16 <= a && a < 22) {
			ret[i] = 100000;
		}

		if (1 <= b && b < 2) {
			ret[i] += 5120000;
		} else if (2 <= b && b < 4) {
			ret[i] += 2560000;
		} else if (4 <= b && b < 8) {
			ret[i] += 1280000;
		} else if (8 <= b && b < 16) {
			ret[i] += 640000;
		} else if (16 <= b && b < 32) {
			ret[i] += 320000;
		}
	}

	for (int i = 0; i < T; i++) {
		cout << ret[i] << endl;
	}

	

	return 0;
}
