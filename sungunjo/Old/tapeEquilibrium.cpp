// you can use includes, for example:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    int sum = 0;
    
    for (int i = 1; i < len; i++) {
        sum += A[i];
    }
    
	int isBig = false;
	int diff;
	if (A[0] > sum) {
		isBig = true;
		diff = A[0] - sum;
	} else {
		isBig = false;
		diff = sum - A[0];
	}
    int min_diff = diff;
    
    for (int i = 2; i < len; i++) {
		if (isBig) {
			diff = diff + 2 * A[i-1];
		} else {
	        diff = diff - 2 * A[i-1];
		}

		if (diff <= 0) {
			isBig = !isBig;
			diff *= -1;
		}
        min_diff = min(min_diff, diff);
    }
    
    return min_diff;
}

int main() {
	int N;
	vector<int> A;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}

	cout << solution(A) << endl;
}
