#include <bits/stdc++.h>
using namespace std;

int h(string s1, string s2, string t){
    size_t n = s1.size();
    size_t m = s2.size();
    size_t k = t.size();
    size_t size = min(n, m);
    long long h1[size];
    long long h2[size];
    long long p[size];
    long long q = LONG_LONG_MAX;
    p[0] = 1;
    for(size_t i = 1; i < max(size, k); i++){
        p[i] = (p[i-1] * 31) % q;
    }
    for(size_t i = 0; i < size; i++){
        h1[i] = ((s1[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h1[i] =  (h1[i] + h1[i - 1]) % q;
        }
    }
    for(size_t i = 0; i < size; i++){
        h2[i] = ((s2[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h2[i] =  (h2[i] + h2[i - 1]) % q;
        }
    }
    long long h_t = 0;
    for(size_t i = 0; i < k; i++){
        h_t = (h_t + ((t[i] - int('a') + 1) * p[i]) % q) % q;
    }
    int cnt = 0;
    for(size_t i = 0; i + k -1 < size; i++){
        long long d1 = h1[i + k - 1];
        long long d2 = h2[i + k - 1];
        if(i > 0){
            d1 -=  h1[i - 1];
            d2 -=  h2[i - 1];
            h_t = (h_t * 31) % q;
        }
        if(d1 == h_t){
            if(d1 == d2){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    string s;
    string t;
    string p;
    cin >> s >> t >> p;
    cout << h(s, t, p);
}