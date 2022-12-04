// Find longest substring one letter
// aaaaddfsgsaagsa ansewr is: a 4 times

#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    map<char, int> mp;

    for (int i(0); i < s.size(); i++)
    {
        if (mp[i] != 0 && s[i - 1] != s[i] && i != 0)
            continue;
        if (s[i] == s[i + 1])
            mp[s[i]] += 1;
    }

    int maxi = 0;
    char ik = 0;
    map<char, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second > maxi)
        {
            maxi = (*it).second;
            ik = (*it).first;
        }
    }
    cout << ik << " " << maxi + 1 << "\n";
    return 0;
}