#include <iostream>
#include <vector>
#include <utility>
using namespace std;


void move(vector<pair<int, int> > &move_list, int from, int to) {
	move_list.push_back(make_pair(from, to));
}

void hanoi(vector<pair<int, int> > &move_list, int N, int from, int via, int to) {
	if (N == 1) {
		move(move_list, from, to);
	} else {
		hanoi(move_list, N - 1, from, to, via);
		move(move_list, from, to);
		hanoi(move_list, N - 1, via, from, to);
	}
}

int main() {
	int N;
	scanf("%d", &N);

	vector<pair<int, int> > move_list;

	hanoi(move_list, N, 1, 2, 3);

	printf("%lu\n", move_list.size());
	for (int i = 0; i < move_list.size(); i++) {
		printf("%d %d\n", move_list[i].first, move_list[i].second);
	}

	return 0;
}