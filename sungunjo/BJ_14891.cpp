#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define WHEEL_UPSIDE 0
#define WHEEL_RIGHT 2
#define WHEEL_LEFT 6

#define POLE_N 0
#define POLE_S 1

#define WHEEL_SIZE 8
#define NUMBER_OF_WHEEL 4

#define TURN_CLOCKWISE 1
#define TURN_COUNTER_CLOCKWISE -1

typedef struct _cmd {
	int wheel_number;
	int direction;

	_cmd() : wheel_number(0), direction(0) {};
	_cmd(int _wheel_number, int _direction) : wheel_number(_wheel_number), direction(_direction) {};
} Cmd;

void turnClockWise(deque<int> &wheel) {
	wheel.push_front(wheel.back());
	wheel.pop_back();
}

void turnCounterClockWise(deque<int> &wheel) {
	wheel.push_back(wheel.front());
	wheel.pop_front();
}

int getPoleAtWheelRight(const deque<int> &wheel) {
	return wheel[WHEEL_RIGHT];
}

int getPoleAtWheelLeft(const deque<int> &wheel) {
	return wheel[WHEEL_LEFT];
}

int getPoleAtWheelUpside(const deque<int> &wheel) {
	return wheel[WHEEL_UPSIDE];
}

int calcScore(const deque<int> wheels[NUMBER_OF_WHEEL]) {
	int sum = 0;
	int d = 1;
	for (int i = 0; i < NUMBER_OF_WHEEL; i++) {
		if (getPoleAtWheelUpside(wheels[i]) == POLE_S) {
			sum += d;
		}
		d *= 2;
	}

	return sum;
}

void changeTurnDirection(int &turn_direction) {
	turn_direction *= (-1);
}

void simulation(deque<int> wheels[NUMBER_OF_WHEEL], const Cmd &cmd) {
	vector<Cmd> turn_list;
	int turn_driection = cmd.direction;
	turn_list.push_back(Cmd(cmd.wheel_number, cmd.direction));

	for (int i = cmd.wheel_number + 1; i < NUMBER_OF_WHEEL; i++) {
		if (getPoleAtWheelRight(wheels[i - 1]) == getPoleAtWheelLeft(wheels[i])) {
			break;
		}
		changeTurnDirection(turn_driection);
		turn_list.push_back(Cmd(i, turn_driection));
	}

	turn_driection = cmd.direction;
	for (int i = cmd.wheel_number - 1; i >= 0; i--) {
		if (getPoleAtWheelLeft(wheels[i + 1]) == getPoleAtWheelRight(wheels[i])) {
			break;
		}
		changeTurnDirection(turn_driection);
		turn_list.push_back(Cmd(i, turn_driection));
	}

	for (int i = 0; i < turn_list.size(); i++) {
		if (turn_list[i].direction == TURN_CLOCKWISE) {
			turnClockWise(wheels[turn_list[i].wheel_number]);
		} else {
			turnCounterClockWise(wheels[turn_list[i].wheel_number]);
		}
	}
}

int solution(deque<int> wheels[NUMBER_OF_WHEEL], const vector<Cmd> &cmd_list) {
	for (int i = 0; i < cmd_list.size(); i++) {
		simulation(wheels, cmd_list[i]);
	}
	return calcScore(wheels);
}

int main() {
	deque<int> wheels[NUMBER_OF_WHEEL];
	for (int i = 0; i < NUMBER_OF_WHEEL; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < WHEEL_SIZE; j++) {
			wheels[i].push_back((int) (input[j] - '0'));
		}
	}

	int K;
	cin >> K;
	vector<Cmd> cmd_list(K);
	for (int k = 0; k < K; k++) {
		int wheel_number, direction;
		cin >> cmd_list[k].wheel_number >> cmd_list[k].direction;
		cmd_list[k].wheel_number -= 1;
	}
	cout << solution(wheels, cmd_list) << "\n";

	return 0;
}