#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int getReversedNum() {
	int reversed_num = 0;
	int pos = 1;
	for (int i = 0; i < 3; i++) {
		int input;
		scanf("%1d", &input);
		reversed_num += input * pos;
		pos *= 10;
	}

	return reversed_num;
}

int main() {
	int first = getReversedNum();
	int second = getReversedNum();

	printf("%d\n", MAX(first, second));
}