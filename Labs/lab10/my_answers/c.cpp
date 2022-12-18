#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int size;
vector<vector<int>> adj;

int BFS(int x, int y)
{
    map<int, bool> visited;
    // visited.resize(size, false);
    queue<int> q;
    q.push(x);
    // visited[x] = true;
    int cnt = 0;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        cnt++;
        if (x * 2 == y || x - 1 == y)
            return cnt;

        if (!visited[x]){
            visited[x] = true;
            q.push(x * 2);
            q.push(x - 1);
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> x >> y;
    cout << BFS(x, y) << "\n";
    return 0;
}