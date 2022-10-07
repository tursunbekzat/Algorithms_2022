#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int n, k, x;
    cin >> n >> k;
    vector<int> v;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    int sum = accumulate(v.begin(), v.end(), 0);
    int val = sum / k;
    int Sum = 0, max2 = 0, max1 = 0;
    cout << "Sum: " << sum << "val: " << val << endl;
    for (int i(0); i < n; i++)
    {
        Sum += v[i];
        if (Sum > val)
        {

            // cout << "Sum: " << Sum << endl
            //      << "i: " << i << endl;
            if (Sum > max2)
            {
                max2 = Sum;
            }
            Sum = 0;
        }
    }
    Sum = 0;
    for (int i(0); i < n; i++)
    {
        Sum += v[i];
        if (Sum >= val)
        {

            // cout << "Sum: " << Sum << endl
            //      << "i: " << i << endl;
            if (Sum > max1)
            {
                max1 = Sum;
            }
            Sum = 0;
        }
    }
    cout << max2 << " " << max1 << endl;
    if (max2 > max1 && max1 != 0)
    {
        cout << max1 << endl;
        return 0;
    }
    else if (max2 <= max1 && max2 != 0)
    {
        cout << max2 << endl;
    }
    else
    {
        cout << max(max2, max1);
    }
    return 0;
}