#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> max_(n, INT_MAX), min_(n, -1);

    vector<vector<int>> graph(n);

    vector<bool> check(n);
    for (int i = 0; i < n; i++)
    {
        graph[i].resize(n);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    max_[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int a = -1;
        for (int j = 0; j < n; j++)
        {
            if (!check[j] && (a == -1 || max_[j] < max_[a]))
            {
                a = j;
            }
        }
        check[a] = true;
        
        if (min_[a] != -1)
        {
            ans += graph[a][min_[a]];
        }

        for (int j = 0; j < n; j++)
        {
            if (graph[a][j] < max_[j])
            {
                max_[j] = graph[a][j];
                min_[j] = a;
            }
        }
    }

    cout << ans;

    return 0;
}