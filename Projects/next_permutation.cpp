// #include <bits/stdc++.h>
// #include <algorithm>

// using namespace std;

// void print(int x)
// {
//     cout << x << " ";
// }

// int main()
// {
//     vector<int> num;
//     for (int i = 0; i < 3; i++)
//     {
//         num.push_back(i);
//     }
//     int cnt = 1;
//     for_each(num.begin(), num.end(), print);
//     cout << endl;
//     while (next_permutation(num.begin(), num.end()))
//     {
//         cnt++;
//         for_each(num.begin(), num.end(), print);
//         cout << endl;
//     }
//     cout << cnt;
//     cout << endl;
// }

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void print(int x)
{
    cout << x << " ";
}

int main()
{
    vector<int> num;
    for (int i = 4; i >= 0; i--)
    {
        num.push_back(i);
    }
    int cnt = 1;
    for_each(num.begin(), num.end(), print);
    cout << endl;
    while (prev_permutation(num.begin(), num.end()))
    {
        cnt++;
        for_each(num.begin(), num.end(), print);
        cout << endl;
    }
    cout << cnt;
    cout << endl;
}
