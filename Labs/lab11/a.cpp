#include <bits/stdc++.h>
using namespace std;

int n, m;
int l, r, c;
vector<pair<int, pair<int, int>>> graph;

int first[200002];
int second[200002], third[200002];

void color(vector<bool> &used, int l, int r)
{
    for (int i = l; i <= r; i++)
        used[i] = 1;
}


int find(int i)
{
    if (i == first[i])
        return i;
    return first[i] = find(first[i]);
}


bool slise(int i, int j)
{
    int a = find(i), b = find(j);
    if (a == b)
        return false;
    first[a] = b;
    second[b] = min(second[a], second[b]);
    third[b] = max(third[a], third[b]);
    return 1;
}



int main()
{
    cin >> n >> m;

    vector<bool> used(n, false);

    while (m--)
    {
        cin >> l >> r >> c;
        l--;
        r--;
        graph.push_back({c, {l, r}});
    }

    for (int i = 0; i < n; i++)
    {
        first[i] = i;
        second[i] = i;
        third[i] = i;
    }

    sort(graph.begin(), graph.end());
    long long ans = 0;
    int cnt = 0, p = -1;
    for (int i = 0; i < graph.size(); i++)
    {
        if (cnt > n - 1)
            break;
        int l = graph[i].second.first, r = graph[i].second.second, c = graph[i].first;
        p = l;
        for (int j = l; j <= r; j++)
        {
            if (j != find(j))
            {
                p = find(j);
                break;
            }
        }



        if (second[p] <= l and r <= third[p])
            continue;
        else if (second[p] <= r and r <= third[p])
            r = second[p];
        else if (second[p] <= l and l <= third[p])
            l = third[p];

        for (int j = l; j <= r; j++)
        {
            if (slise(p, j))
            {
                cnt++;
                ans += c;
            }
        }
    }

    cout << ans;

    return 0;
}