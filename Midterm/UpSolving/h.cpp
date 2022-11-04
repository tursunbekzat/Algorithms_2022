#include <iostream>
using namespace std;

struct maxheap
{
    int sz;
    int heap[1000000001];

    maxheap();
    void insert(int val);
    void heapify(int i);
    void build();
    int rgls(int i);
};

maxheap::maxheap()
{
    sz = 0;
}

void maxheap ::insert(int val)
{
    heap[sz++] = val;
}

void maxheap ::build()
{
    for (int i(sz / 2); i >= 0; i--)
    {
        heapify(i);
    }
}

void maxheap ::heapify(int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int m = i;
    if (l < sz && heap[l] > heap[i])
    {
        m = l;
    }
    if (r < sz && heap[r] > heap[i])
    {
        m = r;
    }
    if (m != i)
    {
        swap(heap[m], heap[i]);
        heapify(m);
    }
}

int maxheap ::rgls(int i)
{
    int cnt = 0;
    // if(2 * i + 1 < sz && 2 * i + 2 < sz){
    //     return cnt;
    // }
    while (sz - 1)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < sz)
        {
            if (r < sz)
            {
                if (r > l)
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    maxheap mh;
    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        mh.insert(x);
    }

    mh.build();

    mh.rgls(0);

    return 0;
}