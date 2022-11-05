#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void print(deque<int> dq)
{
    for (auto it = dq.begin(); it != dq.end(); ++it)
        cout << *it << " ";
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    deque<int> dq;

    int n;
    cin >> n;

    int x, y;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        // if (x == 1)
        dq.push_back(y);
        // else
        //     reverse(dq.begin(), dq.end());
        print(dq);
    }
    return 0;
}