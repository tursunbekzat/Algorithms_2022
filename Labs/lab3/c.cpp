#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, x;
    cin >> n >> m;
    vector<int> v;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int a[m][4];
    for (int i(0); i < m; i++)
    {
        for (int j(0); j < 4; j++)
        {
            cin >> x;
            a[i][j] = x;
        }
    }
    vector<int> count;
    for (int i(0); i < m; i++)
    {
        int cnt = 0;
        for (int j(0); j < n; j++)
        {
            if ((a[i][0] <= v[j] && v[j] <= a[i][1]) || (a[i][2] <= v[j] && v[j] <= a[i][3]))
            {
                cnt++;
            }
        }
        count.push_back(cnt);
    }
    for (int i = 0; i < m; i++)
    {
        cout << count[i] << " ";
        cout << endl;
    }
}