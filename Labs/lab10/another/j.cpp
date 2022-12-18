#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<pair<list<int>, int>> adj;    
    vector<bool> visited;

    public:
        Graph(int V);

        void addEdge(int v, int w);

        void BFS();
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
    visited.resize(V, false);
}

void Graph::addEdge(int v, int w){
    adj[v].first.push_back(w);
    adj[v].second = 0;
}

int cnt = 0;

void Graph::BFS(){
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            int ans = 0;
            queue <int> q;
            q.push(i);

            visited[i] = true;


            while(!q.empty()){
                int size = q.size();
                for(int x = 0; x < size; x++){
                    int val = q.front();
                    // cout << q.front() << ' ';
                    q.pop();

                    for(auto adjacent: adj[val].first){
                        if(!visited[adjacent]){
                            visited[adjacent] = true;
                            q.push(adjacent);
                            
                            adj[adjacent].second = adj[val].first.size();
                        }
                    }
                    if(adj[val].first.size() > adj[val].second){
                        // cout << val << ' ' << adj[val].first.size() << ' ' << adj[val].second << endl;
                        cnt++;
                    }
                }
                ans++;
            }
            if(ans == 1){
                cnt++;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for(int i = 0; i < m; i++){
        int v, w;
        cin >> v >> w;
        g.addEdge(v-1, w-1);
    }
    g.BFS();
    cout << cnt;
}