#include <iostream>
#include <vector>
using namespace std;

void getNumberArray(vector<int> &arr, int size) {
	for (int i = 0; i < size; i++) {
		scanf("%d", &(arr[i]));
	}
}

bool binarySearch(const vector<int> &arr, int num) {
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == num) {
			return true;
		} else if (arr[mid] > num) {
			right = mid - 1;
		} else if (arr[mid] < num) {
			left = mid + 1;
		}
	}
	return false;
}

int main() {
	int N, M;

	scanf("%d", &N);
	vector<int> A(N, 0);
	getNumberArray(A, N);
	sort(A.begin(), A.end());
	scanf("%d", &M);
	vector<int> numbers(M, 0);
	getNumberArray(numbers, M);

	for (int m = 0; m < M; m++) {
		printf("%d\n", (int) binarySearch(A, numbers[m]));
	}
}
