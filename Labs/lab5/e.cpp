#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Insert(vector<int> *v, int x)
{
    (*v).push_back(x);
}

void Print(vector<int> v, int j)
{
    int sum = 0;
    for (int i(j); i < v.size(); i++)
    {
        sum += v[i];
    }
    cout << sum << endl;
}

int main()
{
    vector<int> v;
    int q, k, x;
    cin >> q >> k;
    string s;
    int cnt = 0, cnt1 = 0;
    for (int i(0); i < q; i++)
    {
        cin >> s;
        if (s == "insert")
        {
            cnt++;
            cin >> x;
            Insert(&v, x);
        }
        else
        {
            if(cnt > k){
                sort(v.begin(), v.end());
                cnt1++;
                Print(v, cnt1);
                continue;
            }
            Print(v, 0);
        }
    }
    cout << cnt << " " << cnt1 << endl;
    return 0;
}