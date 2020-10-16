#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char numbers[16];
	char asc[16] = "1 2 3 4 5 6 7 8";
	char des[16] = "8 7 6 5 4 3 2 1";
	cin.getline(numbers, 16);
	if (strncmp(numbers, asc, 16) == 0) {
		printf("ascending\n");
	} else if (strncmp(numbers, des, 16) == 0) {
		printf("descending\n");
	} else {
		printf("mixed\n");
	}

}
