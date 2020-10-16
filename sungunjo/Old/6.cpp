#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void printNull(int width) {
	for (int i = 0; i < width; i++) {
		printf(".");
	}
	printf(" ");
	return;
}

void drawLine(int width) {
	for (int i = 0; i < width; i++) {
		printf("#");
	}
	return;
}

void drawOuter(int width) {
	printf("#");
	for (int i = 1; i < width - 1; i++) {
		printf(".");
	}
	printf("#");
}

void drawLeft(int width) {
	printf("#");
	for (int i = 1; i < width; i++) {
		printf(".");
	}
}

void drawRight(int width) {
	for (int i = 0; i < width - 1; i++) {
		printf(".");
	}
	printf("#");
}

void print(int width, int height, int line_num, int number) {
	int mid = height / 2;
	int bottom = height - 1;
	switch (number) {
		case 0:
			if ((line_num == 0) || (line_num == bottom)) {
				drawLine(width);
			} else {
				drawOuter(width);
			}
			break;

		case 1:
			drawRight(width);
			break;

		case 2:
			if ((line_num == 0) || (line_num == mid) || (line_num == bottom)) {
				drawLine(width);
			} else if (line_num < mid) {
				drawRight(width);
			} else {
				drawLeft(width);
			}
			break;

		case 3:
			if ((line_num == 0) || (line_num == mid) || (line_num == bottom)) {
				drawLine(width);
			} else {
				drawRight(width);
			}
			break;

		case 4:
			if (line_num == mid) {
				drawLine(width);
			} else if (line_num < mid) {
				drawOuter(width);
			} else {
				drawRight(width);
			}
			break;

		case 5:
			if ((line_num == 0) || (line_num == mid) | (line_num == bottom)) {
				drawLine(width);
			} else if (line_num < mid) {
				drawLeft(width);
			} else {
				drawRight(width);
			}
			break;

		case 6:
			if ((line_num == mid) || (line_num == bottom)){
				drawLine(width);
			} else if (line_num < mid) {
				drawLeft(width);
			} else {
				drawOuter(width);
			}
			break;

		case 7:
			if (line_num == 0) {
				drawLine(width);
			} else {
				drawRight(width);
			}
			break;

		case 8:
			if ((line_num == 0) || (line_num == mid) || (line_num == bottom)) {
				drawLine(width);
			} else {
				drawOuter(width);
			}
			break;

		case 9:
			if ((line_num == 0) || (line_num == mid)) {
				drawLine(width);
			} else if (line_num < mid) {
				drawOuter(width);
			} else {
				drawRight(width);
			}
			break;
	}

	printf(" ");
	return;
}

int main() {
	int tc;
	string form;
	cin >> tc >> form;

	vector<pair<int,string> > number_list(tc, make_pair(-1, "")); 
	int height_limit = 0;

	for (int t = 0; t < tc; t++) {
		cin >> number_list[t].first >> number_list[t].second;
		height_limit = max(height_limit, number_list[t].first * 2 - 1);
	}
	
	if (form == "TOP") {
		for (int h = 0; h < height_limit; h++) {
			int list_size = (int)number_list.size();
			for (int i = 0; i < list_size; i++) {
				string number = number_list[i].second;
				int width = number_list[i].first;
				int height = width * 2 - 1;
				
				int number_size = (int)number.size();
				for (int j = 0; j < number_size; j++) {
					if (h < height) {
						print(width, height, h, (int)(number[j] - '0'));
					} else {
						printNull(width);
					}
				}
			}
			printf("\n");
		}
	} else if (form == "BOTTOM") {
		for (int h = 0; h < height_limit; h++) {
			int list_size = (int)number_list.size();
			for (int i = 0; i < list_size; i++) {
				string number = number_list[i].second;
				int width = number_list[i].first;
				int height = width * 2 - 1;
					
				int number_size = (int)number.size();
				for (int j = 0; j < number_size; j++) {
					if (height_limit - height <= h) {
						print(width, height, h - height_limit + height, (int)(number[j] - '0'));
					} else {
						printNull(width);
					}
				}
			}
			printf("\n");
		}
	} else if (form == "MIDDLE") {
		for (int h = 0; h < height_limit; h++) {
			int list_size = (int)number_list.size();
			for (int i = 0; i < list_size; i++) {
				string number = number_list[i].second;
				int width = number_list[i].first;
				int height = width * 2 - 1;
				int draw_range = (height_limit - height) / 2;
				
				int number_size = (int)number.size();
				for (int j = 0; j < number_size; j++) {
					if ((draw_range <= h) && (h < height_limit - draw_range)) {
						print(width, height, h - draw_range, (int)(number[j] - '0'));
					} else {
						printNull(width);
					}
				}
			}
			printf("\n");
		}
	}

}
