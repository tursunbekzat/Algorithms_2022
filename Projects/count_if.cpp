#include <bits/stdc++.h>

using namespace std;

bool isEven(int x)
{
    return x % 2 == 0;
}

int main()
{
    vector<int> num;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        num.push_back(x);
    }
    int cnt = count_if(num.begin(), num.end(), isEven);
    cout << cnt << endl;
}