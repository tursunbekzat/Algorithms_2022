#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int a[n][n];


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }    
    while (q--)
    {
        int q1, q2, q3;
        cin >> q1 >> q2 >> q3;
        if(a[q1-1][q2-1] == 1 && a[q2-1][q3-1] == 1 && a[q1-1][q3-1] == 1){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    


    return 0;
}