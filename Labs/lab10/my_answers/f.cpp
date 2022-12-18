#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int size;
map<int, bool> isRed;
vector<vector<int>> adj;

string BFS(int x, int y)
{
    int v = x;
    vector<bool> visited;
    visited.resize(size, false);
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty())
    {
        int cnt = 0;
        v = q.front();
        q.pop();
        for (auto i : adj[v])
        {
            if (i == x || i == y)
                cnt++;
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
        if (cnt == 2)
            return "YES";
    }
    return "NO";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    size = n;
    adj.resize(n);
    int x, y;
    for (int i(0); i < m; i++)
    {
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    cin >> x >> y;
    cout << BFS(x-1, y-1) << "\n";

    return 0;
}