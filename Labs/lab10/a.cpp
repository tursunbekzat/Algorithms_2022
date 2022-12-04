#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, m;
vector<vector<int>> vv;
map<pair<int, int>, bool> visited;

void kill(int i, int j, vector<pair<int, int>> &pos)
{
    if (visited[make_pair(i, j)])
        return;
    visited[make_pair(i, j)] = true;
    if (i != 0)
        if (vv[i - 1][j] == 1)
        {
            vv[i - 1][j] = 2;
            pos.push_back(make_pair(i - 1, j));
        }
    if (i + 1 != n)
        if (vv[i + 1][j] == 1)
        {
            vv[i + 1][j] = 2;
            pos.push_back(make_pair(i + 1, j));
        }
    if (j != 0)
        if (vv[i][j - 1] == 1)
        {
            vv[i][j - 1] = 2;
            pos.push_back(make_pair(i, j - 1));
        }
    if (j + 1 != m)
        if (vv[i][j + 1] == 1)
        {
            vv[i][j + 1] = 2;
            pos.push_back(make_pair(i, j + 1));
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<pair<int, int>> twice;
    for (int i(0); i < n; i++)
    {
        vector<int> temp(m);
        for (int j(0); j < m; j++)
        {
            cin >> temp[j];
            if (temp[j] == 2)
                twice.push_back(make_pair(i, j));
        }
        vv.push_back(temp);
    }

    int cnt = 0;
    while (1)
    {
        vector<pair<int, int>> twice2;
        for (auto p : twice)
        {
            kill(p.first, p.second, twice2);
        }
        if (twice2.empty())
            break;
        cnt++;
        twice = twice2;
    }

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (vv[i][j] == 1)
            {
                cout << -1 << "\n";
                return 0;
            }

    cout << cnt << "\n";
    return 0;
}