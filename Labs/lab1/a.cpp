#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        deque<int> d;
        int m;
        cin >> m;
        d.push_front(m);
        for (int i = m - 1; i > 0; i--)
        {
            d.push_back(i);
            int j = i + 1;
            while (j != 0)
            {
                d.push_front(d.back());
                d.pop_back();
                j--;
            }
        }
        for (int i : d)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}