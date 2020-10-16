#include <string>
#include <vector>
#include <unordered_set>

                    #include <iostream>

using namespace std;

void makeList(int column_len, int set_size, vector<vector<int> > &list, int index, vector<int> tmp_list, string tmp_str, unordered_set<string> candidate_set) {
    if ((int)tmp_list.size() == set_size) {
        list.push_back(tmp_list);
    } else {
		if (set_size - (int)tmp_list.size() <= column_len - index - 1) {
			makeList(column_len, set_size, list, index + 1, tmp_list, tmp_str, candidate_set);
		}
		if (index + 1 < column_len){
			tmp_list.push_back(index + 1);
			tmp_str += (to_string(index + 1) + " ");
			if (candidate_set.find(tmp_str) != candidate_set.end()) {
				return;
			}
			makeList(column_len, set_size, list, index + 1, tmp_list, tmp_str, candidate_set);
		}
	}
}

bool duplicateCheck(int row_len, vector<int> &list, vector<vector<string> > &relation, unordered_set<string> &candidate_set) {
	int list_len = (int)list.size();

	unordered_set<string> set;
	for (int r = 0; r < row_len; r++) {
		string key = "";
		for (int c = 0; c < list_len; c++) {
			key += relation[r][list[c]];
		}
		if (set.find(key) == set.end()) {
			set.insert(key);
		} else {
			return false;
		}

	}
	string candidate_key = "";
	for (int c = 0; c < list_len; c++) {
		candidate_key += (to_string(list[c]) + " ");
	}
	candidate_set.insert(candidate_key);
	return true;
}

int solution(vector<vector<string> > relation) {
    int answer = 0;
    int row_len = (int)relation.size();
    int column_len = (int)relation[row_len-1].size();
    unordered_set<string> candidate_set; 
    for (int k = 1; k <= column_len; k++) {
        vector<vector<int> > list;
		string tmp_str = "";
        makeList(column_len, k, list, -1, vector<int> (), tmp_str, candidate_set);


		int list_len = list.size();
		for (int l = 0; l < list_len; l++) {
			duplicateCheck(row_len, list[l], relation, candidate_set);
		}
    }

    return answer = (int)candidate_set.size();
}

int main() {
	vector<vector<string> > r(6, vector<string>(4));
	r[0][0] = "100"; r[0][1] = "ryan"; r[0][2] = "music"; r[0][3] = "2";
	r[1][0] = "200"; r[1][1] = "apeach"; r[1][2] = "math"; r[1][3] = "2";
	r[2][0] = "300"; r[2][1] = "tube"; r[2][2] = "computer"; r[2][3] = "3";
	r[3][0] = "400"; r[3][1] = "con"; r[3][2] = "computer"; r[3][3] = "1";
	r[4][0] = "500"; r[4][1] = "muzi"; r[4][2] = "music"; r[4][3] = "3";
	r[5][0] = "600"; r[5][1] = "apeach"; r[5][2] = "music"; r[5][3] = "2";
	cout << solution(r) << endl; 

}
