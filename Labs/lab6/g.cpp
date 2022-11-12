#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, string> oldlogins;
    map<string, string> newlogins;
    vector<string> v;
    string old, nnew;

    int n;
    cin >> n;

    for (int i(0); i < n; i++)
    {
        cin >> old >> nnew;
        oldlogins[old] = nnew;
        newlogins[nnew] = old;
        if (newlogins[old] == "")
            v.push_back(old);
    }

    vector< pair < string,string > > pass;

    for(string i:v){
        string orig = i;
        while(oldlogins[i]!="") {
            if(oldlogins[i] == orig) {i = oldlogins[i];break;}
            i = oldlogins[i];
        }
        pass.push_back(make_pair(orig,i));
    }

    // for (map<string, string>::iterator i = newlogins.begin(); i != newlogins.end(); ++i)
    // {
    //     cout << (*i).first << ": " << (*i).second << endl;
    // }

    cout << pass.size() << '\n';
    
    for(int i = pass.size()-1;i >= 0;i--) {
        cout << pass[i].first <<" "<< pass[i].second << "\n";
    }

    return 0;
}