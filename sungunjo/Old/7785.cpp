#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	multiset<string, greater<string> > enter;
	multiset<string, greater<string> > leave;
	for (int i = 0; i < n; i++) {
		string name, state;

		cin >> name >> state;

		if (state == "enter") {
			enter.insert(name);
		} else {
			leave.insert(name);
		}
	}

	multiset<string>::iterator e = enter.begin(), l = leave.begin();

	while(e != enter.end()) {
		if ((*e) != (*l)) {
			cout << *e << "\n";
		} else {
			l++;
		}
		e++;
	}

	return 0;
}
