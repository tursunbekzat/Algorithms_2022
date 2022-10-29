#include <iostream>
using namespace std;

int sz = 0;
unsigned long long heap[1000001];

void heapify(int i)
{
    int l = 2 * i + 1, r = 2 * i + 2, m = i;
    if (l < sz && heap[l] > heap[m])
        m = l;
    if (l < sz && heap[r] > heap[m])
        m = r;
    if (m != i)
    {
        swap(heap[i], heap[m]);
        heapify(m);
    }
}

void build()
{
    for (int i(sz / 2); i >= 0; i--)
    {
        heapify(i);
    }
}

void heapsort()
{
    build();
    int size = sz;
    while (size > 1)
    {
        swap(heap[0], heap[size - 1]);
        size--;
        heapify(0);
    }
}

void sum(int j)
{
    unsigned long long sum = 0;
    for (int i(0); i < sz - j; i++)
    {
        sum += heap[i];
    }
    cout << sum << endl;
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
    int n, m;
    cin >> n >> m;

    string c;
    int x, cnt = 0, j = 0;
    for (int i(0); i < n; i++)
    {
        cin >> c;
        if (cnt >= n)
        {
            j++;
        }
        else if (c == "insert")
        {
            cnt++;
            cin >> x;
            heap[sz] = x;
            sz++;
        }
        else
        {
            heapsort();
            print();
            sum(j);
        }
    }

    return 0;
}