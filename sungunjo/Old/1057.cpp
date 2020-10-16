#include <iostream>
using namespace std;
int main() {
	int N, kim, im, round = 0;
	scanf("%d %d %d", &N, &kim, &im);
	while(kim != im) {
		round++;
		kim = (kim + 1) / 2;
		im = (im + 1) / 2;
	}

	printf("%d\n", round);

	return 0;
}
