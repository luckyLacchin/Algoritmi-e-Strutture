#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

int dfs (vector<vector<int>> adj, int r) {
    
    stack <int> s;
    s.push(r);
    int res = 0; 
    bool *visited = new bool [adj.size()]; 
    for (int i = 0; i < adj.size(); i++) {
        visited[i] = false;
    }
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (visited[u] == false) {
            visited[u] = true;
            ++res;
            for (int i = 0; i < adj[u].size(); i++) {
                s.push(adj[u][i]);
            }
        }
    }
    return res;
}

void dfs_better (vector<vector<int>> adj, int r) {
    
    stack <int> s;
    s.push(r); 
    vector <bool> visited;
    visited.resize(adj.size(),false);
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (visited[u] == false) {
            visited[u] = true;
            for (int i : adj[u]) {
                s.push(i);
            }
        }
    }
}

void dfs_rec (vector<vector<int>> g, int u, vector <bool> visited) {
    visited[u] = true;
    for (int v : g[u]) {
        if (!visited[v]) {
            dfs_rec(g,v,visited);
        }
    }
}