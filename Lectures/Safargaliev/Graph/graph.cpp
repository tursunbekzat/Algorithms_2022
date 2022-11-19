#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<vector<int>> g;
int n = 5;
bool used[5];

// glubina
void dfs(int v)
{
    cout << "Current vertex: " << g[v][0] << "\n";
    used[v] = true;
    for (int i(0); i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (used[to])
            dfs(to);
    }
}

queue<int> q;
// shirina
void bfs(int v)
{
    cout << g[v][0] << "\n";
    used[v] = true;
    q.push(v);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (int i(0); i < g[v].size(); i++)
        {
            int to = g[v][i];
            if (!used[to])
            {
                used[to] = true;
                q.push(to);
            }
        }
    }
}

// count of no relationship graphs
int comp(){
    int cnt = 0;
    for(int i(0);i<n;i++){
        if(!used[i]){
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}

map<int, vector<int>> mv;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<pair<int, int>> v;
    int x, y;
    for (int i; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    return 0;
}