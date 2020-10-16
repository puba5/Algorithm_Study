#include <iostream>
#include <vector>
using namespace std;


void func2(vector<int> k);
void func(vector<int> k) {
	k.push_back(1);

	func2(k);
	func2(k);
	cout << k.size() << endl;

}

void func2(vector<int> k) {
	k.push_back(2);
	cout << k.size() << endl;
}


int main() {
	vector<int> a;
	a.push_back(2);
	func(a);

	cout << a.size() << endl;

	return 0;
}
