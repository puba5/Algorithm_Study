#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	double x, y, c;
	cin >> x >> y >> c;

	double left = 0; 
	double right = min(x, y);

	while(abs(right - left) > 1e-6) {
		double mid = (left + right) / 2;

		double c1 = sqrt(x*x - mid*mid);
		double c2 = sqrt(y*y - mid*mid);
		double h = (c1 * c2) / (c1 + c2);

		if (h > c) {
			left = mid;
		} else {
			right = mid;
		}
	}

	cout << left << endl;
	return 0;
}
