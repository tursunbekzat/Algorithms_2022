#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> q;
    int x;
    while (n)
    {
        int cnt = 0;
        cin >> x;
        q.push(x);
        while (q.front() < x - 3000)
        {
            q.pop();
            if (q.empty())
                break;
        }
        cout << q.size() << " ";
        n--;
    }
    cout << "\n";

    return 0;
}