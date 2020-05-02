#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define SWAP(a, b) 	\
	int tmp = a; 	\
	a = b; 			\
	b = tmp;

int gcd(int a, int b) {
	if (b > a) {
		SWAP(a, b)
	}

	while (b > 0) {
		int r = a % b;
		a = b; b = r;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int first_ring;
	cin >> first_ring;

	for (int i = 0; i < N - 1; i++) {
		int input_ring;
		cin >> input_ring;
		int gcd_res = gcd(first_ring, input_ring);
		cout << first_ring / gcd_res << "/" << input_ring / gcd_res << "\n";
	}

	return 0;
}