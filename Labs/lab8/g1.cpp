#include <bits/stdc++.h>
using namespace std;

void h(string s, string t){
    size_t n = s.size();
    size_t m = t.size();
    long long p[n];
    long long  h[n];
    long long q = LONG_LONG_MAX;
    p[0] = 1;
    for(int i = 1; i < n; i++ ){
        p[i] = (p[i - 1] * 31) % q;;
    }
    for(int i = 0; i < n; i++){
        h[i] = ((s[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }
    long long h_s = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        h_s = (h_s + ((t[i] - int('a') + 1) * p[i]) % q);
    }
    for(size_t i = 0; i + m - 1 < n; i++){
        long long d = h[i + m - 1];
        if(i > 0){
            d -= h[i - 1];
        }
        if(d == h_s * p[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin>> l >> r;
        string t = s.substr(l - 1, r - l + 1);
        h(s, t);
    }
}