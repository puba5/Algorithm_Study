#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define STR_MAX 50

bool ascend(string &a, string &b) {
	if (a.size() < b.size()) {
		return true;
	} else if (a.size() > b.size()) {
		return false;
	} else {
		if (a.compare(b) < 0) {
			return true;
		} else {
			return false;
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);

	vector<string> str_arr(N);

	for (int n = 0; n < N; n++) {
		char input_str[STR_MAX + 1];
		scanf("%s", input_str);
		str_arr[n].append(input_str);
	}

	sort(str_arr.begin(), str_arr.end(), ascend);
	
	for (int i = 0; i < str_arr.size(); i++) {
		if ((i > 0) && (str_arr[i - 1].compare(str_arr[i]) == 0)) {
			continue;
		}
		printf("%s\n", str_arr[i].c_str());
	}

	return 0;
}