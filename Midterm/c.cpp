#include <iostream>

using namespace std;

unsigned long long heap[100100];
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

void build()
{
    for (int i = sz / 2; i >= 0; i--)
    {
        heapify(i);
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

int main()
{
    cin >> sz;
    for (int i(0); i < sz; i++)
    {
        cin >> heap[i];
    }
    build();

    int k;
    cin >> k;
    int j, c;
    for (int i(0); i < k; i++)
    {
        cin >> j >> c;
        heap[j - 1] = c + heap[j - 1];
    }
    build();
    
    print();

    return 0;
}