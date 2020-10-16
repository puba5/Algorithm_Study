#include <iostream>
#include <vector>
using namespace std;

#define MAX 200000000

int N;
int J[1000001];
vector<int> loop;
bool loop_founded[1000001];


void find_loop() {
	for (int i = 1; i <= N; i++) {
		if (loop_founded[i]) {
			continue;
		}
		int count = 0;
		vector<int> loop_record;
		loop_record.push_back(i);
		loop_founded[i] = true;
		count++;
		int k = J[i];
		for (int m = 0; m < 1000000; m++) {
			bool fin = false;
			if (loop_record[0] == k) {
				loop.push_back(count);
				break;
			}
			for (int j = 1; j < loop_record.size(); j++) {
				if (loop_record[j] == k) {
					loop.push_back(count-j);
					fin = true;
					break;
				}
			}
			if (fin) {
				break;
			} else {
				loop_record.push_back(k);
				loop_founded[k] = true;
				count++;
				k = J[k];
			}
		}
	}
}

int ans() {
	for (int i = 2; i <= MAX; i++) {
		bool ans = true;
		for (int j = 0; j < loop.size(); j++) {
			if (i % loop[j] == 0) {
				ans = false;
				break;
			}
		}
		if (ans) {
			return i;
		}
	}
	return -1;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> J[i];
		if (i == J[i]) {
			cout << -1 << endl;
			return 0;
		}
	}

	find_loop();
	cout << ans() << endl;

}
