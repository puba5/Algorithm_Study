#include <iostream>
#include <algorithm>
using namespace std;

int N;
int one;
int other[1005];

bool desc(int a, int b) {
	return a > b;
}

int main() {
	cin >> N;

	cin >> one;
	for (int i = 0; i < N-1; i++) {
		cin >> other[i];
	}

	int ret = 0;
	while(1) {
		sort(other, other+(N-1), desc);
		if (one > other[0]) {
			break;
		} else {
			other[0]--;
			one++;
			ret++;
		}
	}

	cout << ret << endl;
}
