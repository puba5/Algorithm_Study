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
cin.tie(NULL); cout.tie(NULL);

#define MAX_OUT_CNT 3
#define NUM_OF_BATTER 9

#define FAVORITE_BATTER 0
#define CLEANUP_HITTER 3

typedef enum _bat {
	BAT_OUT = 0,
	BAT_SINGLE_HIT,
	BAT_DOUBLE_HIT,
	BAT_TRIPLE_HIT,
	BAT_HOMERUN,

	RESUHLT_SIZE
} Bat;

typedef enum _base {
	HOME_BASE = 0,
	FIRST_BASE,
	SECOND_BASE,
	THIRD_BASE,

	BASE_SIZE,
} Base;

void nextBatter(int &current_batter) {
	current_batter = (current_batter + 1) % NUM_OF_BATTER;
}

int hit(vector<bool> &runner_in, Bat bat_result) {
	int score = 0;
	int advance = (int) bat_result;
	for (int i = (int) THIRD_BASE; i > (int) THIRD_BASE - advance; i--) {
		if (runner_in[i] == true) {
			runner_in[i] = false;
			score += 1;
		}
	}
	
	for (int i = (int) THIRD_BASE; i >= advance; i--) {
		if (runner_in[i - advance] == true) {
			runner_in[i] = true;
			runner_in[i - advance] = false;
		}
	}

	return score;
}

int playInning(const vector<Bat> &inning_results, const vector<int> &lineup, int &current_batter) {
	int out_cnt = 0;
	int score = 0;
	vector<bool> runner_in(BASE_SIZE, false);

	while (out_cnt < MAX_OUT_CNT) {
		runner_in[HOME_BASE] = true;
		Bat bat_result = inning_results[lineup[current_batter]];
		if (bat_result == BAT_OUT) {
			runner_in[HOME_BASE] = false;
			out_cnt += 1;
		} else {
			score += hit(runner_in, bat_result);
		}
		nextBatter(current_batter);
	}

	return score;
}

int simulation(const vector<vector<Bat> > &inning_results, const vector<int> &lineup) {
	int N = inning_results.size();
	int score = 0;
	int current_batter = 0;
	for (int inning = 0; inning < N; inning++) {
		score += playInning(inning_results[inning], lineup, current_batter);
	}

	return score;
}

int go(const vector<vector<Bat> > &inning_results, vector<int> &lineup, int lineup_idx, vector<bool> &fixed_lineup) {
	if (lineup_idx == NUM_OF_BATTER) {
		return simulation(inning_results, lineup);
	} else if (lineup_idx == CLEANUP_HITTER) {
		lineup_idx += 1;
	}

	int max_score = 0;
	for (int i = 0; i < NUM_OF_BATTER; i++) {
		if (fixed_lineup[i] == true) {
			continue;
		}

		lineup[lineup_idx] = i;
		fixed_lineup[i] = true;
		int score = go(inning_results, lineup, lineup_idx + 1, fixed_lineup);
		max_score = max(max_score, score);
		fixed_lineup[i] = false;
	}

	return max_score;
}

int solution(const vector<vector<Bat> > &inning_results) {
	vector<int> lineup(NUM_OF_BATTER, 0);
	vector<bool> fixed_lineup(NUM_OF_BATTER, false);

	lineup[CLEANUP_HITTER] = FAVORITE_BATTER;
	fixed_lineup[FAVORITE_BATTER] = true;

	return go(inning_results, lineup, 0, fixed_lineup);
}


int main() {
	IOS_SETTING

	int N;
	cin >> N;

	vector<vector<Bat> > inning_results(N, vector<Bat> (NUM_OF_BATTER, BAT_OUT));

	for (int n = 0; n < N; n++) {
		for (int i = 0; i < NUM_OF_BATTER; i++) {
			int input;
			cin >> input;
			inning_results[n][i] = (Bat) input;
		}
	}

	cout << solution(inning_results) << "\n";

	return 0;
}
