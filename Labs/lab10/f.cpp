#include <bits/stdc++.h>
using namespace std;

#define MAX_NODES 100005
int parent[MAX_NODES];
int size_set[MAX_NODES];

int find_set(int v){
	if (v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}
int main()
{
	int n, m ; cin >> n >> m;
    for(int i = 1; i<=n; i++){
        parent[i] = i;
	    size_set[i] = i;
    }
	
    while(m--){
        int a,b; cin >> a >> b;
        a = find_set(a);
	    b = find_set(b);
	    if (a != b) {
		    if (size_set[a] < size_set[b]) swap(a, b);
		    parent[b] = a;
		    size_set[a] += size_set[b];
        }
    }
	int start,end; cin >> start >> end;
	if (find_set(start) == find_set(end)) cout << "YES";
    else cout << "NO";
	return 0;
}

