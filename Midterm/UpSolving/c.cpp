#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long heap[10010000], heap1[10010000];
int sz = 0;

void heapify(int i)
{
    int l = 2 * i + 1, r = 2 * i + 2;
    int mx = i;
    if (i < sz && heap[mx] < heap[l])
    {
        mx = l;
    }
    if (i < sz && heap[mx] < heap[r])
    {
        mx = r;
    }
    if (mx != i)
    {
        swap(heap[i], heap[mx]);
        heapify(mx);
    }
}

void heapify1(int i)
{
    int l = 2 * i + 1, r = 2 * i + 2;
    int mx = i;
    if (i < sz && heap1[mx] < heap1[l])
    {
        mx = l;
    }
    if (i < sz && heap1[mx] < heap1[r])
    {
        mx = r;
    }
    if (mx != i)
    {
        swap(heap1[i], heap1[mx]);
        heapify1(mx);
    }
}

void build()
{
    for (int i = sz / 2; i >= 0; i--)
    {
        heapify(i);
    }
}

void build1()
{
    for (int i = sz / 2; i >= 0; i--)
    {
        heapify1(i);
    }
}

void print()
{
    for (int i(0); i < sz; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void print1()
{
    for (int i(0); i < sz; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void heapsort()
{
    build1();
    int s = sz;
    while (sz > 1)
    {
        swap(heap1[0], heap1[sz - 1]);
        sz--;
        heapify1(0);
    }
    sz = s;
}

int binarySearch(int k, int l, int r)
{
    cout << "bs print1: \n";
    print1();
    while (l <= r)
    {
        int mid = (l + r) / 2;
        cout << "heap " << heap1[mid] << endl;
        if (heap1[mid] < k)
        {
            l = mid + 1;
        }
        else if (heap1[mid] > k)
        {
            r = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return 0;
}

int main()
{
    cin >> sz;
    for (int i(0); i < sz; i++)
    {
        cin >> heap[i];
    }
    build();

    vector<unsigned long long> v, v1;
    int k;
    cin >> k;
    int j, c;

    for (int i(0); i < k; i++)
    {
        cin >> j >> c;
        heap[j - 1] = c + heap[j - 1];
        v.push_back(heap[j - 1]);
    }
    build();
    for (int i(0); i < sz; i++)
    {
        heap1[i] = heap[i];
    }
    print();
    print1();
    heapsort();
    print1();

    cout << "size " << sz << endl;
    for (int i(0); i < k; i++)
    {
        cout << "v[i] = " << v[i] << endl;
        cout << binarySearch(v[i], 0, sz) << endl;
    }

    print();

    return 0;
}