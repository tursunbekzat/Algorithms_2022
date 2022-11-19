#include <bits/stdc++.h>
#define ll long long 
using namespace std;



int mod = 1e9 + 7; 
 
 
class HM{ 
    vector<bool>  ar; 
    vector<ll> v; 
    ll size; 
public: 
    HM(){ 
        size = mod/1000; 
        ar.resize(size); 
    } 

    void add(ll x, ll h){ 
        h = h%size; 
        v.push_back(h); 
        ar[h] = true; 
    }

    bool find(ll h){ 
        h = h%size; 
        return ar[h]; 
    }

    void set_false(){ 
        for(ll i = 0; i < v.size(); i++) ar[i] = false; 
        v.clear(); 
    }

}; 
 
int n;

string s[11]; 
 
 
string sub(ll m){ 
    for(int i = 0; i < n; i++) if (m >= s[i].size()) return ""; 
    
    static HM hm[10]; 
    
    ll D = 27, H = 1; 
    
    for(int i = 0; i < m-1; i++) H = (H*D)%mod; 
    
    for(int j = 0; j < n-1; j++){ 
        ll t = 0; 
        for(int i = 0; i < m-1; i++) t = (D*t + s[j][i])%mod; 
        for(int i = 0; i < s[j].size()-m+1; i++){ 
            t = ((D * (t - (i ? s[j][i-1] : 0)*H) + s[j][i+m-1])%mod + mod)%mod; // rehashing 
            hm[j].add(i+m, t); 
        } 
    } 
    
    string ans = ""; 
    ll t = 0; 
    for(int i = 0; i < m-1; i++) t = (D*t + s[n-1][i])%mod; 
    for(int i = 0; i < s[n-1].size()-m+1; i++){ 
        t = ((D * (t - (i ? s[n-1][i-1] : 0)*H) + s[n-1][i+m-1])%mod + mod)%mod; // rehashing 
        bool flag = true; 
        for(int j = 0; j < n-1; j++) if (!hm[j].find(t)) flag = false; 
        if (flag) {ans = s[n-1].substr(i, m); break; } 
    } 
    for(int i = 0; i < n; i++) hm[i].set_false(); 
    return ans; 
 
}

string bin(){
    ll l = -1, r = 5001;
    while(l+1 < r){
        ll m = (r+l)/2;
        (sub(m) == "" ? r : l) = m;
    }

    return sub(l);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> s[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < s[i].size(); j++){
            s[i][j] -= 'a'-1;
        }
    }
    
    string ans = bin();
    
    for(int i = 0; i < ans.size(); i++)ans[i] += 'a'-1;
    
    cout << ans;
}