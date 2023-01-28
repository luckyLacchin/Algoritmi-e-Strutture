#include <stack>
#include <vector>

using namespace std;


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