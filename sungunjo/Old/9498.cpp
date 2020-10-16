#include <iostream>

using namespace std;

int main() {
	int x;
	cin >> x;
	if (90 <= x) {
		cout << "A\n";
	} else if (80 <= x) {
		cout << "B\n";
	} else if (70 <= x) {
		cout << "C\n";
	} else if (60 <= x) {
		cout << "D\n";
	} else {
		cout << "F\n";
	}

	return 0;
}
