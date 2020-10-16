#include <iostream>
#include <vector>
using namespace std;

#define LIMIT 1000000007

unsigned int square(unsigned int x, unsigned int n) {
	unsigned int ret = 1;
	for (int i = 0; i < n; i++) {
		ret = (ret * x) % LIMIT;
	}

	return ret;
}

unsigned int factorial(unsigned int x) {
	unsigned int ret = 1;
	for (int i = x; i > 0; i--) {
		ret = (ret * (unsigned int)i) % LIMIT;
	}

	return ret;
}

unsigned int mod_inverse(unsigned int a, unsigned int b) {
	vector<unsigned int> s, r, q;
	s.push_back(1); s.push_back(0);
	r.push_back(a); r.push_back(b);
	q.push_back(0);

	for (int i = 2;; i++) {
		q.push_back(r[i-2] / r[i-1]);
		r.push_back(r[i-2] % r[i-1]);

		if (r[i] == 0) {
			return (s[i-1] + b) % b;
		}

		s.push_back(s[i-2] - s[i-1] * q[i-1]);
	}

	return -1;
}

int main() {
	int L, N, M;
	vector<int> a, b;
	unsigned int s_and_m = 0, s_or_m = 0;
	unsigned int num_of_op = 0, num_of_case = 0;
	int tmp;
	cin >> L >> N;
	for (int n = 0; n < N; n++) {
		cin >> tmp; a.push_back(tmp);
	}
	cin >> M;
	for (int m = 0; m < M; m++) {
		cin >> tmp; b.push_back(tmp);
	}

	vector<int>::iterator a_iter = a.begin(), b_iter = b.begin();
	while (b_iter != b.end()) {
		if (*b_iter != *a_iter) {
			if (*b_iter == 1) {
				a_iter = a.erase(a_iter);
				a_iter = a.insert(a_iter, 2, 1);
				s_or_m++;
			} else {
				if (*(a_iter+1) == 1) {
					a.erase(a_iter+1);
					*a_iter = 2;
					s_or_m++;
				} else {
					a_iter = a.erase(a_iter+1);
					a_iter = a.insert(a_iter, 1) - 1;
					*a_iter = 2;
					s_and_m++;
				}
			}
		}

		a_iter++; b_iter++;
	}

	num_of_op = s_or_m + s_and_m * 2;

	num_of_case = ((factorial(num_of_op) % LIMIT) * mod_inverse(square(2, s_and_m), LIMIT)) % LIMIT;

	cout << s_or_m << " " << s_and_m << endl;


	cout << num_of_op << " " << num_of_case << endl;

	return 0;
}
