#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

unsigned long long ar[10000000];
unsigned long long n, k;
vector<unsigned long long> v;

unsigned long long NumDiv(unsigned long long md, unsigned long long* maxi)
{
    unsigned long long sum = 0;
    unsigned long long cnt = 0;
    *maxi = 0;
    for (unsigned long long i(0); i < n; i++)
    {
        sum += ar[i];
        if (sum > md)
        {
            // cout << "bigger sum = " << sum - ar[i] << endl;
            cnt++;
            if ((*maxi) < sum - ar[i])
            {
                (*maxi) = sum - ar[i];
            }
            // cout << "bigger sum = " << sum << endl;
            sum = ar[i];
        }
        else if (sum == md)
        {
            // cout << "equal sum = " << sum << endl;
            cnt++;
            if ((*maxi) < sum)
            {
                (*maxi) = sum;
            }
            sum = 0;
        }
        // cout << "maxi = " << (*maxi) << endl;
    }
    // cout << "sum last = " << sum << endl;
    if (sum < md && sum != 0 || sum > md)
    {
        cnt++;
    }
    // cout << "cnt = " << cnt << endl;
    // cout << endl
    //      << endl;
    return cnt;
}

void Oshieti()
{
    unsigned long long sum = 0;
    for (unsigned long long i(0); i < n; i++)
    {
        sum += ar[i];
    }
    unsigned long long l = 0;
    unsigned long long r = sum * 2;
    while (l <= r)
    {
        unsigned long long maxi = 0;
        unsigned long long mid = (l + r) / 2;
        // cout << "left = " << l << endl;
        // cout << "right = " << r << endl;
        // cout << "mid = " << mid << endl;
        unsigned long long nd = NumDiv(mid, &maxi);
        if (nd > k)
        {
            l = mid + 1;
        }
        else if (nd < k)
        {
            r = mid - 1;
        }
        else
        {
            r = mid - 1;
            v.push_back(maxi);
        }
    }
}

int main()
{
    cin >> n >> k;
    for (unsigned long long i(0); i < n; i++)
    {
        cin >> ar[i];
    }

    // cout << endl;
    Oshieti();

    unsigned long long mini = 100000000000000;
    for (unsigned long long i : v)
    {
        if (mini > i)
        {
            mini = i;
        }
        // cout << i << " ";
    }
    cout << mini << endl;

    return 0;
}