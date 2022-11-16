#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

void merge(int l, int m, int r)
{
    vector<int> sorted;
    int i1 = l, i2 = m + 1;

    while (i1 <= m && i2 <= r)
    {
        if (v[i1] <= v[i2])
        {
            sorted.push_back(v[i1]);
            i1++;
        }
        else
        {
            sorted.push_back(v[i2]);
            i2++;
        }
    }

    if (i1 <= m)
    {
        for (; i1 <= m; i1++)
            sorted.push_back(v[i1]);
    }
    else
    {
        for (; i2 <= r; i2++)
            sorted.push_back(v[i2]);
    }
    for (int i(l); i <= r; i++)
    {
        v[i] = sorted[i - l];
    }
    // print();
}

void mergesort(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = (l + r) / 2;
    mergesort(l, m);
    mergesort(m + 1, r);
    merge(l, m, r);
}

void print()
{
    for (int s : v)
        cout << s << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    cin >> n;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    mergesort(0, v.size() - 1);

    print();

    return 0;
}