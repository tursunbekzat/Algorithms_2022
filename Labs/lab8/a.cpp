#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long Hash(long long s)
{
    return s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<long long, long long> mp;

    int n;
    cin >> n;

    long long s;
    for (int i(0); i < 2 * n; i++)
    {
        cin >> s;
        long long h = Hash(s);
        mp[s] = h;
    }

    for (map<long long, long long>::iterator i = mp.begin(); i != mp.end(); ++i)
    {
        cout << (*i).first << " "<< (*i).second << endl;
    }

    // vector<pair<long long, long long>> v;

    // for(int i(0);i<mp.size();i++){
    //     if(mp[i] == mp[i+1]){
    //         v.push_back(make_pair(mp[i], mp[i + 1]));
    //     }
    // }

    return 0;
}