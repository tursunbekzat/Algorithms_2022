#include <iostream>
using namespace std;

unsigned long long heap[200100];
int sz = 0;

void heapify(int i)
{
    int l = 2 * i + 1, r = 2 * i + 2;
    int mid = i;
    if (i < sz && heap[mid] < heap[l])
    {
        mid = l;
    }
    if (i < sz && heap[mid] < heap[r])
    {
        mid = r;
    }
    if (mid != i)
    {
        swap(heap[i], heap[mid]);
        heapify(mid);
    }
}

void build()
{
    for (int i(sz / 2); i >= 0; i--)
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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i(0); i < n; i++)
    {
        cin >> heap[i];
    }

    build();

    print();

    return 0;
}