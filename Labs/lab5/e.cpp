#include <iostream>
using namespace std;

int sz;
unsigned long long heap[20000001];

void print(int j)
{
    unsigned long long sum = 0;
    for (int i(0); i < sz - j; i++)
    {
        sum += heap[i];
    }
    cout << sum << endl;
}

void insert(unsigned long long x)
{
    heap[sz] = x;
}

void heapify(int i)
{
    int l = i + i + 1;
    int r = i + i + 2;
    int mid = i;
    if(l < sz && heap[l] > heap[mid]){
        mid = l;
    }
    if(l < sz && heap[l] > heap[mid]){
        mid = l;
    }
    if(mid != i){
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

void heapsort()
{
    build();
}

int main()
{
    cin >> sz;
    int k;
    cin >> k;
    string s;
    unsigned long long x;
    int j = 0, cnt = 0;
    for (int i(0); i < sz; i++)
    {
        heap[i] = 0;
    }
    heapsort();
    for (int i(0); i < sz; i++)
    {
        cin >> s;
        if (s == "print")
        {
            heapsort();
            print(j);
        }
        else
        {

            cnt++;
            cin >> x;
            if (cnt > k)
            {
                j++;
                continue;
            }
            insert(x);
        }
    }

    return 0;
}