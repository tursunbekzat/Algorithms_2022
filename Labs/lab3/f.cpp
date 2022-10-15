#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> pow_enem;
    vector<pair<int, int>> win;
    int y;
    for (int i(0); i < n; i++)
    {
        cin >> y;
        pow_enem.push_back(y);
    }
    sort(pow_enem.begin(), pow_enem.end());
    int k;
    cin >> k;
    int x;
    vector<int> pow_enem1;
    for (int i(0); i < k; i++)
    {
        cin >> x;
        int m = 0;
        bool ok = true;
        int l = 0, h = pow_enem.size() - 1;
        while (l <= h)
        {
            m = (l + h) / 2;
            // cout << l << h << m << endl;
            // cout << pow_enem[m] << endl;
            if (x >= pow_enem[m])
            {
                l = m + 1;
                ok = true;
            }
            else if (x < pow_enem[m])
            {
                h = m - 1;
                ok = false;
            }
        }
        if (!ok)
        {
            m--;
        }
        // cout << m << endl;   
        for (int i(0); i < m + 1; i++)
        {
            pow_enem1.push_back(pow_enem[i]);
        }
        win.push_back(make_pair(m + 1, accumulate(pow_enem1.begin(), pow_enem1.end(), 0)));
        pow_enem1.clear();
    }
    for (int i(0); i < k; i++)
    {
        cout << win[i].first << " " << win[i].second << endl;
    }
    return 0;
}