#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n, f;
    vector<int> gift;
    cin >> n >> f;
    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        gift.push_back(x);
    }
    sort(gift.begin(), gift.end());

    int l = 0, h = 100, f1, m, ans = 1e5, ans1 = 1e5;
    while (l <= h)
    {
        f1 = 0;
        m = (l + h) / 2;
        // cout << "midpoint: " << m << " "
        //      << "l: " << l << " "
        //      << "h: " << h << endl;
        for (int i(0); i < n; i++)
        {
            f1 += ceil(gift[i] / m);
        }
        // cout << "f1: " << f1 << endl;
        if (f1 > f)
        {
            l = m + 1;
        }
        else if (f1 < f)
        {
            h = m - 1;
        }
        if (f1 == f)
        {
            break;
        }
        if (ans1 > m && ans1 > ans)
        {
            ans1 = m;
        }
        if (ans > m)
        {
            ans = m;
        }
    }
    cout << ans << " " << ans1 << " " << m << endl;
    return 0;
}