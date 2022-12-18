#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int size;
map<int, bool> isRed;
vector<vector<int>> adj;

string BFS(int v)
{
    vector<bool> visited;
    visited.resize(size, false);
    queue<int> q;
    q.push(v);
    visited[v] = true;
    int cnt = 0;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (auto vect : adj[v])
        {
            if (!visited[vect])
            {
                visited[vect] = true;
                q.push(vect);
            }
            else
                cnt++;
        }
    }
    if (cnt > 1)
        return "NO";
    return "YES";
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
    int first;
    for (int i(0); i < m; i++)
    {
        cin >> x >> y;
        if (i == 0)
            first = x;
        adj[x - 1].push_back(y - 1);
    }

    cout << BFS(first) << "\n";

    return 0;
}