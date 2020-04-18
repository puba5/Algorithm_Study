#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char *input = new char[1000000];
	cin.getline(input, 1000000);
	int i = 0;
	char *t = strtok(input, " ");
	while (t != NULL) {
		t = strtok(NULL, " ");
		i += 1;
	}
	printf("%d\n", i);
}