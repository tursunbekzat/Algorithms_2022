#include <iostream>
#include <deque>
using namespace std;


void insert(deque<int> *d, int n)
{
    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        (*d).push_back(x);
    }
}


void merge(deque<int> &v, int l, int m, int r)
{
    deque<int> sorted;
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

void mergesort(deque<int> &d, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = (l + r) / 2;
    mergesort(d, l, m);
    mergesort(d, m + 1, r);
    merge(d, l, m, r);
}


void print(deque<int> d)
{
    if(d.size() == 0){
        return;
    }
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void check_common(deque<int> d1, deque<int> d2){
    if(d1.empty() || d2.empty()){
        return;
    }
    while(!d1.empty() && !d2.empty()){
        if(d2.front() < d1.front()){
            d2.pop_front();
        }
        else if(d2.front() > d1.front()){
            d1.pop_front();
        }
        else{
            cout << d1.front() << " ";
            d1.pop_front();
            d2.pop_front();
        }
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    deque<int> d1, d2;

    cin >> n >> m;

    insert(&d1, n);
    insert(&d2, m);

    mergesort(d1, 0, n - 1);
    mergesort(d2, 0, m - 1);

    // print();

    check_common(d1, d2);

    return 0;
}
