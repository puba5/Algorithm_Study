#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

#define D_SIZE 2
#define DIR_SIZE 4

typedef struct _rot_info {
	int d;
	int k;

	_rot_info() : d(0), k(0) {};
	_rot_info(int _d, int _k) : d(_d), k(_k) {};
} RotInfo;

typedef struct _cmd {
	int x;
	RotInfo rot_info;

	_cmd() : x(0), rot_info() {};
	_cmd(int _x, int _d, int _k) : x(_x), rot_info(_d, _k) {};
	_cmd(int _x, RotInfo _rot_info) : x(_x), rot_info(_rot_info) {};
} Cmd;

typedef struct _pos {
	int n;
	int m;

	_pos() : n(0), m(0) {};
	_pos(int _n, int _m) : n(_n), m(_m) {};
} Pos;


static int g_d[D_SIZE] = {
	1,
	-1
};

static Pos g_dir[DIR_SIZE] = {
	Pos(-1, 0),
	Pos(1, 0),
	Pos(0, -1),
	Pos(0, 1),
};

void solveOverflow(int &x, int MAX) {
	if (x >= MAX) {
		x = 0;
	} else if (x < 0) {
		x = MAX - 1;
	}
}

class Disk {
private:
	int N;
	int M;
	int remained;
	vector<vector<int> > num;

	bool erase();
	bool equalize();
	
	void rotateTrack(int track, int d, int k);
	bool changeNum();

	void deleteNum(int n, int m);

	void print();

public:
	Disk() : N(0), M(0), remained(0) {};
	Disk(int _N, int _M) : N(_N), M(_M), remained(_N * _M) { this->num.assign(_N, vector<int> (_M)); };

	void setN(int _N) { this->N = _N; };
	void setM(int _M) { this->M = _M; };
	void setNum(int n, int m, int _num) { this->num[n][m] = _num; };
	int getN() { return this->N; };
	int getM() { return this->M; };
	int getNum(int n, int m) { return this->num[n][m]; };

	bool rotateByCmd(int x, int d, int k);
	int sum();
};

bool Disk::erase() {
	bool is_changed = false;
	vector<vector<bool> > check(this->N, vector<bool> (this->M, false));
	vector<Pos> erase_list;

	for (int n = 0; n < this->N; n++) {
		for (int m = 0; m < this->M; m++) {
			if (check[n][m] == true) {
				continue;
			}

			queue<Pos> q;
			bool is_erased = false;
			q.push(Pos(n, m));
			check[n][m] = true;
			
			while (!q.empty()) {
				Pos pos = q.front(); q.pop();

				for (int d = 0; d < DIR_SIZE; d++) {
					Pos next_pos(pos.n + g_dir[d].n, pos.m + g_dir[d].m);
					solveOverflow(next_pos.m, this->M);

					if ((next_pos.n < 0) || (next_pos.n >= this->N) ||
						(this->num[next_pos.n][next_pos.m] == 0) ||
						(check[next_pos.n][next_pos.m] == true)) {
						continue;
					}

					if (this->num[next_pos.n][next_pos.m] == this->num[n][m]) {
						this->deleteNum(next_pos.n, next_pos.m);
						q.push(next_pos);
						check[next_pos.n][next_pos.m] = true;
						is_erased = true;
					}
				}
			}
			if (is_erased) {
				this->deleteNum(n, m);
				is_changed = true;
			}
		}
	}
	return is_changed;
}

bool Disk::equalize() {
	bool is_remained = false;
	double avg = (double) this->sum() / this->remained;

	for (int n = 0; n < this->N; n++) {
		for (int m = 0; m < this->M; m++) {
			if (this->num[n][m] == 0) {
				continue;
			}

			if ((double) this->num[n][m] > avg) {
				this->num[n][m] -= 1;
			} else if ((double) this->num[n][m] < avg) {
				this->num[n][m] += 1;
			}

		}
	}

	return (bool) this->remained;
}

void Disk::rotateTrack(int track, int d, int k) {
	for (int cnt = 0; cnt < k; cnt++) {
		vector<int> &track_num = this->num[track];
		int prev_num = track_num[0];
		int next_i = 0;
		for (int i = 0; i < this->M; i++) {
			next_i = next_i + g_d[d];
			solveOverflow(next_i, this->M);
			int tmp = track_num[next_i];
			track_num[next_i] = prev_num;
			prev_num = tmp;
		}
	}
}
bool Disk::changeNum() {
	if (this->erase() == false) {
		if (this->equalize() == false) {
			return false;
		}
	}

	return true;
}

void Disk::deleteNum(int n, int m) {
	this->num[n][m] = 0;
	this->remained -= 1;
}

bool Disk::rotateByCmd(int x, int d, int k) {
	for (int i = x; i <= this->N; i += x) {
		this->rotateTrack(i - 1, d, k);
	}

	if (this->changeNum() == false) {
		return false;
	}

	return true;
}

int Disk::sum() {
	int sum_of_num = 0;
	for (int n = 0; n < this->N; n++) {
		for (int m = 0; m < this->M; m++) {
			sum_of_num += this->num[n][m];
		}
	}

	return sum_of_num;
}


int main() {
	int N, M, T;
	scanf("%d %d %d", &N, &M, &T);

	Disk disk(N, M);
	vector<Cmd> cmd_list(T);

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			int num;
			scanf("%d", &num);
			disk.setNum(n, m, num);
		}
	}

	for (int t = 0; t < T; t++) {
		int x, d, k;
		scanf("%d %d %d", &x, &d, &k);

		if (disk.rotateByCmd(x, d, k) == false) {
			break;
		}
	}

	printf("%d\n", disk.sum());

	return 0;
}