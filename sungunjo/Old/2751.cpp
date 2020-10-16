#include <iostream>
#include <set>
using namespace std;
int main() {
	int t;
	set<int> s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int tmp;
		cin >> tmp;
		s.insert(tmp);
	}

	set<int>::iterator iter;
	for (iter= s.begin(); iter != s.end(); iter++) {
		cout << *iter << "\n";
	}

	return 0;
}
