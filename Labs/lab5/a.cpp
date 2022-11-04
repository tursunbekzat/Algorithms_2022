#include <iostream>
using namespace std;

unsigned long long heap[200010];
int q = 0;

void heapify(int i)
{
    int left = i + i + 1;
    int right = i + i + 2;

    int mx = i;

    if (left < q && heap[left] < heap[mx])
    {
        mx = left;
    }
    if (right < q && heap[right] < heap[mx])
    {
        mx = right;
    }

    if (mx != i)
    {
        swap(heap[i], heap[mx]);
        heapify(mx);
    }
}

void build()
{
    for (int i = q / 2; i >= 0; i--)
    {
        heapify(i);
    }
}

void insert(unsigned long long value)
{
    heap[q++] = value;
    int i = q - 1;
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (heap[i] < heap[p])
        {
            swap(heap[i], heap[p]);
            i = p;
        }
        else
        {
            break;
        }
    }
}

void deleteMin()
{
    swap(heap[0], heap[q - 1]);
    q--;
    heapify(0);
}

void print()
{
    for (int i = 0; i < q; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void heapsort()
{
    build();
    while (q > 1)
    {
        swap(heap[0], heap[q - 1]);
        q--;
        heapify(0);
    }
}

int main()
{
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> heap[i];
    }

    build();

    // unsigned long long ans = 0;

    // while (q > 1)
    // {
    //     unsigned long long a = heap[0];
    //     deleteMin();
    //     unsigned long long b = heap[0];
    //     deleteMin();
    //     ans += a + b;
    //     insert(a + b);
    // }
    // cout << heap[0] << endl;

    // cout << ans << endl;
    int sz = q;
    heapsort();
    q = sz;
    print();
    return 0;
}