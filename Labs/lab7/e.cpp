#include <iostream>
#include <vector>
using namespace std;

int m, n;
int a[500][500];
vector<pair<int, int>> sum_of_rows;

void insert()
{
    for (int i(0); i < n; i++)
    {
        sum_of_rows.push_back(make_pair(i, 0));
        for (int j(0); j < m; j++)
        {
            cin >> a[i][j];
            sum_of_rows[i].second += a[i][j];
        }
    }

    // for (int i(0); i < n; i++)
    // {
    //     cout << sum_of_rows[i].first << " " << sum_of_rows[i].second << "\n";
    // }
}

void merge_sorted_arr(vector<pair<int, int>> &v, int l, int r)
{
    int mid = (l + r) / 2;
    int i1 = l, i2 = mid + 1;

    vector<pair<int, int>> mv;
    while (i1 <= mid && i2 <= r)
    {
        if (v[i1].second < v[i2].second)
        {
            mv.push_back(v[i1]);
            i1++;
        }
        else if (v[i1].second > v[i2].second)
        {
            mv.push_back(v[i2]);
            i2++;
        }
        else{
            int y = i1 + i2;
            for(int j(0);j<m;j++){
                if(a[v[i1].first][j] > a[v[i2].first][j]){
                    mv.push_back(v[i1]);
                    i1++;
                    break;
                }
                else if(a[v[i1].first][j] < a[v[i2].first][j]){
                    mv.push_back(v[i2]);
                    i2++;
                    break;
                }
            }
            if(y == i1 + i2){
                mv.push_back(v[i1]);
                i1++;
            }
        }
    }

    if (i1 <= mid)
        for (; i1 <= mid; i1++)
            mv.push_back(v[i1]);
    else
        for (; i2 <= r; i2++)
            mv.push_back(v[i2]);

    for (int i = l; i <= r; i++)
        v[i] = mv[i - l];
}

void MergeSort(vector<pair<int, int>> &v, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    MergeSort(v, l, mid);
    MergeSort(v, mid + 1, r);
    merge_sorted_arr(v, l, r);
}

void print()
{
    for (int i(n - 1); i >= 0; i--)
    {
        for (int j(0); j < m; j++)
        {
            cout << a[sum_of_rows[i].first][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    insert();

    MergeSort(sum_of_rows, 0, n - 1);

    // for (int i(0); i < n; i++)
    // {
    //     cout << sum_of_rows[i].first << " " << sum_of_rows[i].second << "\n";
    // }

    print();

    return 0;
}