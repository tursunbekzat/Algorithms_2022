// stack
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
    vector<int> ages;
    vector<int> values;
    values.push_back(-1);
    stack<int> st;
    bool ok;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ages.push_back(x);
    }
    st.push(ages[0]);
    for (int i = 1; i < n; i++)
    {
        ok = true;
        if (st.top() > ages[i])
        {
            st.pop();
            while (ok)
            {
                if (st.empty())
                {
                    values.push_back(-1);
                    break;
                }
                else
                {
                    if (st.top() > ages[i])
                    {
                        st.pop();
                    }
                    else
                    {
                        values.push_back(st.top());
                        break;
                    }
                }
            }
        }
        else
        {
            values.push_back(st.top());
        }
        st.push(ages[i]);
    }
    for (int i : values)
    {
        cout << i << " ";
    }
    return 0;
}