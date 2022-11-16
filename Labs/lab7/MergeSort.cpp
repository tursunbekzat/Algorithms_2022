#include <iostream>
#include <vector>
using namespace std;

void merge_sorted_arr(vector <int> &v, int l, int r)
{
    int mid = (l + r) / 2;
    int i1 = l, i2 = mid + 1, i = l;

    vector <int> mv(r - l + 1);
    while (i1 <= mid && i2 <= r)
    {
        if (v[i1] <= v[i2]){
            mv[i - l] = v[i1];
            i1++;
        }else{
            mv[i - l] = v[i2];
            i2++;
        }
        i++;
    }
    
    if (i1 <= mid)
        for (; i1 <= mid; i1++, i++)
            mv[i - l] = v[i1];
    else
        for (; i2 <= r; i2++, i++)
            mv[i - l] = v[i2];

    for (i = l; i <= r; i++)
        v[i] = mv[i - l];
}

void MergeSort(vector <int> &v, int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) / 2;
    MergeSort(v, l, mid);
    MergeSort(v, mid + 1, r);
    merge_sorted_arr(v, l, r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector <int> v;
    int n; cin >> n;
    while (n--)
    {
        int x; cin >> x;
        v.push_back(x);
    }

    MergeSort(v, 0, v.size() - 1);

    for (int i : v) cout << i << " ";
    
}