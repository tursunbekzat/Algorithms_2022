#include <iostream>
#include <vector>
using namespace std;

int getHash(string s)
{
    const int m = 1e9 + 7;
    const int P = 11;
    int p = 1;
    int Hash = 0;
    int n = s.size();
    for (int i(0); i < n; i++)
    {
        Hash = (Hash + (s[i] - 91) * p) % m;
        p = (p * P) % m;
    }
    return Hash;
}

void print(vector<int> v)
{
    for (int k : v)
        cout << k << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int q;
    cin >> s >> q;

    vector<int> counts;
    int l, r;
    for (int i(0); i < q; i++)
    {
        int cnt = 0;
        cin >> l >> r;
        string sub = s.substr(l - 1, r - l + 1);
        // cout << "substring : " << sub << "\n";
        int h = getHash(sub);
        // cout << "hash substring is : " << h << "\n";
        for (int i(0); i < s.size(); i++)
        {
            string ssub = s.substr(i, sub.size());
            // cout << "ssubstrings : " << ssub << "\n";
            int sh = getHash(ssub);
            // cout << "hash ssubstring is : " << h << "\n";
            if (sh != h)
                continue;
            if (ssub == sub)
                cnt++;
            // cout << "count is = " << cnt << "\n";
        }
        counts.push_back(cnt);
    }

    print(counts);
    return 0;
}