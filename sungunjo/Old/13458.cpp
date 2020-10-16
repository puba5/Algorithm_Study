#include <iostream>
using namespace std;

int N;
int A[1000000];
int B, C;

int main() {
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> A[n];
	}
	cin >> B >> C;

	unsigned long long ans = 0;

	for (int n = 0; n < N; n++) {
		int remain = A[n] - B;
		ans++;
		
		if (remain > 0) {
			ans += remain / C;
			if (remain % C != 0) {
				ans++;
			}
		}
	}

	cout << ans << endl;
}
