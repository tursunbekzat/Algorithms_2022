#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void print(int x)
{
    cout << 2 * x << " ";
}

int main()
{
    vector<int> num;
    for (int i = 0; i < 10; i++)
    {
        num.push_back(i);
    }
    for_each(num.begin(), num.end(), print);
    cout << endl;
}