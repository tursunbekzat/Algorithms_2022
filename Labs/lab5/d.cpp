#include <iostream>
#include <algorithm>
#include <cmath>
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
    // int s = sz;
    while (q > 1)
    {
        swap(heap[0], heap[q - 1]);
        q--;
        heapify(0);
    }
}

int main()
{
    int k;
    cin >> q >> k;
    for (int i = 0; i < q; i++)
    {
        cin >> heap[i];
    }

    build();
    // print();
    int cnt = 0;
    while (heap[0] < k)
    {
        if (q < 2)
        {
            cout << -1 << endl;
            return 0;
        }
        cnt++;
        unsigned long long a = heap[0];
        deleteMin();
        unsigned long long b = heap[0];
        deleteMin();
        insert(a + 2 * b);
    }
    cout << cnt << endl;
    return 0;
}