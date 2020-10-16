#include <iostream>
#include <cstring>
using namespace std;

string p;
string f;
char m[100][100];

bool match(int i, int j) {
         if (m[i][j] == -1) {
                if (i == p.size()-1 && j == f.size()-1) m[i][j] = (p.at(i) == f.at(j) || p.at(i) == '*');
                else if (i == p.size()-1 && j != f.size()-1) m[i][j] = (p.at(i) == '*');
                else if (i != p.size()-1 && j == f.size()-1) m[i][j] = (p.at(i) == '*' && match(i+1, j));
                else m[i][j] = ((p.at(i) == f.at(j) && match(i+1, j+1)) || (p.at(i) == '*' && (match(i+1, j) || match(i, j+1) || match(i+1, j+1))));
        }
        return (bool)m[i][j];
}

int main(){
        int n;
        string *fileNames;

        cin >> p >> n;
        fileNames = new string[n];
        for (int i = 0; i < n; i++) cin >> fileNames[i];
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < 100; j++) memset(m[j], -1, sizeof(char)*100);
                f = fileNames[i];
                if (match(0, 0)) cout << f << endl;
        }

        return 0;
}
