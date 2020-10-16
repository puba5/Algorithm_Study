#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int> > point(N);
	for (int n = 0; n < N; n++) {
		int x, y;
		cin >> x >> y;
		point.push_back(make_pair(x, y));
	}

}
