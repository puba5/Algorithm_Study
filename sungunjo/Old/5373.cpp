#include <iostream>
#include <cstring>
using namespace std;

int T;
int n;
char ans[100][3][3];

void rot_right(char cube[][3]) {
	char temp[3][3];
	temp[0][0] = cube[0][0]; temp[0][1] = cube[0][1]; temp[0][2] = cube[0][2];
	cube[0][2] = cube[0][0]; cube[0][1] = cube[1][0]; cube[0][0] = cube[2][0];
	cube[0][0] = cube[2][0]; cube[1][0] = cube[2][1]; cube[2][0] = cube[2][2];
	cube[2][0] = cube[2][2]; cube[2][1] = cube[1][2]; cube[2][2] = temp[0][2];
	cube[2][2] = temp[0][2]; cube[1][2] = temp[0][1]; cube[0][2] = temp[0][0];
}

void rot_left(char cube[][3]) {
	char temp[3][3];
	temp[0][0] = cube[0][0]; temp[0][1] = cube[0][1]; temp[0][2] = cube[0][2];
	cube[0][0] = cube[0][2]; cube[0][1] = cube[1][2]; cube[0][2] = cube[2][2];
	cube[0][2] = cube[2][2]; cube[1][2] = cube[2][1]; cube[2][2] = cube[2][0];
	cube[2][2] = cube[2][0]; cube[2][1] = cube[1][0]; cube[2][0] = temp[0][0];
	cube[2][0] = temp[0][0]; cube[1][0] = temp[0][1]; cube[0][0] = temp[0][2];
}

