#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;
stack <int> topSort (vector<vector<int>> &g, int nodi);
void ts_dfs (vector <vector <int>> &g, int u, bool *visited, stack<int>&s);
vector <vector <int>> transpose (vector<vector<int>> &g,int nodi);
vector<int> cc (vector<vector<int>> &g, stack <int> s);
void ccdfs (vector<vector<int>> &g, int counter, int u, vector<int> id);
vector<int> scc(vector<vector<int>> &g, int nodi);

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
vector <vector <int>> transpose (vector<vector<int>> &g,int nodi) {

    vector<vector<int>> trasposta;
    trasposta.resize(nodi);
    for (int i = 0; i < nodi; i++) {
        for (int j : g[i]){
            trasposta[j].push_back(i);
        }
    }
    return  trasposta;
}
vector<int> cc (vector<vector<int>> &g, stack <int> s) {
    
    vector <int> id;
    id.resize(g.size(),0);
    int counter = 0;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (id[u]==0){
            counter = counter + 1;
            ccdfs(g,counter,u,id);
        }
    }
    return id;
}

void ccdfs (vector<vector<int>> &g, int counter, int u, vector<int> id) {
    id[u] = counter;
    for (int v : g[u]) {
        if(id[v] == 0) {
            ccdfs (g,counter,g[u][v],id);
        }
    }
}
vector<int> scc(vector<vector<int>> &g, int nodi) {
    stack <int> s = topSort (g, nodi);
    vector<vector<int>> trasposta = transpose (g,nodi);
    return cc(trasposta,s);
}