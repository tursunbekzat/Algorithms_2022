#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix(string& s){
    vector<int> p(s.size());
    p[0] = 0;

    for(int i(1);i<s.size()-1;i++){
        int j = p[i];
    }

    return p;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> p = prefix(s);

    for(int s:p)
        cout << s;
    cout << "\n";

    return 0;

}