#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

#define IOS_SETTING \
ios::sync_with_stdio(false);\
cin.tie(NULL);\
cout.tie(NULL);


void parseNum(string x, deque<int> &dq) {
	if (x.size() < 3) {
		return;
	}

	int prev = 1, cur = x.find(',');
	while (cur != string::npos){
		dq.push_back(stoi(x.substr(prev, cur - prev)));
		prev = cur + 1;
		cur = x.find(',', prev);
	}
	dq.push_back(stoi(x.substr(prev, x.size() - 1 - prev)));
}

bool doR(deque<int> &dq, bool &reversed) {
	reversed = !reversed;
	return true;
}

bool doD(deque<int> &dq, bool reversed) {
	if (dq.empty() == true) {
		return false;
	}

	if (reversed == true) {
		dq.pop_back();
	} else {
		dq.pop_front();
	}
	return true;
}

bool doOperation(deque<int> &dq, bool &reversed, char pi) {
	if (pi == 'R') {
		return doR(dq, reversed);
	} else if (pi == 'D') {
		return doD(dq, reversed);
	} else {
		return false;
	}
}

void printForward(const deque<int> &dq) {
	for (int i = 0; i < dq.size(); i++) {
		cout << dq[i];
		if (i + 1 < dq.size()) {
			cout << ",";
		}
	}	
}

void printBackward(const deque<int> &dq) {
	for (int i = dq.size() - 1; i >= 0; i--) {
		cout << dq[i];
		if (i - 1 >= 0) {
			cout << ",";
		}
	}	
}

void print(const deque<int> &dq, bool reversed) {
	cout << "[";
	if (reversed == true) {
		printBackward(dq);
	} else {
		printForward(dq);
	}
	cout << "]\n";
}

void solution() {
	string p, x;
	int n;
	cin >> p >> n >> x;

	deque<int> dq;
	parseNum(x, dq);
	bool reversed = false;
	for (int i = 0; i < p.size(); i++) {
		bool op_result = doOperation(dq, reversed, p[i]);
		if (op_result == false) {
			cout << "error\n";
			return;
		}
	}
	print(dq, reversed);
}

int main() {
    IOS_SETTING

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		solution();
	}

	return 0;
}