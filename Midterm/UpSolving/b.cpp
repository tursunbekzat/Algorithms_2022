#include <iostream>
#include <cmath>

using namespace std;

bool CheckForPrime(int m)
{
    for (int i = 2; i <= sqrt(m); i++)
    {
        if (m % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int i = 2;
    while (i < n)
    {
        if (CheckForPrime(i) && CheckForPrime(n - i))
        {
            cout << i << " " << n - i << endl;
            break;
        }
        i++;
    }
    return 0;
}