#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	long double ret = 88888888;
	long double a[500];
	
	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int k = K; k <= N; k++) {
		for (int i = 0; i <= N - k; i++) {
			long double m = 0;
			for (int j = i; j < i + k; j++) {
				m += a[j];
			}
			m /= k;
			long double dist = 0;
			for (int j = i; j < i + k; j++) {
				dist += (a[j] - m) * (a[j] - m);
			}
			dist /= k;
			ret = min(ret, dist);
		}
	}


	cout.precision(11);
	cout << sqrt(ret) << endl;

	return 0;
}
