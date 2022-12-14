#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> dq;

void print()
{
    for (int i(0); i < dq.size(); i++)
    {
        cout << dq[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    bool ok = true;
    int x, y;
    int cnt = 0;
    while (n > 0)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y;
            if (ok)
                dq.push_back(y);
            else
            {
                dq.push_front(y);
            }
        }
        else
        {
            ok = !ok;
            cnt++;
        }
        n -= 1;
    }
    if(cnt % 2 != 0)
        reverse(dq.begin(), dq.end());
    print();
    return 0;
}