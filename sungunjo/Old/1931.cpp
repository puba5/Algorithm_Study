#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N;
vector<pair<unsigned int, unsigned int> > a;

int main() {
	cin >> N;

	for (int n = 0; n < N; n++) {
		unsigned int start, end;
		cin >> start >> end;
		a.push_back(make_pair(end, start));
	}

	sort(a.begin(), a.end());

	int count = 0;
	int before_end = 0;

	for (int i = 0; i < N; i++) {
		if (before_end <= a[i].second) {
			count++;
			before_end = a[i].first;
		}
	}

	cout << count << endl;

	return 0;
}
