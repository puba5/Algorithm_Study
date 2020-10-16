#include <iostream>
using namespace std;

int main() {
        int N;
        cin >> N;
        int ret = 0;
        int i = N;
        while (i > 1) {
                if (i % 3 == 0) i /= 3;
                else if (i  % 2 == 0) i /= 2;
                else i--;
                ret++;
cout << i << endl;
        }
        cout << ret << endl;
        return 0;
}
