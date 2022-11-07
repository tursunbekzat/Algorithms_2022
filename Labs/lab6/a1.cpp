#include <iostream>
using namespace std;

int sz;
char h[100000];
char v[5] = {'a', 'e', 'o', 'i', 'u'};

bool bins(char d)
{
    for (int i(0); i < 5; i++)
    {
        if (d == v[i])
        {
            return true;
        }
    }
    return false;
}

void heapify(int i)
{
    int l = i + i + 1;
    int r = i + i + 2;
    int m = i;
    int cnt = 0;
    if (l < sz && h[l] < h[m] && bins(h[m]) && !bins(h[l]))
    {
        m = l;
    }
    if (r < sz && h[r] < h[m] && bins(h[m]) && !bins(h[r]))
    {
        m = r;
    }
    if (l < sz && h[l] > h[m])
    {
        if (bins(h[l]) && !bins(h[m]))
            cnt = 0;
        else
            m = l;
    }
    if (r < sz && h[r] > h[m])
    {
        if (bins(h[r]) && !bins(h[m]))
            cnt = 0;
        else
            m = r;
    }
    // cout << m << endl;
    if (m != i)
    {
        swap(h[i], h[m]);
        heapify(m);
    }
}

void build()
{
    for (int i = sz / 2 - 1; i >= 0; i--)
    {
        heapify(i);
    }
}

void print()
{
    for (int i(0); i < sz; i++)
    {
        cout << h[i];
    }
    cout << endl;
}

void heapsort()
{
    while(sz > 1){
        swap(h[0], h[sz-1]);
        sz--;
        heapify(0);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> sz;
    for (int i(0); i < sz; i++)
    {
        cin >> h[i];
    }

    build();
    // print();
    int n = sz;
    heapsort();
    sz = n;
    print();

    return 0;
}