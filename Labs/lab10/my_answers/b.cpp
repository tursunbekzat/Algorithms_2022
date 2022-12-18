#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int size;
vector<vector<int>> adj;

int BFS(int v, int k)
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
        cnt++;
        // for (auto i : adj[v])
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
        for (auto vect : adj[v])
        {
            // cout << vect << "\n";
            if (vect == k)
                return cnt;
            if (!visited[vect])
            {
                visited[vect] = true;
                q.push(vect);
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> size;
    int x;
    adj.resize(size);
    for (int i(0); i < size; i++)
    {
        for (int j(0); j < size; j++)
        {
            cin >> x;
            if (x == 1)
                adj[i].push_back(j);
        }
    }
    int k, l;
    cin >> k >> l;
    cout << BFS(k - 1, l - 1) << "\n";
    return 0;
}