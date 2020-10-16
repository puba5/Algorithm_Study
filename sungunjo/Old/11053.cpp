#include <iostream>
using namespace std;

int main() {
	int n;
	int *a;
	int *length;
	int max;
	
	cin >> n;

	a = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	length = new int[n];
	length[0] = 1;

	for (int i = 1; i < n; i++) {
		max = 0;
		for (int j = 0; j < i; j++) {
			if ((a[j] < a[i]) && (max < length[j])) {
					max = length[j];
			}
		}
		length[i] = max + 1;
	}
	
	max = length[0];
	for (int i = 1; i < n; i++) {
		if (max < length[i]) {
			max = length[i];
		}
	}
	cout << max << endl;
	
	return 0;
}
