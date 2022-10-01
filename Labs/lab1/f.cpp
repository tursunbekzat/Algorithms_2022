// n-th prime number
#include <iostream>
#include <vector>

using namespace std;

bool prime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return "1";
}

int main()
{
    vector<int> primes;
    int n;
    cin >> n;
    for (int i = 2; i < 10000; i++)
    {
        if (prime(i))
        {
            primes.push_back(i);
        }
    }
    cout << primes[n - 1];
    return 0;
}