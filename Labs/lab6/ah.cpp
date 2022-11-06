#include <iostream>
using namespace std;

int n;
char w[100000];
char vowels[6] = {'a', 'e', 'o', 'i', 'u', 'y'};

void print(int n);

bool binarysearch(char c, int l, int r)
{
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (vowels[m] > c)
        {
            r = m - 1;
        }
        else if (vowels[m] < c)
        {
            l = m + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

struct maxheap
{
    char c;
    maxheap *left, *right;
    maxheap(char c)
    {
        this->c = c;
        left = right = NULL;
    }
};

void heapify(int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int m = i;
    if(l < n && w[l] > w[m]){
        bool ol = binarysearch(w[l], 0, 6);
        bool om = binarysearch(w[m], 0, 6);

        if((!ol && !om) or (ol && om)){
            m = l;
        }
    }
    if(r < n && w[r] > w[m]){
        bool oR = binarysearch(w[r], 0, 6);
        bool om = binarysearch(w[m], 0, 6);

        if((!oR && !om) or (oR && om)){
            m = r;
        }
    }
    if(m != i){
        swap(w[i], w[m]);
        heapify(m);
    }
}

void build()
{
    for (int i(n / 2); i >= 0; i--)
        heapify(i);
}

void heapsort()
{
    build();
    while (n > 1)
    {
        swap(w[0], w[n - 1]);
        n--;
        heapify(n-1);
    }
}

void print(int n)
{
    for (int i(n - 1);i>=0;i--)
    {
        cout << w[i];
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    maxheap *root = NULL;

    cin >> n;
    for (int i(0); i < n; i++)
    {
        cin >> w[i];
    }

    int sz = n;
    heapsort();

    print(sz);

    return 0;
}