#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

bool isEven(int x)
{
    return x % 2 == 0;
}

int main()
{
    vector<int> num;
    for (int i = 0; i < 10; i++)
    {
        num.push_back(i);
    }
    rotate(num.begin(), num.begin() + 2, num.end());
    for (int i = 0; i < 10; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}