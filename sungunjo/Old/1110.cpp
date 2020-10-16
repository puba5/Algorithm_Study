#include <iostream>
using namespace std;

int main() {
	int n, x, cycle = 0;
	cin >> n;
	x = n;
	do {
		x = (x % 10) * 10 + (((x / 10) + (x % 10)) % 10);
		cycle++;
	} while (n != x);

	cout << cycle << "\n";
}
