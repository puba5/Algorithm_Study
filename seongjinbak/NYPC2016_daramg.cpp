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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	cin.ignore();

	vector<vector<char> > v(n, vector<char>(n));

	int playerCnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'C') {
				playerCnt++;
			}
		}
	}
	
	int squirrelCnt = playerCnt * 2;

	cout << n << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == '.' && squirrelCnt > 0) {
				squirrelCnt--;
				v[i][j] = 'D';
			}
			cout << v[i][j];
		}
		cout << '\n';
	}
	


}

