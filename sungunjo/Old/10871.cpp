#include <iostream>
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	for (int n = 0; n < N; n++) {
		int tmp;
		cin >> tmp;
		if (tmp < X) {
			cout << tmp << " ";
		}
	}
	cout << "\n";

	return 0;
}
