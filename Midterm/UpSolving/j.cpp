#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long heap[10000001];
int n;
int sz = 0;

void heapify(int i)
{
    int left = i + i + 1;
    int right = i + i + 2;

    int mx = i;

    if (left < sz && heap[left] > heap[mx])
    {
        mx = left;
    }
    if (right < sz && heap[right] > heap[mx])
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
    for (int i = sz / 2; i >= 0; i--)
    {
        heapify(i);
    }
}

void heapsort()
{
    build();
    while (sz > 0)
    {
        swap(heap[0], heap[sz - 1]);
        sz--;
        heapify(0);
    }
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

bool search(unsigned long long m)
{
    int l = 0;
    int r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (heap[mid] < m)
        {
            l = mid + 1;
        }
        else if (heap[mid] > m)
        {
            r = mid - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    unsigned long long m;
    cin >> m >> n;

    for (int i(0); i < n; i++)
    {
        cin >> heap[i];
    }

    sz = n;
    heapsort();

    print();

    for (int i(0); i < n; i++)
    {
        if (search(m - heap[i]))
        {
            cout << heap[i] << " " << m - heap[i] << endl;
            break;
        }
    }

    return 0;
}