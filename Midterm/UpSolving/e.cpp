#include <iostream>
#include <stack>
using namespace std;

struct Stack
{
    stack<int> st;
    stack<int> st1;

    // Stack();
    void add(int val);
    void delet();
    void getmax();
    void getcur();
};

void Stack ::add(int val)
{
    if (st1.empty())
    {
        st1.push(val);
    }
    else
    {
        if (st1.top() <= val)
        {
            st1.push(val);
        }
    }
    st.push(val);
}

void Stack ::delet()
{
    if (st.empty())
    {
        cout << "error" << endl;
        return;
    }
    if (st.top() == st1.top())
    {
        st1.pop();
    }
    st.pop();
}

void Stack ::getcur()
{
    if (st.empty())
    {
        cout << "error\n";
        return;
    }
    cout << st.top() << "\n";
}

void Stack ::getmax()
{
    if (st.empty())
    {
        cout << "error\n";
        return;
    }
    cout << st1.top() << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    Stack st;
    string s;
    int x;
    for (int i(0); i < n; i++)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> x;
            st.add(x);
        }
        else if (s == "delete")
        {
            st.delet();
        }
        else if (s == "getcur")
        {
            st.getcur();
        }
        else
        {
            st.getmax();
        }
    }

    return 0;
}