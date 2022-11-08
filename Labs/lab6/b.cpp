#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> *v, int n)
{
    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        (*v).push_back(x);
    }
}

void quicksort(vector<int> v, int l, int r)
{
    if (r < 1 || l >= r)
    {
        return;
    }
    int j = r;
    while (l < j)
    {
        if (v[l] > v[r])
        {
            while (j > l)
            {
                if (v[j] <= v[r]){
                    swap(v[l], v[j]);
                }
                j--;
            }
        }
        // if(j <= l){
        //     break;
        // }
        l++;
    }
    quicksort(v, 0, l - 1);
    quicksort(v, l, r);
}

void print(vector<int> v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n, m;
    vector<int> v1, v2;

    cin >> n >> m;

    insert(&v1, n);
    insert(&v2, m);

    print(v1);
    print(v2);

    // quicksort(v1, 0, n - 1);
    // quicksort(v2, 0, m - 1);

    // print(v1);
    // print(v2);

    return 0;
}