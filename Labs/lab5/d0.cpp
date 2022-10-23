// C++ code to demonstrate the working of
// make_heap(), front()
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Initializing a vector
    vector<int> v1;

    int n, k, x;
    cin >> n >> k;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        v1.push_back(-1 * x);
    }
    // Converting vector into a heap
    // using make_heap()
    make_heap(v1.begin(), v1.end());

    int cnt = 0;
    unsigned long long ans = 0;
    while ((-1) * v1.front() < k)
    {    
        cnt++;
        if (v1.size() < 2)
        {
            cout << -1 << endl;
            return 0;
        }
        unsigned long long a = v1.front();
        swap(v1.front(), v1.back());
        v1.pop_back();
        make_heap(v1.begin(), v1.end());
        unsigned long long b = v1.front();
        swap(v1.front(), v1.back());
        v1.pop_back();
        v1.push_back(a + 2 * b);
        make_heap(v1.begin(), v1.end());
    }
    cout << cnt << endl;
    return 0;
}
