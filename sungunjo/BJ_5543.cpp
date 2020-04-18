#include <iostream>
using namespace std;
#define MAX 2000
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {int bugger = MAX, drink = MAX;
	for (int i = 0; i < 3; i++) {
		int _bugger;
		scanf("%d", &_bugger);
		bugger = MIN(bugger, _bugger);
	}

	for (int i = 0; i < 2; i++) {
		int _drink;
		scanf("%d", &_drink);
		drink = MIN(drink, _drink);
	}

	printf("%d\n", bugger + drink - 50);

	return 0;
}