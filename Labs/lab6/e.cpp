#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> vv;
vector<vector<int>> vv1;
vector<int> v;

void pop()
{
    while (!v.empty())
    {
        v.pop_back();
    }
}

void quicksorty(vector<int> &v1, int l, int r)
{
    if (l >= r)
        return;
    int i = l;
    int j = r;
    int g = v1[r];
    while (i < j)
    {
        if (v1[i] > g)
        {
            while (j > i)
            {
                if (v1[j] <= g)
                {
                    swap(v1[i], v1[j]);
                    j--;
                    break;
                }
                j--;
            }
        }
        i++;
    }
    quicksorty(v1, 0, i - 1);
    quicksorty(v1, i, r);
}

void sort_vv()
{
    for (int i(0); i < m; i++)
    {
        quicksorty(vv1[i], 0, n - 1);
        reverse(vv1[i].begin(), vv1[i].end());
    }
}

void transpose()
{
    for (int i(0); i < m; i++)
    {
        for (int j(0); j < n; j++)
        {
            v.push_back(vv[j][i]);
        }
        vv1.push_back(v);
        pop();
    }
}

void transpose1()
{
    for (int i(0); i < n; i++)
    {
        for (int j(0); j < m; j++)
        {
            vv[i][j] = vv1[j][i];
        }
    }
}

void print()
{
    for (int i(0); i < n; i++)
    {
        for (int j(0); j < m; j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << "\n";
    }
}

void print1()
{
    for (int i(0); i < m; i++)
    {
        for (int j(0); j < n; j++)
        {
            cout << vv1[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int x;
    for (int i(0); i < n; i++)
    {
        for (int j(0); j < m; j++)
        {
            cin >> x;
            v.push_back(x);
        }
        vv.push_back(v);
        pop();
    }

    // cout << "\nInitial matrix\n";
    // print();

    transpose();

    // cout << "Transpose matrix\n";
    // print1();

    sort_vv();

    // cout << "Sorted Transpose matrix\n";
    // print1();

    transpose1();

    // cout << "Final matrix\n";
    print();

    return 0;
}