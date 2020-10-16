#include <iostream>
using namespace std;

int N, K;
int *c;

int merge() {
	
}

int split(int start, int end){
	if (end - start > 1) {
		split(start, (start + end) / 2);
		split((start + end) / 2 + 1, end);
	} else {
		merge(start, end);
	}
}

int main() {
	cin >> N;
	new int[N];
	
	for (int i = 0; i < N; i++) {
		cin >> c[i];
	}
	cin >> K;
	

	return 0;
}
