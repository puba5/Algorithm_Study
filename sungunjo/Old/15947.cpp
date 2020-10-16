#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int N;
	cin >> N;
	N--;

	vector<string> song;
	song.push_back("baby"); song.push_back("sukhwan"); song.push_back("tururu"); song.push_back("turu");
	song.push_back("very"); song.push_back("cute"); song.push_back("tururu"); song.push_back("turu");
	song.push_back("in"); song.push_back("bed"); song.push_back("tururu"); song.push_back("turu");
	song.push_back("baby"); song.push_back("sukhwan");
	
	int word_index = N % 14;
	int loop_cnt = N / 14;

	if (song[word_index] == "tururu") {
		if (loop_cnt >= 3) {
			cout << "tu+ru*" << loop_cnt + 2 << endl;
		} else {
			cout << song[word_index];
			for (int i = 0; i < loop_cnt; i++) {
				cout << "ru";
			}
			cout << endl;
		}
	} else if (song[word_index] == "turu") {
		if (loop_cnt >= 4) {
			cout << "tu+ru*" << loop_cnt + 1 << endl;
		} else {
			cout << song[word_index];
			for (int i = 0; i < loop_cnt; i++) {
				cout << "ru";
			}
			cout << endl;
		}
	} else {
		cout << song[word_index] << endl;
	}

	return 0;
}
