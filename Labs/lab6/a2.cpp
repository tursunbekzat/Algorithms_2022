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

void print()
{
    for (int i(0); i < sz; i++)
    {
        cout << h[i];
    }
    cout << endl;
}

void heapify(int i)
{
    if (i == 0)
        return;
    int p = (i - 1) / 2;
    int cnt = 0;
    if (h[p] > h[i])
    {
        bool pin = bins(h[p]);
        bool ip = bins(h[i]);
        if(pin && !ip){
            cout << h[i] << " " << h[p] << endl;
            swap(h[i], h[p]);
            heapify(p);
        }
    }
    if (h[p] < h[i])
    {
        bool pin = bins(h[p]);
        bool ip = bins(h[i]);
        if (!pin && ip)
        {
            cnt++;
            heapify(p);
        }
        else
        {
            cout << h[i] << " " << h[p] << endl;
            swap(h[p], h[i]);
            heapify(p);
        }
    }
    // print();
}

void build()
{
    for (int i = sz - 1; i > 0; i--)
    {
        heapify(i);
    }
}


void heapsort()
{
    while (sz > 0)
    {
        swap(h[0], h[sz - 1]);
        sz--;
        heapify(sz);
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
    print();
    int n = sz;
    heapsort();
    sz = n;
    print();

    return 0;
}