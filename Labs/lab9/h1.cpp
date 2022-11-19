#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> mp;

void find(vector<int> p)
{
    int min = INT32_MAX;
    int m;
    if(p.size() % 2 == 0)
        m = 0;
    else    
        m = 1;
    for (int i(1); i < p.size(); i++)
    {
        if (p[i] % 2 == m)
        {
            if (!mp[p[i]])
            {
                min = p[i];
                mp[p[i]] = i;
            }
        }
    }
}

void computeLPSArray(string pat, vector<int> &lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pat.size())
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    string pat;
    cin >> pat;

    vector<int> p(pat.size());

    computeLPSArray(pat, p);

    find(p);

    int cnt = 0;

    // cout << '\n';
    // for (int x : p) cout << x << " ";
    // cout << '\n';

    for (auto it : mp)
    {
        // cout << it.first << "--" << it.second << '\n';
        string s1, s2;
        int AB_size = it.second + 1;
        if (AB_size == pat.size() || AB_size % 2 == 1) 
            continue;
        s1 = pat.substr(0, AB_size / 2); 
        s2 = pat.substr(AB_size / 2, AB_size / 2); 
        // cout << s1 << "--" << s2 << '\n';
        if (s1 == s2) cnt++;
        // cout << "cnt = " << cnt << "\n";
    }

    cout << cnt << '\n';
    return 0;
}