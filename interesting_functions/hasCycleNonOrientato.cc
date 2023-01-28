#include <vector>

using namespace std;

bool hasCycleRec (vector<vector<int>> g, int u, int p,vector<bool> visited) {
    visited[u] = true;
    for (int v : g[u]) {
        if (v != p) {
            if (visited[v])
                return true;
            else if (hasCycleRec(g,v,u,visited))
                return true;
        }
    }
    return false;
}

bool hasCycle (vector<vector<int>> g) {

    vector<bool> visited;
    visited.resize(g.size(),false);
    for (int u = 0; u < g.size(); u++) {
        if (!visited[u])
            if (hasCycleRec(g,u,-1,visited))
                return true;
    }
    return false;
}