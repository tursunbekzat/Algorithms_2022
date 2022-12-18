#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[200001], r[200001];


int find(int i)
{
    return (i == p[i]) ? i : p[i] = find(p[i]);
}


bool merge(int i, int j)
{
    int a = find(i), b = find(j);
    if (a == b)
        return false;
    p[a] = b;
    return 1;
}


int main()
{
    cin >> n >> m;

    int used[n];
    vector<int> graph[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        r[i] = i;
    }
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> res;

    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        res.push_back(cnt++);
        for (int x : graph[i])
        {
            if (x > i)
            {
                if (merge(i, x))
                    cnt--;
            }
        }
    }

    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << endl;

    return 0;
}