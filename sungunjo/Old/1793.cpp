#include <iostream>
using namespace std;

class int_100 {
public:
	unsigned int num[100];

	void set(unsigned int a) {
		for (int i = 0; i < 10; i++) {
			num[i] = a % 10;
			a /= 10;
		}
	}

	void print() {
		bool start = false;
		for (int i = 99; i >=0; i--) {
			if (!start) {
				if (num[i] != 0) {
					start = true;
				}
			}
			if (start) {
				cout << num[i];
			}
		}
		cout << endl;
	}
};

int_100 add(int_100 a, int_100 b) {
	int_100 result;
	bool carry = false;
	for (int i = 0; i < 100; i++) {
		result.num[i] = a.num[i] + b.num[i];
		if (carry) {
			result.num[i] += 1;
			carry = false;
		}
		if (result.num[i] >= 10) {
			carry = true;
			result.num[i] %= 10;
		}
	}
	return result;
}

int_100 mult2(int_100 a) {
	int_100 result;
	unsigned int upload = 0;
	for (int i = 0; i < 100; i++) {
		result.num[i] = a.num[i] * 2 + upload;
		upload = result.num[i] / 10;
		result.num[i] %= 10;
	}
	return result;
}



int main() {
	int n;
	int_100 dp[251];

	dp[0].set(1);
	dp[1].set(1);

	for (int i = 2; i <= 250; i++) {
		dp[i] = add(dp[i-1], mult2(dp[i-2]));
	}
	
	while (cin >> n) {
		dp[n].print();
	}

	return 0;
}
