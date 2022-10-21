#include <iostream>
using namespace std;

unsigned long long heap[200010];
int sz = 0;

void heapify(int i)
{
    int left = i + i + 1;
    int right = i + i + 2;

    int mx = i;
    // cout << "left: " << left << "   right: " << right << endl;
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

void insert(unsigned long long value)
{
    heap[sz++] = value;
    int i = sz - 1;
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (heap[i] > heap[p])
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
    swap(heap[0], heap[sz - 1]);
    sz--;
    heapify(0);
}

void print()
{
    for (int i = 0; i < sz; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void heapsort()
{
    build();
    // int s = sz;
    while (sz > 1)
    {
        swap(heap[0], heap[sz - 1]);
        sz--;
        heapify(0);
    }
}

int main()
{
    cin >> sz;
    for (int i = 0; i < sz; i++)
    {
        cin >> heap[i];
    }

    build();
    // print();
    // unsigned long long ans = 0;
    // cout << sz << endl;
    while (sz > 1)
    {
        // cout << 1 <<endl;
        unsigned long long a = heap[0];
        deleteMin();
        unsigned long long b = heap[0];
        deleteMin();
        // ans += a - b;
        if(a > b){
            insert(a - b);
        }else if(b > a){
            insert(b - a);
        }else{
            insert(0);
        }
        // print();
    }
    cout << heap[0] << endl;

    // cout << ans << endl;
}