#include<iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <array>
#include <set>
#define ll long long

using namespace std;	

void Spin(vector< vector<char> > &v, int n, int cnt) {
	vector< vector<char> > vec(n, vector<char>(n));

	for (auto i = 0; i <= n - 1; i++) {
		for (auto j = 0; j <= n - 1; j++) {
			// 1
			if (cnt == 1 || cnt == 3)
				vec[n - 1 - j][n - 1 - i] = v[i][j];
			// 2
			else 
				vec[j][n - 1 - i] = v[i][j];
		}
	}

	for (auto i = 0; i <= n - 1; i++) {
		for (auto j = 0; j <= n - 1; j++) {
			v[i][j] = vec[i][j];
		}
	}
}

void Slide(vector< vector<char> > &v, int n) {
	vector< vector<char> > vec(n, vector<char>(n, '.'));

	for (auto i = n - 1; i >= 0; i--) {
		int k = n - 1;
		for (auto j = n - 1; j >= 0; j--) {
			if (v[j][i] != '.') {
				vec[k][i] = v[j][i];
				k--;
			}
		}
	}
	for (auto i = 0; i <= n - 1; i++) {
		for (auto j = 0; j <= n - 1; j++) {
			v[i][j] = vec[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector< vector<char> > v(n, vector<char>(n));

	for (auto i = 0; i < n; i++) {
		for (auto j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	// 돌리고 밀고
	int counter = 0;
	while (m--) {
		counter++;
		Spin(v, n, counter%4);
		Slide(v, n);
	}

	for (auto i = 0; i < n; i++) {
		for (auto j = 0; j < n; j++) {
			cout << v[i][j];
		}
		cout << '\n';
	}
}

