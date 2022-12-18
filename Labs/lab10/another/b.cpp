#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int d[n];

    for(int i = 0; i < n; i++){
        d[i] = -1;
    }

    int a[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    int s, t;

    cin >> s >> t;
    s--; t--;
    
    queue<int> q;
    
    d[s] = 0;
    q.push(s);

    while (q.size() > 0)
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(a[cur][i] == 1 && d[i] == -1){
                d[i] = d[cur] + 1;
                q.push(i);
            }
        }
    }
    
    cout << d[t];

    return 0;
}