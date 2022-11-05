#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> dq;

void push(int y){
    dq.push_back(y);
}

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

    int cnt = 0;
    int x, y;
    while (n--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y;
            push(y);
        }
        else{
            cnt++;
        }
    }
    // if(cnt % 2 != 0)
    //     reverse(dq.begin(), dq.end());
    print();
    return 0;
}