#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	int lcm, gcd;

	for (int i = min(a, b); i > 0; i--) {
		if ((a % i == 0) && (b % i == 0)) {
			lcm = i;
			break;
		}
	}

	gcd = (a * b) / lcm;

	cout << lcm << "\n" << gcd << "\n";

	return 0;
}