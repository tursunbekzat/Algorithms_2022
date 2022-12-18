#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int size;
map<int, bool> isRed;
vector<vector<int>> adj;

int BFS(int y)
{
    vector<bool> visited;
    visited.resize(size, false);
    queue<int> q;
    q.push(y);
    visited[y] = true;
    int cnt = 0;
    while (!q.empty())
    {
        y = q.front();
        q.pop();
        if (isRed[y])
            return cnt;
        cnt++;
        for (auto i : adj[y])
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    size = n;
    adj.resize(n);
    int x, y;
    for (int i(0); i < m; i++)
    {
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    for (int i(0); i < q; i++)
    {
        cin >> x >> y;
        if (x == 1)
        {
            isRed[y - 1] = true;
        }
        else
        {
            cout << BFS(y - 1) << "\n";
        }
    }
    return 0;
}