void rotate(char rot, char dir, char up[][3], char down[][3], char front[][3], char back[][3], char left[][3], char right[][3]) {
	char temp[3][3];
	if (rot == 'U') {
		if (dir == '+') {
			temp[0][0] = left[0][0]; temp[0][1] = left[0][1]; temp[0][2] = left[0][2];
			left[0][0] = front[0][0]; left[0][1] = front[0][1]; left[0][2] = front[0][2];
			front[0][0] = right[0][0]; front[0][1] = right[0][1]; front[0][2] = right[0][2];
			right[0][0] = back[0][0]; right[0][1] = back[0][1]; right[0][2] = back[0][2];
			back[0][0] = temp[0][0]; back[0][1] = temp[0][1]; back[0][2] = temp[0][2];

			rot_right(up);
		} else {
			temp[0][0] = back[0][0]; temp[0][1] = back[0][1]; temp[0][2] = back[0][2];
			back[0][0] = right[0][0]; back[0][1] = right[0][1]; back[0][2] = right[0][2];
			right[0][0] = front[0][0]; right[0][1] = front[0][1]; right[0][2] = front[0][2];
			front[0][0] = left[0][0]; front[0][1] = left[0][1]; front[0][2] = left[0][2];
			left[0][0] = temp[0][0]; left[0][1] = temp[0][1]; left[0][2] = temp[0][2];

			rot_left(up);
		}

	} else if (rot == 'D') {
		if (dir == '+') {
			temp[2][0] = back[2][0]; temp[2][1] = back[2][1]; temp[2][2] = back[2][2];
			back[2][0] = right[2][0]; back[2][1] = right[2][1]; back[2][2] = right[2][2];
			right[2][0] = front[2][0]; right[2][1] = front[2][1]; right[2][2] = front[2][2];
			front[2][0] = left[2][0]; front[2][1] = left[2][1]; front[2][2] = left[2][2];
			left[2][0] = temp[2][0]; left[2][1] = temp[2][1]; left[2][2] = temp[2][2];

			rot_right(down);
		} else {
			temp[2][0] = left[2][0]; temp[2][1] = left[2][1]; temp[2][2] = left[2][2];
			left[2][0] = front[2][0]; left[2][1] = front[2][1]; left[2][2] = front[2][2];
			front[2][0] = right[2][0]; front[2][1] = right[2][1]; front[2][2] = right[2][2];
			right[2][0] = back[2][0]; right[2][1] = back[2][1]; right[2][2] = back[2][2];
			back[2][0] = temp[2][0]; back[2][1] = temp[2][1]; back[2][2] = temp[2][2];

			rot_left(down);
		}
	} else if (rot == 'F') {
		if (dir == '+') {
			temp[0][0] = right[0][0]; temp[1][0] = right[1][0]; temp[2][0] = right[2][0];
			right[0][0] = up[2][0]; right[1][0] = up[2][1]; right[2][0] = up[2][2];
			up[2][0] = left[2][2]; up[2][1] = left[1][2]; up[2][2] = left[0][2];
			left[0][2] = down[0][0]; left[1][2] = down[0][1]; left[2][2] = down[0][2];
			down[0][0] = temp[2][0]; down[0][1] = temp[1][0]; down[0][2] = temp[0][0];

			rot_right(front);
		} else {
			temp[0][0] = down[0][0]; temp[0][1] = down[0][1]; temp[0][2] = down[0][2];
			down[0][0] = left[0][2]; down[0][1] = left[1][2]; down[0][2] = left[2][2];
			left[0][2] = up[2][2]; left[1][2] = up[2][1]; left[2][2] = up[2][0];
			up[2][0] = right[0][0]; up[2][1] = right[1][0]; up[2][2] = right[2][0];
			right[0][0] = temp[0][2]; right[1][0] = temp[0][1]; right[2][0] = temp[0][0];

			rot_left(front);
		}
	} else if (rot == 'B') {
		if (dir == '+') {
			temp[0][0] = left[0][0]; temp[1][0] = left[1][0]; temp[2][0] = left[2][0];
			left[0][0] = up[0][2]; left[1][0] = up[0][1]; left[2][0] = up[0][0];
			up[0][0] = right[0][2]; up[0][1] = right[1][2]; up[0][2] = right[2][2];
			right[0][2] = down[2][2]; right[1][2] = down[2][1]; right[2][2] = down[2][0];
			down[2][0] = temp[0][0]; down[2][1] = temp[1][0]; down[2][2] = temp[2][0];

			rot_right(back);

		} else {
			temp[0][2] = right[0][2]; temp[1][2] = right[1][2]; temp[2][2] = right[2][2];
			right[0][2] = up[0][0]; right[1][2] = up[0][1]; right[2][2] = up[0][2];
			up[0][0] = left[2][0]; up[0][1] = left[1][0]; up[0][2] = left[0][0];
			left[0][0] = down[2][0]; left[1][0] = down[2][1]; left[2][0] = down[2][2];
			down[2][0] = temp[2][2]; down[2][1] = temp[1][2]; down[2][2] = temp[0][2];

			rot_left(back);
		}
	} else if (rot == 'L') {
		if (dir == '+') {
			temp[2][2] = back[2][2]; temp[1][2] = back[1][2]; temp[0][2] = back[0][2];
			back[2][2] = down[0][0]; back[1][2] = down[1][0]; back[0][2] = down[2][0];
			down[0][0] = front[0][0]; down[1][0] = front[1][0]; down[2][0] = front[2][0];
			front[0][0] = up[0][0]; front[1][0] = up[1][0]; front[2][0] = up[2][0];
			up[0][0] = temp[2][2]; up[1][0] = temp[1][2]; up[2][0] = temp[0][2];

			rot_right(left);
		} else {
			temp[0][0] = up[0][0]; temp[1][0] = up[1][0]; temp[2][0] = up[2][0];
			up[0][0] = front[0][0]; up[1][0] = front[1][0]; up[2][0] = front[2][0];
			front[0][0] = down[0][0]; front[1][0] = down[1][0]; front[2][0] = down[2][0];
			down[0][0] = back[2][2]; down[1][0] = back[1][2]; down[2][0] = back[0][2];
			back[2][2] = temp[0][0]; back[1][2] = temp[1][0]; back[0][2] = temp[2][0];

			rot_left(left);
		}
	} else if (rot == 'R') {
		if (dir == '+') {
			temp[0][2] = up[0][2]; temp[1][2] = up[1][2]; temp[2][2] = up[2][2];
			up[0][2] = front[0][2]; up[1][2] = front[1][2]; up[2][2] = front[2][2];
			front[0][2] = down[0][2]; front[1][2] = down[1][2]; front[2][2] = down[2][2];
			down[0][2] = back[2][0]; down[1][2] = back[1][0]; down[2][2] = back[0][0];
			back[2][0] = temp[0][2]; back[1][0] = temp[1][2]; back[0][0] = temp[2][2];

			rot_right(right);
		} else {
			temp[2][0] = back[2][0]; temp[1][0] = back[1][0]; temp[0][0] = back[0][0];
			back[2][0] = down[0][2];  back[1][0] = down[1][2]; back[0][0] = down[2][2];
			down[0][2] = front[0][2]; down[1][2] = front[1][2]; down[2][2] = front[2][2];
			front[0][2] = up[0][2]; front[1][2] = up[1][2]; front[2][2] = up[2][2];
			up[0][2] = temp[2][0]; up[1][2] = temp[1][0]; up[2][2] = temp[0][0];

			rot_left(right);

		}
	}

}

void init(char cube[][3], char color) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[i][j] = color;
		}
	}
}

int main() {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;

		char up[3][3], down[3][3], front[3][3], back[3][3], left[3][3], right[3][3];

		init(up, 'w'); init(down, 'y'); init(front, 'r'); init(back, 'o'); init(left, 'g'); init(right, 'b');
		for (int k = 0; k < n; k++) {
			char rot, dir;
			cin >> rot >> dir;

			rotate(rot, dir, up, down, front, back, left, right);
		}
		for (int i = 0; i < 3; i++) {
			memcpy(ans[t][i], up[i], sizeof(up[i]));
		}
	}

	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << ans[t][i][j];
			}
			cout << endl;
		}
	}

}
