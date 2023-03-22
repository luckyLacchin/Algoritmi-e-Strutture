#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

void ccdfs_rec (vector<vector<int>> adj, int u, int *id, int &res) {
    if (id[u] == 0) {
        id[u] = 1; //non mi interessa calcolare le c.c. basta qualsiasi numero
    }
    for (int i = 0; i < adj[u].size(); i++) {
        if (id[adj[u][i]] == 0) {
            ++res;
            ccdfs_rec (adj,adj[u][i],id,res);
        }
    }

}

void ccdfs_stack (vector<vector<int>> &g, int counter, int u, vector <int> &id) {
    
    stack <int> s;
    s.push(u);
    while (!s.empty()) {
        int t = s.top();
        s.pop();
        id[t] = counter;
        for (int v : g[t]) {
            if (id[v] == 0) {
                s.push(v);
            }
        }


    }
}