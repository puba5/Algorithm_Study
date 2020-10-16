#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

int main() {
	pair<int, string> alb[25];
	alb[0] = make_pair(1967, "DavidBowie");
        alb[1] = make_pair(1969, "SpaceOddity");
        alb[2] = make_pair(1970, "TheManWhoSoldTheWorld");
        alb[3] = make_pair(1971, "HunkyDory");
        alb[4] = make_pair(1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
        alb[5] = make_pair(1973, "AladdinSane");
        alb[6] = make_pair(1973, "PinUps");
        alb[7] = make_pair(1974, "DiamondDogs");
        alb[8] = make_pair(1975, "YoungAmericans");
        alb[9] = make_pair(1976, "StationToStation");
        alb[10] = make_pair(1977, "Low");
        alb[11] = make_pair(1977, "Heroes");
        alb[12] = make_pair(1979, "Lodger");
        alb[13] = make_pair(1980, "ScaryMonstersAndSuperCreeps");
        alb[14] = make_pair(1983, "LetsDance");
        alb[15] = make_pair(1984, "Tonight");
        alb[16] = make_pair(1987, "NeverLetMeDown");
        alb[17] = make_pair(1993, "BlackTieWhiteNoise");
        alb[18] = make_pair(1995, "1.Outside");
        alb[19] = make_pair(1997, "Earthling");
        alb[20] = make_pair(1999, "Hours");
        alb[21] = make_pair(2002, "Heathen");
        alb[22] = make_pair(2003, "Reality");
        alb[23] = make_pair(2013, "TheNextDay");
        alb[24] = make_pair(2016, "BlackStar");

	int Q;
	int count[100];
	queue<pair<int, string> > q[100];
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int S, E;
		cin >> S >> E;
		
		count[i] = 0;
		for (int j = 0; j < 25; j++) {
			if (alb[j].first < S) {
				continue;
			} else if (E < alb[j].first) {
				break;
			} else {
				count[i]++;
				q[i].push(alb[j]);
			}
		}
	}
	for (int i = 0; i < Q; i++) {
		cout << count[i] << endl;
		while(!q[i].empty()) {
			cout << q[i].front().first << " " << q[i].front().second << endl;
			q[i].pop();
		}
	}
	return 0;
}
