#include <bits/stdc++.h>
using namespace std;

long long f(string s){

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
}

int main(){
    int n;
    cin >> n;
    int k = 2 * n;
    string arr[k];
    set<string> st;
    for(int i = 0; i < k; i++){
        cin >> arr[i];
        st.insert(arr[i]);
    } 
    int cnt = 0;
    for(int i = 0; i < k; i++){
        string h = to_string(f(arr[i]));
        if(st.find(h) != st.end()){
                cout << "Hash of string \"" << arr[i] << "\" is " << h << "\n"; 
                cnt ++;
            }
        if(cnt == n){
            break;
        }
    }
}