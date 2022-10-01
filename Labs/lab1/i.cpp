#include <iostream>
#include <stack>
#include <deque>

using namespace std;

int main()
{
    stack<char> st;
    deque<char> d;
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        d.push_back(s[i]);
    }
    int cnt = 0;
    while (d.size() > 1)
    {
        if(cnt > 2 * n){
            break;
        }
        cnt++;
        if (st.empty())
        {
            st.push(d.front());
            d.push_back(d.front());
            d.pop_front();
        }
        if (st.top() != d.front())
        {
            d.pop_front();
            st.pop();
        }
        else
        {
            st.push(d.front());
            d.push_back(d.front());
            d.pop_front();
        }
    }

    string answer;
    if (d.back() == 'S')
    {
        answer = "SAKAYANAGI";
    }
    else
    {
        answer = "KATSURAGI";
    }
    cout << answer;
    return 0;
}