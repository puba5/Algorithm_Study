#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		vector<string> pnum;
		cin >> n;
		for (int nc = 0; nc < n; nc++) {
			string temp;
			cin >> temp;
			pnum.push_back(temp);
		}

		sort(pnum.begin(), pnum.end());

		bool consistency = true;

		for (int i = 0; i < n-1; i++) {
			int len = pnum[i].size();
			if ((pnum[i][0] == pnum[i+1][0]) && (len < pnum[i+1].size())){
				bool isEqual = true;
				for (int j = 0; j < len; j++) {
					if (pnum[i][j] != pnum[i+1][j]) {
						isEqual = false;
						break;
					}
				}
				if (isEqual) {
					consistency = false;
					break;
				}
			}
		}

		if (consistency == true) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
