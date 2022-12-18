#include <bits/stdc++.h>
using namespace std;

vector<int> vec;


int inc(int n)
{
    if (n == vec[n])
    {
        return n;
    }
    else
        return vec[n] = inc(vec[n]);
}


void dec(int f, int s)
{
    s = inc(s);
    f = inc(f);
    if (f != s)
    {
        vec[f] = s;
    }
}


int main()
{
    vector<pair<int, pair<int, int>>> v;

    int n, m, x, y, sum = 0;
    cin >> n >> m >> x >> y;
    vec.resize(n);

    for (int i = 0; i < m; i++)
    {
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;
        a--;
        b--;
        if (s == "big")
            c *= x;
        else if (s == "small")
            c *= y;
        else if (s == "both")
            c *= min(x, y);

        v.push_back({c, {a, b}});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
    {
        vec[i] = i;
    }

    for (int i = 0; i < v.size(); ++i)
    {
        int f = v[i].second.first;
        int s = v[i].second.second;
        int amount = v[i].first;

        if (inc(f) != inc(s))
        {
            sum += amount;
            dec(f, s);
        }
    }

    cout << sum;

    return 0;
}