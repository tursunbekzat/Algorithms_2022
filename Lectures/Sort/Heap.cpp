#include <iostream>
using namespace std;

char heap[200010];
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
    // int s = sz;
    while(sz > 1)
    {
        swap(heap[0], heap[sz-1]);
        sz--;
        heapify(0);
    }
}


void print()
{
    for (int i = 0; i < sz; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    sz = n;
    for (int i = 0; i < sz; i++)
    {
        cin >> heap[i];
    }
    // heapsort();
    build();
    for(int i(0);i<n;i++){
        cout << heap[i] << " ";
    }
    // print();
    cout << endl;
}