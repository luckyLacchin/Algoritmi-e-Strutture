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