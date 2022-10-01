// superprime
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
    vector<int> superprimes;
    int n;
    cin >> n;
    for (int i = 2; i < 100000; i++)
    {
        if (prime(i))
        {
            primes.push_back(i);
        }
    }
    for (int i = 2; i < (n + 1) * (n + 1); i++)
    {
        if (prime(i))
        {
            superprimes.push_back(primes[i - 1]);
        }
    }
    cout << superprimes[n - 1];
    return 0;
}