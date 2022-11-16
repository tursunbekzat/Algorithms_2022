#include <bits/stdc++.h>
using namespace std;

set < int > st;

void f(string s, string t){
    size_t n = s.size();
    size_t m = t.size();
    long long p[n];
    long long h[n];
    long long q = LONG_LONG_MAX;
    p[0] = 1;
    for(size_t i = 1; i < max(n, m); i++){
        p[i] = (p[i - 1] * 31) % q;
    }
    for(size_t i = 0; i < n; i++){
        h[i] = ((s[i]  - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }
    long long h_t = 0;
    for(size_t i =0; i < m; i++){
        h_t = (h_t + ((t[i] - int('a') + 1) * p[i]) % q) % q; 
    }
    for(size_t i = 0; i + m - 1 < n; i++){
        long long d = h[i + m - 1];
        if(i > 0){
            d -= h[i - 1];
        }
        if(d == h_t * p[i] && s.substr(i, m) == t){
            for(size_t j = i; j < i + m; j++ ){
                st.insert(j);
            }
        } 
    }
}

int main(){
    string s;
    int n;
    cin >> s >> n;
    while(n > 0){
        string t;
        cin >> t;
        f(s, t);
        n --;
    }
    if(s.size() == st.size()){
        cout << "YES";
    }
    else cout << "NO";

}