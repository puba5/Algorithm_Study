#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BigInteger {
private:
	vector<char> number;
public:
	void add(const BigInteger &b) {
		bool up = false;
		int small_len = min(this->number.size(), b.number.size());
		int index = 0;
		while (index < small_len) {
			char sum = this->number[index] + b.number[index];
			if (up == true) {
				up = false;
				sum += 1;
			}
			if (sum >= 10) {
				up = true;
				this->number[index] = sum - 10;
			}
			index += 1;
		}
		
		if (this->number.size() < b.number.size()) {
			if (up == true) {
				up = false;
				this->number.push_back(b.number[index] + 1);
				index += 1;
			}
			while (index < b.number.size()) {
				this->number.push_back(b.number[index]);
				index += 1;
			}
		} else if (this->number.size() > b.number.size()) {
			if (up == true) {
				up = false;
				this->number.push_back(this->number[index] + 1);
				index += 1;
			}
			while (index < this->number.size()) {
				this->number.push_back(this->number[index] + 1);
				index += 1;
			}
		} else {
			if (up == true) {
				up = false;
				this->number.push_back(1);
			}
		}
	}
/*
	void cube() {
		vector<char> origin(this->number.size(), 0);
		copy(this->number.begin(), this->number.end(), origin.begin());
		char up = 0;
		for (int n = 0; n < 2; n++) {
			for (int i = 0; i < origin.size(); i++) {
				for (int j = 0; j < this->number.size(); j++) {
					char num = this->number[j] * origin[i] + up;
					this->number[j] = num % 10;
					up = num / 10;
				}
				if (up > 0) {
					
				}
			}
		}
		
	}
*/
	void divBy2() {
		char share = 0, remainder = 0;
		for (int i = this->number.size() - 1; i >= 0; i--) {
			char num = ((remainder * 10) + this->number[i]);
			this->number[i] = num / 2;
			remainder = num % 2;
		}
	};

	void setByString(string str_number) {
		for (int i = str_number.size() - 1; i >= 0; i--) {
			this->number.push_back(str_number.c_str()[i] - '0');
		}
	}

	void print() {
		for (int i = this->number.size() - 1; i >= 0; i--) {
			printf("%d", this->number[i]);
		}
		printf("\n");
	}
};

int main() {
	BigInteger a, b;
	a.setByString("99");
	b.setByString("1");
	a.add(b);
	a.print();
}