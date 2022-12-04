#include <iostream>
#include <queue>

using namespace std;

struct vertex
{
    int r, c;
    vertex(int r, int c){
        this->r = r;
        this->c = c;
    }
};

char a[100][100];
queue <vertex> q;

void step(int r, int c, int n, int m){
    if(r < n && r >= 0 && c < m && c >= 0 && a[r][c] == '1'){
        a[r][c] = '2';
        q.push(vertex(r,c));
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '1'){
                q.push(vertex(i,j));
                while (q.size() > 0)
                {
                    vertex cur = q.front(); 
                    q.pop();
                    step(cur.r + 1, cur.c, n, m);
                    step(cur.r - 1, cur.c, n, m);
                    step(cur.r, cur.c + 1, n, m);
                    step(cur.r, cur.c - 1, n, m);
                }
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}