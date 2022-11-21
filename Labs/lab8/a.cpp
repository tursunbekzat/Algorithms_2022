#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <sstream>
using namespace std;

int modulo = 1e9 + 7;
vector <string> v;

bool Find(string s){
    for (string x : v)
        if (x == s)
            return 1;

    return 0;
}

int Hash(string s)
{
    size_t n = s.size();
    long long p[n];
    long long q = 1e9 + 7;
    p[0] = 1;
    for(size_t i = 1; i < n; i++){
        p[i] = (p[i - 1] * 11) % q;
    }
    long long h = 0;
    for(size_t i = 0; i < n; i++){
        h = (h + ((s[i] - 47) * p[i]) % q) % q;
    }
    return h;

    // int h = 0;
    // for(int i(0);i<s.size();i++){
    //     h += (int(s[i] - 47) * pow(11, i));
    //     h %= modulo;
    // }

    // if (h < 0)
    //     return modulo + h;
    // return h;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    n *= 2;
    string s;
    while (n--)
    {
        cin >> s;
        v.push_back(s);
    }

    map <string, bool> checked;
    map <string, string> hashes;
    // map <string, string> all;

    while (true)
    {
        for (string x : v)
        {
            if (!checked[x])
            {
                int h = Hash(x);
                string HASH;
                stringstream ss;
                ss << h; ss >> HASH;
                // all[x] = HASH;
                if (Find(HASH))
                {
                    hashes[x] = HASH;
                    checked[x] = true;
                    checked[HASH] = true;
                }
            }
        }
        if (checked.size() == v.size())
            break;
    }
    
    for (auto it : hashes)
        cout << "Hash of string \"" << it.first << "\" is " << it.second << '\n';
    
    // for (auto it : all)
    //     cout << "String: " << it.first << "  Hash: " << it.second << '\n';

    return 0;

}