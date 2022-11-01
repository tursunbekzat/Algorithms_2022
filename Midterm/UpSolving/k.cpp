// You are given q queries. Also there is an empty array a .
// There are two types of queries:
// 1 x - add x to the end of array a;
// 2 - reverse the array a.

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> q;
stack<int> st;

void reverse()
{
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}


void print()
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int x, y;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y;
            q.push(y);
        }
        else
        {
            reverse();
        }
    }
    print();
}
