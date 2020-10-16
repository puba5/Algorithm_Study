#include <iostream>
#include <vector>
using namespace std;

const int dr[4] = {-1, 0, 1,  0};
const int dc[4] = { 0, 1, 0, -1};

void print(vector<vector<int> > &room){
	for (int r = 0; r < room.size(); r++) {
		for (int c = 0; c < room[0].size(); c++) {
			printf("%d ", room[r][c]);
		}
		printf("\n");
	}
}

void diffuse(vector<vector<int> > &room, int R, int C) {
	vector<vector<int> > temp(R, vector<int> (C));
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (room[r][c] == -1) {
				continue;
			}
			int diffuse_amount = room[r][c] / 5;
			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d], nc = c + dc[d];
				if ((nr < 0) || (R <= nr) || (nc < 0) || (C <= nc) || (room[nr][nc] == -1)) {
					continue;
				}
				temp[r][c] -= diffuse_amount;
				temp[nr][nc] += diffuse_amount;
			}
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			room[r][c] += temp[r][c];
		}
	}
}

void refresh(vector<vector<int> > &room, int R, int C) {
	int r = 0, c = 0, d = 2;
	int pr, pc;
	int save = room[r][c];
	do {
		pr = r; pc = c;
		r += dr[d]; c += dc[d];
		
		if ((r < 0) || (c < 0) || (C <= c)) {
			d = (d + 3) % 4;
			r = pr + dr[d]; c = pc + dc[d];
		} else if (room[r][c] == -1) {
			d = (d + 3) % 4;
			save = 0;
			continue;
		}
		int temp = room[r][c];
		room[r][c] = save;
		save = temp;
	} while ((r != 0) || (c != 0));

	r = R - 1; c = 0; d = 0;
	save = room[r][c];
	do {
		pr = r; pc = c;
		r += dr[d]; c += dc[d];

		if ((R <= r) || (c < 0) || (C <= c)) {
			d += 1;
			r = pr + dr[d]; c = pc + dc[d];
		} else if (room[r][c] == -1) {
			d += 1;
			save = 0;
			continue;
		}
		int temp = room[r][c];
		room[r][c] = save;
		save = temp;
	} while ((r != R - 1) || (c != 0));
}

int addAll(const vector<vector<int> > &room, int R, int C) {
	int sum = 2;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			sum += room[r][c];
		}
	}
	return sum;
}

int simul(vector<vector<int> > &room, int R, int C, int T) {
	for (int t = 0; t < T; t++) {
		diffuse(room, R, C);
		refresh(room, R, C);
	}

	return addAll(room, R, C);
}

int main() {
	int R, C, T;
	scanf("%d %d %d", &R, &C, &T);
	vector<vector<int> > room(R, vector<int> (C));
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			scanf("%d", &room[r][c]);
		}
	}

	printf("%d\n", simul(room, R, C, T));

	return 0;
}
