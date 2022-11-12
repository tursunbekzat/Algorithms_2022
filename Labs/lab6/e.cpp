#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int a[1000][1000];
vector<vector<int>> vv;
vector<int> v;

void quicksort(int b[], int l, int r)
{
    if (l >= r || r < 1)
        return;
    int h = r;
    while (l < h){
        if (b[l] < b[r]){
            while (h > l){
                if (b[h] >= b[r]){
                    swap(b[l], b[h]);
                    // h--;
                    break;
                }
                h--;
            }
        }
        l++;
    }
    quicksort(b, 0, l - 1);
    quicksort(b, l, r);
}

void sortA()
{
    for (int i(0); i < m; i++)
    {
        quicksort(a[i], 0, n - 1);
    }
}

void print()
{
    for (int i(0); i < n; i++)
    {
        for (int j(0); j < m; j++)
        {
            cout << a[j][i] << " ";
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
            cin >> a[j][i];
        }
    }

    // cout << "\nInitial matrix\n";
    // for (int i(0); i < m; i++)
    // {
    //     for (int j(0); j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    sortA();

    // cout << "Final matrix\n";
    print();

    return 0;
}