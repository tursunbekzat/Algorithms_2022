#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long a[1000000001];

void serach(unsigned long long k, int p)
{
    int l = 0;
    int r = p;
    while (l <= r)
    {
        int m = (l + r) / 2;
        unsigned long long ans = a[m] + a[p - 1 - m];
        if (ans == k)
        {
            cout << 1 << " " << 2;
            return;
        }
        if(ans < k){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
}

void heapify(int i, int n)
{
    int left = i + i + 1;
    int right = i + i + 2;

    int mx = i;

    if (left < n && a[left] > a[mx])
    {
        mx = left;
    }
    if (right < n && a[right] > a[mx])
    {
        mx = right;
    }

    if (mx != i)
    {
        swap(a[i], a[mx]);
        heapify(mx, n);
    }
}

void build(int n){
    for(int i(n/2);i>=0;i--){
        heapify(i, n);
    }
}

void heapsort(int n){
    build(n);

    while(n > 1){
        swap(a[0], a[n - 1]);
        n--;
        heapify(0, n);
    }
}

int main()
{
    int n;
    unsigned long long m;
    cin >> m >> n;

    for (int i(0); i < n; i++)
    {
        cin >> a[i];
    }

    int p = n;
    heapsort(n);

    serach(m, p);

    return 0;
}