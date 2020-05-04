#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K;
	cin >> K;

	stack<int> s;
	
	int sum = 0;
	for (int k = 0; k < K; k++) {
		int input;
		cin >> input;
		if (input == 0) {
			sum -= s.top();
			s.pop();
		} else {
			s.push(input);
			sum += s.top();
		}
	}

	cout << sum << "\n";
	return 0;
}