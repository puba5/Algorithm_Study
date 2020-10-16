#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	int k = 64;
	int cnt = 0;

	while(x > 0) {
		if (x - k >= 0) {
			x -= k;
			cnt++;
		} else {
			k /= 2;
		}
	}

	cout << cnt << endl;

	return 0;
}
