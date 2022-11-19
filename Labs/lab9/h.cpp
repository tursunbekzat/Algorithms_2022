#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector <pair <int, int> > v;

void find(vector<int> p)
{
    for (int i(0); i < p.size(); i++)
        if (p[i] % 2 == 0)
            v.push_back(make_pair(p[i], i));
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

    map <string, bool> mp;
    for (auto it : v)
    {
        string s1, s2;
        int AB_size = it.second + 1;
        if (AB_size == pat.size()) 
            continue;
        s1 = pat.substr(0, AB_size / 2); 
        s2 = pat.substr(AB_size / 2, AB_size / 2); 
        if (s1 == s2 && !mp[s1] && s1 != "")
        {
            // cout << it.first << "--" << it.second << '\n';
            // cout << s1 << "--" << s2 << '\n';
            cnt++;
            mp[s1] = true;
        }
    }

    cout << cnt << '\n';
    return 0;
}