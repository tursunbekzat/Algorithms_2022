#include <iostream>
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2, t;
    cin >> s1 >> s2 >> t;
    int t_Hash = getHash(t);
    int cnt = 0;
    int n = min(s1.size(), s2.size()), m = t.size();
    for (int i(0); i < n; i++)
    {
        string sub1 = s1.substr(i, m);
        int sub1_Hash = getHash(sub1);
        if (sub1_Hash != t_Hash)
            continue;
        string sub2 = s2.substr(i, m);
        int sub2_Hash = getHash(sub2);
        if (sub2_Hash != sub1_Hash)
            continue;
        if (sub1 == sub2)
            cnt++;
    }

    cout << cnt << "\n";
    return 0;
}