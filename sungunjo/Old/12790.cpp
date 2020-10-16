#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	int ret[1000];
	cin >> T;

	for (int i = 0; i < T; i++) {
		int hp, ehp, mp, emp, atk, eatk, def, edef;
		cin >> hp >> mp >> atk >> def >> ehp >> emp >> eatk >> edef;
		hp = max(1, hp + ehp);
		mp = max(1, mp + emp);
		atk = max(0, atk + eatk);
		def = def + edef;
		ret[i] = hp + 5*mp + 2*atk + 2*def << endl;
	}
	for (int i = 0; i < T; i++) {
		cout << ret[i] << endl;
	}
	return 0;
}	
