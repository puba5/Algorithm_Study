#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    int minimum = 2000000, maximum = -2000000;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        minimum = min(minimum, tmp);
        maximum = max(maximum, tmp);
    }
    
    cout << minimum << " " << maximum << endl;
    
    return 0;
}
