#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_NAME 200

typedef struct _member_info {
	int no;
	int age;
	char name[MAX_NAME + 1];

	_member_info() : no(-1), age(-1), name("") {};
	_member_info(int _no, int _age, char _name[MAX_NAME + 1]) : no(_no), age(_age) { strncpy(name, _name, MAX_NAME + 1); };
} MemberInfo;

bool ascend(MemberInfo &a, MemberInfo &b) {
	if (a.age < b.age) {
		return true;
	} else if (a.age > b.age) {
		return false;
	} else {
		if (a.no < b.no) {
			return true;
		} else {
			return false;
		}
	}
}


int main() {
	int N;
	scanf("%d", &N);

	vector<MemberInfo> member_list(N);

	for (int n = 0; n < N; n++) {
		member_list[n].no = n;
		scanf("%d %s", &(member_list[n].age), member_list[n].name);
	}

	sort(member_list.begin(), member_list.end(), ascend);

	for (int i = 0; i < member_list.size(); i++) {
		printf("%d %s\n", member_list[i].age, member_list[i].name);
	}

	return 0;
}