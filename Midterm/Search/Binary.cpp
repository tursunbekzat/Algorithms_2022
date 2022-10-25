#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

bool Find(int k, int l, int r)
{
    bool ans = false;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] == k)
        {
            ans = true;
            break;
        }
        else if (v[m] < k)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n;
    for (int i(0); i < n; i++)
    {
        cin >> k;
        v.push_back(k);
    }
    cin >> k;
    int l = 0, r = n;
    if (Find(k, l, r))
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    return 0;
}