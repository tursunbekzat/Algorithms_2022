#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> v; 
vector <int> check;

vector <int> ans (queue <int> q, vector <bool> vis){
    vector <int> answ;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        vis[cur] = true;
        answ.push_back(cur);
        for(auto it: v[cur]){
            if(not vis[it]){
                check[it]--;
                if(check[it] == 0){
                    q.push(it);
                }
            }
        }



    }
    return answ; 
}

int main(){
    int n, m;
    cin >> n >> m;
    v.assign(n + 1, vector <int> ());
    check.assign( n + 1, 0);
    while(m --){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        check[y]++;
    }
    queue <int> q;
    for(int i = 1; i <= n; i++){
        if(check[i] == 0){
            q.push(i);
        }
    }
    vector <bool> vis(n + 1, 0);
    vector <int> answer = ans(q, vis);
    if(answer.size() < n){
        cout << "Impossible" << endl;
    }
    else {
        cout << "Possible" << endl;
        for(int i = 0; i < n; i++){
            cout << answer[i] << " ";
        }
    }
    return 0;
}