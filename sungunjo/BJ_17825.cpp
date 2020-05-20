#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define IOS_SETTING \
ios::sync_with_stdio(false); \
cin.tie(NULL); \
cout.tie(NULL);

#define NUM_OF_HORSE 4
#define NUM_OF_DICE 10

#define HORSE_OVERLAPPED -1

typedef struct _place {
	int score;
	bool is_blue;
	
	_place *red_road;
	_place *blue_road;

	_place() : score(0), is_blue(false), red_road(nullptr), blue_road(nullptr) {};
	_place(int _score, bool _is_blue, _place *_red_road, _place *_blue_road) : score(_score), is_blue(_is_blue), red_road(_red_road), blue_road(_blue_road) {};

} Place;

class Game {
private: 
	Place *start;
	Place *end;

	Place **horse_pos;

public:
	Game();
	Place *getPosOf(int horse_id);
	int moveForward(int horse_id, int move_dist);
	int moveTo(int horse_id, Place *dst);
	bool isOverlapped(int horse_id, Place *pos);
	bool isReachedEnd(int horsed_id);
};

int go(Game &game, const int *dice, int dice_idx, int total_score) {
	if (dice_idx == NUM_OF_DICE) {
		return total_score;
	}

	int max_total_score = 0;
	for (int i = 0; i < NUM_OF_HORSE; i++) {
		// 결승점 간 말은 안움직임
		if (game.isReachedEnd(i) == true) {
			continue;
		}

		// 원래 위치 기억
		Place *prev_pos = game.getPosOf(i);
		// 이동
		int score = game.moveForward(i, dice[dice_idx]);
		// 겹치면 안감
		if (score == HORSE_OVERLAPPED) {
			continue;
		}
		// 다음 주사위 이동해봐서 제일 큰 점수 저장
		max_total_score = max(max_total_score, go(game, dice, dice_idx + 1, total_score + score));
		// 말 원래 위치로 복귀
		game.moveTo(i, prev_pos);
	}

	return max_total_score;
}

int main() {
	IOS_SETTING

	Game game;
	int dice[NUM_OF_DICE];
	for (int i = 0; i < NUM_OF_DICE; i++) {
		cin >> dice[i];
	}

	cout << go(game, dice, 0, 0) << "\n";

	return 0;
}

Game::Game() {
	/* 게임판 세팅 */
	// 결승점
	(*this).end = new Place(0, false, nullptr, nullptr);

	// 결승점 직전 발판
	Place *end_prev = new Place(40, false, (*this).end, nullptr);

	// 외곽 길
	Place *out_line = new Place(38, false, end_prev, nullptr);
	out_line = new Place(36, false, out_line, nullptr);
	out_line = new Place(34, false, out_line, nullptr);
	out_line = new Place(32, false, out_line, nullptr);

	// 오른쪽 파란 발판
	Place *right_blue = new Place(30, true, out_line, nullptr);

	out_line = new Place(28, false, right_blue, nullptr);
	out_line = new Place(26, false, out_line, nullptr);
	out_line = new Place(24, false, out_line, nullptr);
	out_line = new Place(22, false, out_line, nullptr);

	// 아래쪽 파란 발판
	Place *down_blue = new Place(20, true, out_line, nullptr);

	out_line = new Place(18, false, down_blue, nullptr);
	out_line = new Place(16, false, out_line, nullptr);
	out_line = new Place(14, false, out_line, nullptr);
	out_line = new Place(12, false, out_line, nullptr);

	// 왼쪽 파란 발판
	Place *left_blue = new Place(10, true, out_line, nullptr);

	out_line = new Place(8, false, left_blue, nullptr);
	out_line = new Place(6, false, out_line, nullptr);
	out_line = new Place(4, false, out_line, nullptr);
	out_line = new Place(2, false, out_line, nullptr);

	// 시작점
	(*this).start = new Place(0, false, out_line, nullptr);


	// 안쪽 길
	Place *inner_line = new Place(35, false, end_prev, nullptr);
	inner_line = new Place(30, false, inner_line, nullptr);

	// 중심
	Place *center = new Place(25, false, inner_line, nullptr);

	// 안쪽 왼쪽 길
	Place *left_line = new Place(19, false, center, nullptr);
	left_line = new Place(16, false, left_line, nullptr);
	left_line = new Place(13, false, left_line, nullptr);
	
	// 왼쪽 파란 발판 파란 길 연결
	(*left_blue).blue_road = left_line;

	// 안쪽 아래 길
	Place *down_line = new Place(24, false, center, nullptr);
	down_line = new Place(22, false, down_line, nullptr);
	
	// 아래쪽 파란 발판 파란 길 연결
	(*down_blue).blue_road = down_line;

	// 안쪽 오른쪽 길
	Place *right_line = new Place(26, false, center, nullptr);
	right_line = new Place(27, false, right_line, nullptr);
	right_line = new Place(28, false, right_line, nullptr);

	// 오른쪽 파란 발판 파란 길 연결
	(*right_blue).blue_road = right_line;


	/* 말 세팅 */
	(*this).horse_pos = new Place*[NUM_OF_HORSE];
	for (int i = 0; i < NUM_OF_HORSE; i++) {
		(*this).horse_pos[i] = (*this).start;
	}
}

Place *Game::getPosOf(int horse_id) {
	return (*this).horse_pos[horse_id];
}

int Game::moveForward(int horse_id, int move_dist) {
	Place *new_pos = (*this).horse_pos[horse_id];

	if ((*new_pos).is_blue == true) {
		// 파란 발판에서 시작하면 파란 길로
		new_pos = (*new_pos).blue_road;
		move_dist -= 1;
	}

	for (int i = 0; i < move_dist; i++) {
		// 빨간 길로 이동
		new_pos = (*new_pos).red_road;
		// 도착했으면 끝
		if (new_pos == (*this).end) {
			return (*this).moveTo(horse_id, new_pos);;
		}
	}

	// 다른 말이랑 겹쳐졌으면 이동 안함
	if ((*this).isOverlapped(horse_id, new_pos) == true) {
		return HORSE_OVERLAPPED;
	}

	// 제대로 도착했으면 점수 리턴
	return (*this).moveTo(horse_id, new_pos);
}

int Game::moveTo(int horse_id, Place *dst) {
	(*this).horse_pos[horse_id] = dst;
	return (*(*this).horse_pos[horse_id]).score;
}

bool Game::isOverlapped(int horse_id, Place *pos) {
	for (int i = 0; i < NUM_OF_HORSE; i++) {
		if ((i != horse_id) && ((*this).horse_pos[i] == pos)) {
			return true;
		}
	}

	return false;
}

bool Game::isReachedEnd(int horse_id) {
	if ((*this).horse_pos[horse_id] == (*this).end) {
		return true;
	} else {
		return false;
	}
}