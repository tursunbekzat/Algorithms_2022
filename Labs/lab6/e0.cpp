#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> vv;

void quicksorty(vector<int> &v1, int l, int r)
{
    if (l >= r)
        return;
    int h = r;
    int g = v1[r];
    while (l < h){
        if (v1[l] < g){
            while (h > l){
                if (v1[h] >= g){
                    swap(v1[l], v1[h]);
                    h--;
                    break;
                }
                h--;
            }
        }
        l++;
    }
    quicksorty(v1, 0, l - 1);
    quicksorty(v1, l, r);
}

void sort_vv()
{
    for (int i(0); i < m; i++)
    {
        quicksorty(vv[i], 0, n - 1);
    }
}

// void transpose()
// {
//     for (int i(0); i < m; i++)
//     {
//         for (int j(0); j < n; j++)
//         {
//             v.push_back(vv[j][i]);
//         }
//         vv1.push_back(v);
//         pop();
//     }
// }

// void transpose1()
// {
//     for (int i(0); i < n; i++)
//     {
//         for (int j(0); j < m; j++)
//         {
//             vv[i][j] = vv1[j][i];
//         }
//     }
// }

void print()
{
    for (int i(0); i < n; i++)
    {
        for (int j(0); j < m; j++)
        {
            cout << vv[j][i] << " ";
        }
        cout << "\n";
    }
}

// void print1()
// {
//     for (int i(0); i < m; i++)
//     {
//         for (int j(0); j < n; j++)
//         {
//             cout << vv1[i][j] << " ";
//         }
//         cout << "\n";
//     }
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int f = max(n, m);
    for(int i(0);i < f + 1;i++){
        vv.push_back({0});
    }

    int x;
    for (int i(0); i < n; i++)
    {
        for (int j(0); j < m; j++)
        {
            cin >> vv[j][i];
        }
    }

    cout << "\nInitial matrix\n";
    print();

    sort_vv();

    cout << "Final matrix\n";
    print();

    return 0;
}