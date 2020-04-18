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


enum Property { Gold, Mana, Light, Dark, Nature };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	cin.ignore();
	
	
	array<int, 5> deck{ 0, };

	while (n--) {
		string str;
		cin >> str;
		
		switch (str[0]) {
		case 'g':
			deck[Property::Gold]++;
			break;
		case 'm':
			deck[Property::Mana]++;
			break;
		case 'l':
			deck[Property::Light]++;
			break;
		case 'd':
			deck[Property::Dark]++;
			break;
		case 'n':
			deck[Property::Nature]++;
			break;
		}
	}
	
	int diff = 0;
	for (int i = 0; i < deck.size(); i++) {
		if (deck[i] > 0) {
			diff++;
		}
	}
	if (diff > 3) {
		cout << "invalid" << endl;
	}
	else
		cout << "valid" << endl;
}

