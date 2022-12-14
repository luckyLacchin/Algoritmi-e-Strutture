#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

void ccdfs (vector<vector<int>> adj, int u, int *id, int &res) {
    if (id[u] == 0) {
        id[u] = 1; //non mi interessa calcolare le c.c. basta qualsiasi numero
    }
    for (int i = 0; i < adj[u].size(); i++) {
        if (id[adj[u][i]] == 0) {
            ++res;
            ccdfs (adj,adj[u][i],id,res);
        }
    }

}