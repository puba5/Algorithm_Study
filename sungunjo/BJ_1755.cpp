#include <iostream>
#include <map>
using namespace std;

string convertNumToString(int num) {
	string converted_num = "";
	while (num > 0) {
		switch (num % 10) {
			case 0:
				converted_num = "zero " + converted_num;
				break;
			case 1:
				converted_num = "one " + converted_num;
				break;
			case 2:
				converted_num = "two " + converted_num;
				break;
			case 3:
				converted_num = "three " + converted_num;
				break;
			case 4:
				converted_num = "four " + converted_num;
				break;
			case 5:
				converted_num = "five " + converted_num;
				break;
			case 6:
				converted_num = "six " + converted_num;
				break;
			case 7:
				converted_num = "seven " + converted_num;
				break;
			case 8:
				converted_num = "eight " + converted_num;
				break;
			case 9:
				converted_num = "nine " + converted_num;
				break;
		}
		num /= 10;
	}

	return converted_num;
}

int main() {
	int M, N;

	scanf("%d %d", &M, &N);

	map<string, int> num_map;
	for (int i = M; i <= N; i++) {
		num_map[convertNumToString(i)] = i;
	}

	map<string, int>::iterator iter;
	int line_cnt = 0;
	for (iter = num_map.begin(); iter != num_map.end(); iter++) {
		printf("%d ", iter->second);
		line_cnt += 1;
		if (line_cnt == 10) {
			printf("\n");
			line_cnt = 0;
		}
	}
}