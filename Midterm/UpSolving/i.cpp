#include <iostream>
#include <deque>
#include <stack>
using namespace std;

stack<int> st;

void convert_to_binary(unsigned long long x)
{
    while (x > 0)
    {
        // de.push_back(x % 2);
        st.push(x % 2);
        x /= 2;
    }
}

void delet()
{
    while (!st.empty())
    {
        st.pop();
    }
    cout << endl;
}

string check_good()
{
    stack<int> st1;
    while (!st.empty())
    {
        if (st1.empty())
        {
            if (st.top() == 0)
            {
                return "NO";
            }
            st1.push(st.top());
            st.pop();
            continue;
        }
        if (st1.top() == st.top())
        {
            st1.push(st.top());
        }
        else
        {
            st1.pop();
        }
        st.pop();
    }
    if (st1.empty())
        return "YES";
    while(!st1.empty()){
        st1.pop();
    }
    return "NO";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unsigned long long x;
    string s;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        convert_to_binary(x);
        cout << check_good();
        delet();
    }

    return 0;
}