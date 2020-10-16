#include <iostream>
using namespace std;

int main() {
	int N, J, ret = 1000003;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> J;
		if (i == J) {
			ret = -1;
			break;
		}
	}
	cout << ret << endl;
	return 0;
}
