#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map<int, vector<int>> adj;
    vector<int> level;

    public:
        Graph(int V);

        int addEdge(int v, int w, int level_current);

        void BFS(int s);

        void setlevel(int a, int level_current);

        void DFS(int begin, int end);
};

Graph::Graph(int V){
    this->V = V;
    level.resize(V, -1);
}

void Graph::setlevel(int a, int level_current){
    level[a] = level_current;
}

int Graph::addEdge(int v, int w, int level_current){
    if(level[w] == -1){
        adj[v].push_back(w);
        adj[w].push_back(v);
        level[w] = level_current;
        return 1;
    } 
    return 0;
}

void Graph::BFS(int s){
    vector <bool> visited(V, false);

    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i < size; i++){
            
            int val = q.front();
            q.pop();
            cout << val <<  ' ' << level[val] << endl;
            for(auto adjacent: adj[val]){
                if(!visited[adjacent]){
                    visited[adjacent] = true;
                    q.push(adjacent);
                }
            }
        }
    }
}

vector<int> path;
void Graph::DFS(int begin, int end){
    path.push_back(begin);
    // cout << begin << ' ' << level[begin] << endl;
    if(begin == end){
        return;
    }
    for(auto adjacent: adj[begin]){
        if(level[adjacent] == level[begin] - 1){
            DFS(adjacent, end);
        }
    }
}

int main(){

    int a, b;
    cin >> a >> b;

    Graph g(20000);

    queue<int> q;
    q.push(a);
    int level_current = 1;
    g.setlevel(a, level_current++);
    while(!q.empty()){
        int size = q.size();
        int stop = 0;
        for(int i = 0; i < size; i++){
            int val = q.front();
            q.pop();

            if(val == b){
                stop = 1;
                break;
            }
            if(val < b){
                if(g.addEdge(val, 2 * val, level_current) == 1){
                    q.push(2 * val);
                }
            }
            if(val - 1 > 0){
                if(g.addEdge(val, val-1, level_current) == 1){
                    q.push(val-1);
                }
            }
        }
        level_current++;
        if(stop == 1){
            break;
        }
    }

    // g.BFS(a);
    // cout << endl;
    g.DFS(b, a);
    cout << path.size() - 1 << endl;
    for(int i = path.size() - 2; i >= 0; i--){
        cout << path[i] << ' ';
    }
}