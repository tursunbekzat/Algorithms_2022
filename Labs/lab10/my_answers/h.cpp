#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int n, m;
map<int, bool> isRed;
vector<vector<int>> adj;

void BFS(int i, int j)
{
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    int cnt = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        i = p.first, j = p.second;
        adj[i][j] = 0;
        q.pop();

        if (i - 1 > 0 && adj[i - 1][j] == 1)
            q.push(make_pair(i - 1, j));
        if (i + 1 < n && adj[i + 1][j] == 1)
            q.push(make_pair(i + 1, j));
        if (j - 1 > 0 && adj[i][j - 1] == 1)
            q.push(make_pair(i, j - 1));
        if (j + 1 > 0 && adj[i][j + 1] == 1)
            q.push(make_pair(i, j + 1));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    adj.resize(n);
    vector<string> s(n);
    for (int i(0); i < n; i++)
        cin >> s[i];

    int a[n][m];
    for (int i(0); i < n; i++)
        for (int j(0); j < m; j++)
            if (s[i][j] == '1')
                adj[i].push_back(1);
            else
                adj[i].push_back(0);

    int cnt = 0;
    for (int i(0); i < n; i++)
        for (int j(0); j < m; j++)
        {
            if (adj[i][j] == 1)
            {
                BFS(i, j);
                cnt++;
            }
        }

    cout << cnt << "\n";
    return 0;
}