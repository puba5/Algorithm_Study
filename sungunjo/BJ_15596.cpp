#include <iostream>
#include <vector>

long long sum(std::vector<int> &a) {
	long long ans = 0;
	std::vector<int>::iterator iter;
	for (iter = a.begin(); iter != a.end(); iter++) {
		ans += *iter;
	}

	return ans;
}

int main() {
	std::vector<int> a;
	a.push_back(1);

	a.push_back(10);

	a.push_back(100);

	a.push_back(1000);

	printf("%lld\n", sum(a));
}