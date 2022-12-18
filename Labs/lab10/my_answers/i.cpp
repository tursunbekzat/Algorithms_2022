#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> visit;
vector<bool> visited;

void BFS(int x)
{
    int v = x;
    visited.resize(n, false);
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        visit.push_back(v);
        for (auto i : adj[v])
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    adj.resize(n);
    int x, y;
    int first;
    for (int i(0); i < m; i++)
    {
        cin >> x >> y;
        if (i == 0)
            first = x;
        adj[x - 1].push_back(y - 1);
    }
    BFS(first - 1);
    for (auto i : visited)
    {
        if (i == false)
        {
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << "Possible\n";
    for (auto i : visit)
        cout << i + 1 << " ";
    cout << "\n";

    return 0;
}