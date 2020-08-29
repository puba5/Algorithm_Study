#include <iostream>
#include <string>

using namespace std;

bool isDecreasingNumber(int number)
{

    while (number >= 0)
    {
        int oneNumber = number % 10;
        if (oneNumber <= number % 10)
        {
            return false;
        }
        number /= 10;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int number = 0;
    while (number++)
    {
        if (isDecreasingNumber(number))
        {
            n--;
        }
        if (n == 0)
        {
            cout << number;
        }
    }

    return 0;
}
