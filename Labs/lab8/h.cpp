#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<string, int> long_substr;
vector<string> ss;

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

void find(string s, int k)
{
    for (int i(0); i < s.size(); i++)
    {
        for (int j(i); j < s.size(); j++)
        {
            string sub = s.substr(i, j);
            if (long_substr[sub] == k)
                long_substr[sub]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    for (int i(0); i < n; i++)
    {
        cin >> s;
        ss.push_back(s);
        find(s, i);
    }

    map<string, int>::iterator it;
    for (it = long_substr.end(); it != long_substr.begin(); it--)
    {
        if((*it).second == n)
            cout << (*it).first << "\n";
    }

    return 0;
}