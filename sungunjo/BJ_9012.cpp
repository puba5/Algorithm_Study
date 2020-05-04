#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

bool isVPS(const string &str) {
	int vps_check = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			vps_check += 1;
		} else if (str[i] == ')') {
			vps_check -= 1;
		} else {
			return -1;
		}
		if (vps_check < 0) {
			return false;
		}
	}

	if (vps_check == 0) {
		return true;
	} else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string input;
		cin >> input;

		if (isVPS(input) == true) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}