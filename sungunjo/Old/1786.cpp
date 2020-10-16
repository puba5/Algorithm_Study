#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> getPi(string str) {
	int str_len = (int)str.size();
	int j = 0;

	vector<int> pi(str_len, 0);

	for (int i = 1; i < str_len; i++) {
		while(j > 0 && str[i] != str[j]) {
			j = pi[j-1];
		}

		if (str[i] == str[j]) {
			pi[i] = ++j;
		}
	}

	return pi;
}

vector<int> kmp(string str, string pat) {
	vector<int> ans;

	vector<int> pi = getPi(pat);
	int str_len = (int)str.size();
	int pat_len = (int)pat.size();
	int j = 0;

	for (int i = 0; i < str_len; i++) {
		while(j > 0 && str[i] != pat[j]) {
			j = pi[j-1];
		}

		if (str[i] == pat[j]) {
			if (j == pat_len - 1) {
				ans.push_back(i - pat_len + 1);
				j = pi[j];
			} else {
				j++;
			}
		}
	}

	return ans;
}

int main() {
	string str, pat;
	getline(cin, str);
	getline(cin, pat);

	vector<int> ans = kmp(str, pat);

	int ans_len = (int)ans.size();
	printf("%d\n", ans_len);
	for (int i = 0; i < ans_len; i++) {
		printf("%d\n", ans[i] + 1);
	}

	return 0;
}
