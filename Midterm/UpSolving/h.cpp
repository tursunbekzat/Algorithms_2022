#include <iostream>
using namespace std;

struct maxheap
{
    int sz;
    int heap[100000];

    maxheap();
    void insert(int val);
    void heapify(int i);
    int rgls(int i);
    void print();
};

maxheap::maxheap()
{
    sz = 0;
}

void maxheap ::insert(int val)
{
    sz++;
    heap[sz-1] = val;
    heapify(sz-1);
}

void maxheap ::heapify(int i)
{
    int p = (i - 1) / 2;
    if(heap[p] < heap[i]){
        swap(heap[p], heap[i]);
        heapify(p);
    }
}

void maxheap ::print(){
    for(int i(0);i<sz;i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}

int maxheap ::rgls(int i)
{
    int cnt = 0;
    while (i < sz)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < sz)
        {
            if (r < sz)
            {
                if (heap[r] > heap[l])
                {
                    cnt++;
                }
            }
        }
        i++;
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

    // mh.print();
    cout << mh.rgls(0) << "\n";

    return 0;
}