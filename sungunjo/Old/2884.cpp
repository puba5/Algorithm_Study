#include <iostream>
using namespace std;

int main() {
	int H, M;

	cin >> H >> M;

	int H2, M2;
	M2 = (M + 15) % 60;
	if (M < 45) {
		H2 = (H + 23) % 24;
	} else {
		H2 = H;
	}

	cout << H2 << " " << M2 << endl;
}
