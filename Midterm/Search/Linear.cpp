#include <iostream>
#include<vector>
using namespace std;

vector<int> v;

void Find(int k){
    for(int i(0);i<v.size();i++){
        if(v[i] == k){
            cout << "yes" << endl;
            return;
        }
    }
    cout << "no" << endl;
}

int main()
{
    int n, k;
    cin >> n;
    for(int i(0);i<n;i++){
        cin >> k;
        v.push_back(k);
    }
    cin >> k;
    Find(k);
    return 0;
}