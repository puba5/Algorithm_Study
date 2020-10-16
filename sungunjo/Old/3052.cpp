#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> s;
	for (int i = 0; i < 10; i++) {
		register int a;
		scanf("%d", &a);
		a %= 42;
		s.insert(a);
	}
	printf("%d\n", (int)s.size());
	return 0;
}
