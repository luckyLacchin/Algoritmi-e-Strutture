#include <vector>
#include <iostream>
#include <stack>


using namespace std;

bool shangai (vector<int> x, vector<int> y, int n, int m);
stack <int> topSort (vector<vector<int>> &g, int nodi);
void ts_dfs (vector <vector <int>> &g, int u, bool *visited, stack<int>&s);
bool hasCycle (vector<vector<int>> &g);
bool hasCycleRec (vector<vector<int>> &g, int u, vector<int> &dt, vector <int> &ft, vector <bool> &visited, int time);

int main () {

    int m, n;
    vector<int> x;
    vector<int> y;
    x.resize(m);
    y.resize(m);
    cout << "Puoi vincere a shangai?" << (shangai(x,y,n,m) ? "Si": "No");

    return 0;
}

bool shangai (vector<int> x, vector<int> y, int n, int m) {
    vector<vector<int>> g;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        g[x[i]].push_back(y[i]);
    }
    if (hasCycle(g))
        return false;
    else
        return true;


}

stack <int> topSort (vector<vector<int>> &g, int nodi) {

    stack <int> s;
    bool *visited = new bool [nodi];
    for (int i = 0; i < nodi; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < nodi; i++) {
        if (visited[i] == false) {
            ts_dfs(g,i,visited,s);
        }
    }

    delete [] visited;
    return s;
}

void ts_dfs (vector <vector <int>> &g, int u, bool *visited, stack<int>&s) {
    visited[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        if(visited[g[u][i]] == false) {
            ts_dfs (g,g[u][i],visited,s);
        }
    }
    s.push(u);
}

bool hasCycle (vector<vector<int>> &g) {

    vector <int> dt;
    vector <int> ft;
    vector <bool> visited;
    dt.resize(g.size());
    ft.resize(g.size());
    visited.resize(g.size()); 
    for (int u = 0; u< g.size(); u++) {
        if (!visited[u])
            if (hasCycleRec(g,u,dt,ft, visited,0))
                return true;
    }
    return false;

}
bool hasCycleRec (vector<vector<int>> &g, int u, vector<int> &dt, vector <int> &ft, vector <bool> &visited, int time) {
    visited[u] = true;
    time = time + 1;
    dt[u] = time;
    for (int v : g[u]) {
        if (dt[u] == 0) {
            if(hasCycleRec(g,v,dt,ft,visited,time))
                return true;
        }
        if (dt[u]<dt[v] && ft[v] == 0)
            return true;
    }
    time = time + 1; 
    ft[u] = time;
    return false;
}