#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int getPi(string str) {
	int ret = 0;

	int str_len = (int)str.size();
	int j = 0;

	vector<int> pi(str_len, 0);

	for (int i = 1; i < str_len; i++) {
		while((j > 0) && (str[i] != str[j])) {
			j = pi[j-1];
		}

		if (str[i] == str[j]) {
			pi[i] = ++j;
			ret = max(ret, pi[i]);
		}
	}

	return ret;
}

int main() {
	string str;
	getline(cin, str);

	int str_len = (int)str.size();

	int ans = 0;

	for (int i = 0; i < str_len - 1; i++) {
		ans = max(ans, getPi(str.substr(i)));
	}

	printf("%d\n", ans);

	return 0;
}
